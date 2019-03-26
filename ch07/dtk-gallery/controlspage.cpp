#include "controlspage.h"

#include <QGridLayout>
#include <QProcess>

#include <dlabel.h>

ControlsPage::ControlsPage(QWidget *parent)
    : QWidget(parent),
      m_waterProgress(new DWaterProgress),
      m_circleProgress(new DCircleProgress),
      m_catButton(new DImageButton),

      m_linkButton(new DLinkButton),
      m_switchButton(new DSwitchButton),

      m_lineEdit(new DLineEdit),
      m_searchEdit(new DSearchEdit),
      m_passwordEdit(new DPasswordEdit),
      m_ipv4Edit(new DIpv4LineEdit),

      m_message(new QLabel("Hello DTK!")),
      m_arrowRectangle(new DArrowRectangle(DArrowRectangle::ArrowLeft,
                                           DArrowRectangle::FloatWidget)),

      m_toast(new DToast(this))

{
    initUI();
    initConnections();
}

void ControlsPage::showEvent(QShowEvent *event)
{
    // 移动DToast的位置到窗口中下方的位置并显示
    m_toast->move((width() - m_toast->width()) / 2.0,
                  height() - 10 - m_toast->height());
    m_toast->pop();

    QWidget::showEvent(event);
}

void ControlsPage::initUI()
{
    // 为DImageButton设置三种状态的图片资源
    m_catButton->setNormalPic(":/images/cat_normal.png");
    m_catButton->setHoverPic(":/images/cat_hover.png");
    m_catButton->setPressPic(":/images/cat_pressed.png");

    // 为DLinkButton设置文字内容
    m_linkButton->setText("Website Addr");

    // 启动DWaterProgress的水纹动画
    m_waterProgress->start();
    // 设置DCircleProgress的大小
    m_circleProgress->setFixedSize(100, 100);
    // 设置总量环形颜色为灰色
    m_circleProgress->setBackgroundColor(Qt::gray);
    // 设置当前进度部分颜色为浅蓝色
    m_circleProgress->setChunkColor(QColor("#B3D9FE"));

    // 统一设置
    m_lineEdit->setFixedWidth(120);
    m_searchEdit->setFixedWidth(120);
    m_passwordEdit->setFixedWidth(120);
    m_ipv4Edit->setFixedWidth(120);

    m_message->setFixedSize(200, 100);
    m_message->setAlignment(Qt::AlignCenter);
    m_arrowRectangle->setContent(m_message);

    // 设置DToast的提示信息内容
    m_toast->setText("Welcome back");

    // 构建界面内容布局
    QGridLayout *layout = new QGridLayout;
    layout->setSpacing(10);

    layout->addWidget(m_waterProgress, 0, 0, 3, 1, Qt::AlignCenter);
    layout->addWidget(m_circleProgress, 0, 1, 3, 1, Qt::AlignCenter);
    layout->addWidget(m_catButton, 4, 0, 2, 2, Qt::AlignCenter);

    layout->addWidget(m_linkButton, 3, 0, 1, 1, Qt::AlignCenter);
    layout->addWidget(m_switchButton, 3, 1, 1, 1, Qt::AlignCenter);

    layout->addWidget(new DLabel("DLineEdit:"), 0, 2, 1, 1, Qt::AlignRight);
    layout->addWidget(new DLabel("DSearchEdit:"), 1, 2, 1, 1, Qt::AlignRight);
    layout->addWidget(new DLabel("DPasswordEdit:"), 2, 2, 1, 1, Qt::AlignRight);
    layout->addWidget(new DLabel("DIpv4Edit:"), 3, 2, 1, 1, Qt::AlignRight);

    layout->addWidget(m_lineEdit, 0, 3, 1, 1, Qt::AlignLeft);
    layout->addWidget(m_searchEdit, 1, 3, 1, 1, Qt::AlignLeft);
    layout->addWidget(m_passwordEdit, 2, 3, 1, 1, Qt::AlignLeft);
    layout->addWidget(m_ipv4Edit, 3, 3, 1, 1, Qt::AlignLeft);

    layout->addWidget(m_arrowRectangle, 4, 2, 2, 2);

    // 竖直方向挤压内容，内容紧凑，而且会好看一点
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addStretch();
    vbox->addLayout(layout);
    vbox->addStretch();

    // 水平方向挤压内容，内容紧凑，而且会好看一点
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addLayout(vbox);
    hbox->addStretch();

    setLayout(hbox);
}

void ControlsPage::initConnections()
{
    // DSwitchButton打开的时候设置两个进度条的进度为50%，否则设置为0%
    connect(m_switchButton, &DSwitchButton::checkedChanged, this,
            [this] (bool checked)
    {
        int progress = checked ? 50 : 0;

        m_waterProgress->setValue(progress);
        m_circleProgress->setValue(progress);

        m_message->setText(QString("Progress set to %1%").arg(progress));
    });

    // DLinkButton点击的时候使用QProcess执行命令打开特定网址
    connect(m_linkButton, &DLinkButton::clicked, this,
            [this] ()
    {
        QProcess::startDetached("xdg-open https://www.deepin.org");

        m_message->setText("Link is open!");
    });

    // DImageButton点击的时候，在右侧的信息框中显示提示信息
    connect(m_catButton, &DImageButton::clicked, this,
            [this]()
    {
        m_message->setText("Meow~~~");
    });

    // DLineEdit编辑完成时，在右侧信息框中显示输入内容
    connect(m_lineEdit, &DLineEdit::editingFinished, this, [this] {
        if (m_lineEdit->text().length() != 0) {
            m_message->setText("Typed: " + m_lineEdit->text());
        } else {
            //警告用户输入不能为空
            m_lineEdit->setAlert(true);
            m_lineEdit->showAlertMessage("Can't be empty");
        }
    });

    // 用户重新编辑时，撤销警告状态
    connect(m_lineEdit, &DLineEdit::textChanged, this, [this] {
        m_lineEdit->setAlert(false);
    });

    // DLineEdit编辑完成时，在右侧信息框中显示输入内容
    connect(m_searchEdit, &DSearchEdit::editingFinished, this, [this] {
        m_message->setText("Searched: " + m_searchEdit->text());
    });

    // DPasswordEdit编辑完成时，在右侧信息框中显示输入内容
    connect(m_passwordEdit, &DPasswordEdit::editingFinished, this, [this] {
        m_message->setText("Guess what, I know your password: \n" + m_searchEdit->text());
    });

    // DIpv4LineEdit编辑完成时，在右侧信息框中显示输入内容
    connect(m_ipv4Edit, &DIpv4LineEdit::editingFinished, this, [this] {
        m_message->setText("I got IP address: " + m_ipv4Edit->text());
    });
}
