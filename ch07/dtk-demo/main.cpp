#include <DApplication>
#include <DWidgetUtil>

#include "mainwindow.h"
#include "controller.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("dtk application");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("Dtk Application");
    a.setApplicationDescription("This is a dtk template application.");

    Controller c;

    MainWindow w;
    w.setMinimumSize(500, 500);

    QObject::connect(&w, &MainWindow::requestScan, &c, &Controller::startScan);
    QObject::connect(&c, &Controller::fileScanned, &w, &MainWindow::showScannedFile);
    QObject::connect(&c, &Controller::scanProgressChanged, &w, &MainWindow::updateProgress);

    w.show();
    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
