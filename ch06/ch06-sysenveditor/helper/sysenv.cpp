#include "sysenv.h"

#include <QDebug>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusConnectionInterface>

#include <PolkitQt1/Authority>

using namespace PolkitQt1;

SysEnv::SysEnv(QObject *parent)
    : QObject(parent),
      QDBusContext()
{
}

bool SysEnv::SetEnv(const QString &name, const QString &val)
{
    // 检查输入是否合法
    if (name.isEmpty())
        return false;

    // 检查函数是否在DBus调用的上下文中
    if (!calledFromDBus())
        return false;

    // 验证用户权限
    if (!doAuth())
        return false;

    // 写入内容到/etc/environment中，这里使用system函数调用系统命令完成
    QString cmd = QString("echo %1=%2 >> /etc/environment").arg(name).arg(val);
    int ret = system(cmd.toUtf8());

    return ret == 0;
}

bool SysEnv::doAuth()
{
    // 获取DBus调用者的PID
    const QDBusMessage msg = message();
    const QString service = msg.service();
    const qint64 pid = connection().interface()->servicePid(service);

    // 构造Subject实例
    UnixProcessSubject sub(pid);
    // 构造Authority实例
    Authority *auth = Authority::instance();
    // 做权限鉴定
    Authority::Result result = auth->checkAuthorizationSync(
                "com.deepin.examples.ch06.setsysenv",
                sub,
                PolkitQt1::Authority::AllowUserInteraction);

    if (result != Authority::Yes) {
        qWarning() << "authorization failed: " << auth->errorDetails();
    }

    return result == Authority::Yes;
}
