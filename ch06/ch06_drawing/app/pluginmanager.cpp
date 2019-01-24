#include "pluginmanager.h"

#include <QPluginLoader>

#include "interface.h"
#include "painterplugin.h"

QList<PainterPlugin *> PluginManager::painters()
{
    if (m_initialized)
        return m_painters;

    // 设置插件所在的目录
    QDir pluginsDir("../plugins/");

    // 遍历目录中的所有文件，尝试加载
    const QStringList files = pluginsDir.entryList(QDir::Files);
    for (const QString file : files)
    {
        // 过滤非动态库的内容
        if (!QLibrary::isLibrary(file)) {
            qWarning() << "file's not plugin type: " << file;
            continue;
        }

        // 使用QPluginLoader尝试将文件作为插件加载
        QPluginLoader loader(pluginsDir.absoluteFilePath(file));
        bool status = loader.load();
        if (!status) {
            qWarning() << "failed to load file as plugin: " << file;
            qWarning() << "error message: " << loader.errorString();
            continue;
        }

        // 尝试从加载成功的插件中获取到入口对象
        QObject *instance = loader.instance();
        if (!instance) {
            qWarning() << "failed to get object from plugin: " << file;
            continue;
        }

        // 将入口对象转换为我们所需的接口
        PainterInterface *painter = qobject_cast<PainterInterface*>(instance);
        if (!painter) {
            qWarning() << "failed to convert plugin to PaitnerInterface: " << file;
            instance->deleteLater();
            continue;
        }

        // 获取静态元数据
        const QJsonObject meta = loader.metaData().value("MetaData").toObject();
        const QString name = meta.value("Name").toString();

        // 构造封装类PainterPlugin的实例
        PainterPlugin *plugin = new PainterPlugin(painter, name);
        m_painters << plugin;
    }

    return m_painters;
}
