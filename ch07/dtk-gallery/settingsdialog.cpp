#include "settingsdialog.h"

#include <QDir>

#include <dsettings.h>
#include <qsettingbackend.h>
#include <dstandardpaths.h>

DCORE_USE_NAMESPACE

SettingsDialog::SettingsDialog(QWidget *parent)
    : DSettingsDialog(parent)
{
    // 构造配置文件路径
    const QString confDir = DStandardPaths::writableLocation(
                QStandardPaths::AppConfigLocation);
    const QString confPath = confDir + QDir::separator() + "dtk-gallery.conf";

    // 创建设置项存储后端
    QSettingBackend *backend = new QSettingBackend(confPath);

    // 通过json文件创建DSettings对象
    DSettings *settings = DSettings::fromJsonFile(":/data/settings.json");
    // 设置DSettings存储后端
    settings->setBackend(backend);

    // 通过DSettings对象构建设置界面
    updateSettings(settings);

    connect(settings, &DSettings::valueChanged,
            this, &SettingsDialog::settingsChanged);
}
