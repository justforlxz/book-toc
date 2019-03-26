#include "mainwindow.h"

#include <QFrame>
#include <QDebug>

#include <QApplication>

#include <dapplication.h>
#include <dtitlebar.h>
#include <dseparatorhorizontal.h>

MainWindow::MainWindow()
    : DMainWindow(),
      m_layout(new QStackedLayout),
      m_controlsPage(new ControlsPage),
      m_effectsPage(new EffectsPage),
      m_darkMode(new QPushButton("Dark")),
      m_lightMode(new QPushButton("Light")),
      m_settingsDialog(new SettingsDialog)
{
    // 构建主窗口界面内容
    initUI();
    // 初始化信号槽连接
    initConnections();
}

void MainWindow::initUI()
{
    m_seg = new DSegmentedControl;

    // 为DSegmentedControl中添加选项
    m_seg->addSegmented("Controls");
    m_seg->addSegmented("Effects");

    // 在标题栏中显示DSegmentedControl控件
    titlebar()->setCustomWidget(m_seg, true);

    // 给标题栏添加设置菜单
    QMenu *settingsMenu = createSettingsMenu();
    titlebar()->setMenu(settingsMenu);

    m_layout->addWidget(m_controlsPage);
    m_layout->addWidget(m_effectsPage);

    // 添加底部栏
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->setSpacing(0);
    bottomLayout->setMargin(0);
    bottomLayout->addWidget(m_darkMode);
    bottomLayout->addSpacing(10);
    bottomLayout->addWidget(m_lightMode);
    bottomLayout->addStretch();

    QWidget *bottomBar = new QWidget;
    bottomBar->setFixedHeight(40);
    bottomBar->setLayout(bottomLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(m_layout);
    mainLayout->addWidget(new DSeparatorHorizontal());
    mainLayout->addWidget(bottomBar);

    // 设置主窗口内容
    QFrame *content = new QFrame;
    content->setLayout(mainLayout);

    setCentralWidget(content);
}

void MainWindow::initConnections()
{
    connect(m_seg, &DSegmentedControl::currentChanged, this, [this] (int index) {
        m_layout->setCurrentIndex(index);
    });

    connect(m_darkMode, &QPushButton::clicked, this, [this] () {
        DApplication *app = qobject_cast<DApplication*>(qApp);
        if (app) {
            app->setTheme("dark");
        }
    });

    connect(m_lightMode, &QPushButton::clicked, this, [this]() {
        DApplication *app = qobject_cast<DApplication*>(qApp);
        if (app) {
            app->setTheme("light");
        }
    });

    connect(m_settingsDialog, &SettingsDialog::settingsChanged, this,
            [this] (const QString &key, const QVariant &value)
    {
        qDebug() << key << value;
    });
}

QMenu* MainWindow::createSettingsMenu()
{
    QMenu *menu = new QMenu;

    QAction *settingsAction = menu->addAction("Settings");
    connect(settingsAction, &QAction::triggered, this, [this] {
        m_settingsDialog->show();
    });

    return menu;
}
