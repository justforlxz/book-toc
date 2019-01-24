#ifndef SYSENV_H
#define SYSENV_H

#include <QObject>
#include <QDBusContext>

class SysEnv : public QObject, protected QDBusContext
{
    Q_OBJECT
public:
    explicit SysEnv(QObject *parent = nullptr);

public slots:
    bool SetEnv(const QString &name, const QString &val);

private:
    bool doAuth();
};

#endif // SYSENV_H
