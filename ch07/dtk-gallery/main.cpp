#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <QPixmap>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    if (!a.setSingleInstance("dtk-gallery"))
        return 0;

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setTheme("light");

//    QIcon(":/images/deepin-logo.svg").pixmap(QSize(48, 48)).save("/tmp/test.png");
    QPixmap(":/images/deepin-logo.svg").save("/tmp/test.png");

    // 设置组织名称
    a.setOrganizationName("deepin");
    // 设置应用名称
    a.setApplicationName("dtk-gallery");
    // 设置应用版本号
    a.setApplicationVersion("0.1");
    // 设置应用图标
    a.setProductIcon(QIcon(":/images/deepin-logo.svg"));
    // 设置应用产品名称
    a.setProductName("DTK Widgets Gallery");
    // 设置应用描述信息
    a.setApplicationDescription("DTK widgets gallery is an demo application to "
                                "demonstrate how DTK works.");
    // 设置程序官网链接
    a.setApplicationHomePage("https://github.com/linuxdeepin/dtkwidget");
    // 不显示鸣谢链接
    a.setApplicationAcknowledgementVisible(false);

    DMainWindow w;
    w.setMinimumSize(500, 500);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
