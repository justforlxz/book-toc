#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <dmainwindow.h>

#include "scanview.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    MainWindow();

public slots:
    void showScannedFile(const QString &file);
    void updateProgress(const qreal &progress);

signals:
    void requestScan();
    void requestStopScan();

private:
    ScanView *m_scanView;

    void initUI();
    void initConnections();
};

#endif // MAINWINDOW_H
