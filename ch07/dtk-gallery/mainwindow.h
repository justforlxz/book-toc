#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QStackedLayout>

#include <dsegmentedcontrol.h>

#include "controlspage.h"
#include "effectspage.h"

#include "settingsdialog.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();

private:
    DSegmentedControl *m_seg;

    QStackedLayout *m_layout;

    ControlsPage *m_controlsPage;
    EffectsPage *m_effectsPage;

    QPushButton *m_darkMode;
    QPushButton *m_lightMode;

    SettingsDialog *m_settingsDialog;

    void initUI();
    void initConnections();

    QMenu* createSettingsMenu();
};

#endif // MAINWINDOW_H
