#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <dsettingsdialog.h>

DWIDGET_USE_NAMESPACE

class SettingsDialog : public DSettingsDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = nullptr);

signals:
    void settingsChanged(const QString &key, const QVariant &value);
};

#endif // SETTINGSDIALOG_H
