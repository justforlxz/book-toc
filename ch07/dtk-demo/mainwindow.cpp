#include "mainwindow.h"

#include <dtitlebar.h>

#include "titlebarcontent.h"
#include "controller.h"

#include <QDebug>

MainWindow::MainWindow() :
    DMainWindow(),
    m_layout(new QStackedLayout),
    m_titlebarContent(new TitlebarContent),
    m_scanView(new ScanView),
    m_cacheResult(new CacheResultView),
    m_bigFileResult(new BigFileResultView)
{
    initUI();
    initConnections();
}

void MainWindow::showScannedFile(const QString &file)
{
    m_scanView->showFileName(file);
}

void MainWindow::updateProgress(const qreal &progress)
{
    m_scanView->updateProgress(progress);

    Controller *controller = qobject_cast<Controller*>(sender());

    // 扫描完成
    if (progress == 1.0) {
        m_bigFileResult->setResult(controller->result());
        m_cacheResult->setResult(controller->result());

        showCacheResult();
    }
}

void MainWindow::showCacheResult()
{
    m_layout->setCurrentIndex(1);
}

void MainWindow::showBigFileResult()
{
     m_layout->setCurrentIndex(2);
}

void MainWindow::initUI()
{
    titlebar()->setCustomWidget(m_titlebarContent, true);

    QFrame *mainWidget = new QFrame;

    m_layout->addWidget(m_scanView);
    m_layout->addWidget(m_cacheResult);
    m_layout->addWidget(m_bigFileResult);

    mainWidget->setLayout(m_layout);
    setCentralWidget(mainWidget);
}

void MainWindow::initConnections()
{
    connect(m_scanView, &ScanView::startButtonClicked,
            this, &MainWindow::requestScan);
    connect(m_scanView, &ScanView::stopButtonClicked,
            this, &MainWindow::requestStopScan);

    connect(m_titlebarContent, &TitlebarContent::bigFileSelected,
            this, &MainWindow::showBigFileResult);
    connect(m_titlebarContent, &TitlebarContent::cacheSelected,
            this, &MainWindow::showCacheResult);
}
