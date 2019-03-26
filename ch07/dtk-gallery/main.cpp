#include <DApplication>
#include <DWidgetUtil>
#include <daboutdialog.h>
#include <DLog>

#include <QDebug>

#include "mainwindow.h"

DCORE_USE_NAMESPACE
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    if (!a.setSingleInstance("dtk-gallery"))
        return 0;

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setTheme("light");

    // 设置组织名称
    a.setOrganizationName("deepin");
    // 设置应用名称
    a.setApplicationName("dtk-gallery");
    // 设置应用版本号
    a.setApplicationVersion("0.1");
    // 设置应用图标
    a.setProductIcon(QIcon(":/images/logo.svg"));
    // 设置应用产品名称
    a.setProductName("DTK Widgets Gallery");
    // 设置应用描述信息
    a.setApplicationDescription("DTK widgets gallery is an demo application to "
                                "demonstrate how DTK works.");
    // 不显示鸣谢链接
    a.setApplicationAcknowledgementVisible(false);
    // 设置程序授权
    a.setApplicationLicense("GPLv3");

    // 设置终端日志和日志文件处理
    DLogManager::registerConsoleAppender();
    DLogManager::registerFileAppender();

    qDebug() << "hello dtk logging";

    MainWindow w;
    w.setMinimumSize(600, 500);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
