#include "painterplugin.h"

PainterPlugin::PainterPlugin(PainterInterface *iface, QString name):
    m_iface(iface),
    m_name(name)
{

}

PainterPlugin::~PainterPlugin()
{
    if (m_iface)
        delete m_iface;
}

PainterInterface *PainterPlugin::painter() const
{
    return m_iface;
}

QString PainterPlugin::name() const
{
    return m_name;
}
