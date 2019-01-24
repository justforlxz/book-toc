#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtCore>

#include "painterplugin.h"

class PluginManager
{
public:
    QList<PainterPlugin*> painters();

private:
    bool m_initialized = false;
    QList<PainterPlugin*> m_painters;
};

Q_GLOBAL_STATIC(PluginManager, PluginManagerInstance)

#endif // PLUGINMANAGER_H
