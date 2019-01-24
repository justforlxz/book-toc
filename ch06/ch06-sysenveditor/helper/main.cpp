#include <QCoreApplication>

#include <QDBusConnection>
#include <QDebug>

#include "sysenv.h"

// DBus服务名
#define Service "com.deepin.examples.ch06.sysenvhelper"
// DBus对象路径
#define Path "/com/deepin/examples/ch06/sysenvhelper"
// DBus接口
#define Interface "com.deepin.examples.ch06.SysEnvHelper"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SysEnv sysenv;

    QDBusConnection systemBus = QDBusConnection::systemBus();

    bool status;
    // 注册DBus服务
    status = systemBus.registerService(Service);
    if (!status) {
        qWarning() << "failed to register service" << systemBus.lastError().message();
        return -1;
    }
    // 将sysenv实例注册为DBus对象，并暴露实例所有的槽函数为DBus方法
    status = systemBus.registerObject(Path,
                                      Interface,
                                      &sysenv,
                                      QDBusConnection::ExportAllSlots);
    if (!status) {
        qWarning() << "failed to register object";
        return -2;
    }

    return a.exec();
}
