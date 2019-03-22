#include <DApplication>
#include <DWidgetUtil>

#include "mainwindow.h"
#include "controller.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    if (!a.setSingleInstance("dtk-demo"))
        return 0;

    // 使用QPixmap的高分屏缩放
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    // 使用浅色风格主题
    a.setTheme("light");
    // 设置组织名称
    a.setOrganizationName("deepin");
    // 设置程序名称
    a.setApplicationName("dtk application");
    // 设置程序版本号
    a.setApplicationVersion("1.0");
    // 设置程序产品图标
    a.setProductIcon(QIcon(":/images/logo.svg"));
    // 设置程序产品名称
    a.setProductName("Dtk Application");
    // 设置程序产品描述
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
