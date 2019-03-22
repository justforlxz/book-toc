#include "mainwindow.h"

#include <dtitlebar.h>

#include "titlebarcontent.h"

#include <QDebug>

MainWindow::MainWindow() :
    DMainWindow(),
    m_scanView(new ScanView)
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
}

void MainWindow::initUI()
{
    TitlebarContent *content = new TitlebarContent;
    titlebar()->setCustomWidget(content, true);

    QFrame *mainWidget = new QFrame;
    QStackedLayout *layout = new QStackedLayout;

    layout->addWidget(m_scanView);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}

void MainWindow::initConnections()
{
    connect(m_scanView, &ScanView::startButtonClicked,
            this, &MainWindow::requestScan);
    connect(m_scanView, &ScanView::stopButtonClicked,
            this, &MainWindow::requestStopScan);
}
