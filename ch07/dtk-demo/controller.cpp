#include "controller.h"

#include <QDir>
#include <QThread>
#include <QDebug>

class Scanner : public QObject {
public:
    Scanner(Controller *controller)
        :QObject(),
          m_controller(controller)
    {

    }

    void doScan() {
        // 清空结果和进度
        *m_controller->m_result = ScanResult{};
        m_controller->m_progress = 0;

        // 扫描缓存
        for (const QString &dir : m_controller->m_cacheDirectories) {
            doScanDir(dir, true);
        }

        emit m_controller->scanProgressChanged(0.5);

        // 扫描大文件
        QDir dir(QDir::home());
        dir.setFilter(QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Dirs);

        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i) {
            doScanDir(list.at(i).filePath());
        }

        emit m_controller->scanProgressChanged(1.0);
    }

private:
    Controller *m_controller;

    void handleCacheFile(const QFileInfo &info) {
        m_controller->m_result->garbageSize += info.size();
    }

    void filterBigFile(const QFileInfo &info) {
        if (info.size() >= 1024 * 1024 * 1024) {
            m_controller->m_result->fileOver1G << info.fileName();
        } else if (info.size() >= 1024 * 1024 * 500) {
            m_controller->m_result->fileOver500M << info.fileName();
        }
    }

    void doScanDir(const QString &path, bool cache = false) {
        QDir dir(path);
        dir.setFilter(QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Files | QDir::Dirs);

        const qreal maxProgress = cache ? 0.4 : 0.9;

        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if (fileInfo.isFile()) {
                if (cache)
                    handleCacheFile(fileInfo);
                else
                    filterBigFile(fileInfo);
                emit m_controller->fileScanned(fileInfo.absoluteFilePath());
                emit m_controller->scanProgressChanged(
                            qMin(m_controller->m_progress += 0.000001, maxProgress));
            } else if (fileInfo.isDir()) {
                doScanDir(fileInfo.absoluteFilePath(), cache);
            }
        }
    }
};

Controller::Controller(QObject *parent)
    : QObject(parent),
      m_result(new ScanResult)
{
    m_cacheDirectories << QDir::home().absoluteFilePath(".cache");
}

void Controller::startScan()
{
    QThread *thread = new QThread;

    Scanner *scanner = new Scanner(this);
    scanner->moveToThread(thread);

    connect(thread, &QThread::finished, scanner, &Scanner::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(thread, &QThread::started, scanner, &Scanner::doScan);

    thread->start();
}
