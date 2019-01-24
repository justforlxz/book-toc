#ifndef PAINTERPLUGIN_H
#define PAINTERPLUGIN_H

#include "interface.h"

class PainterPlugin
{
public:
    PainterPlugin() = default;
    PainterPlugin(PainterInterface *iface, QString name);
    ~PainterPlugin();

    PainterInterface *painter() const;
    QString name() const;

private:
    PainterInterface *m_iface;
    QString m_name;
};

#endif // PAINTERPLUGIN_H
