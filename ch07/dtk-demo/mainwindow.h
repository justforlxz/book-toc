#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <dmainwindow.h>

#include <QStackedLayout>

#include "scanview.h"
#include "cacheresultview.h"
#include "bigfileresultview.h"
#include "titlebarcontent.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void showScannedFile(const QString &file);
    void updateProgress(const qreal &progress);

    void showCacheResult();
    void showBigFileResult();

signals:
    void requestScan();
    void requestStopScan();

private:
    QStackedLayout *m_layout;
    TitlebarContent *m_titlebarContent;
    ScanView *m_scanView;
    CacheResultView *m_cacheResult;
    BigFileResultView *m_bigFileResult;

    void initUI();
    void initConnections();
};

#endif // MAINWINDOW_H
