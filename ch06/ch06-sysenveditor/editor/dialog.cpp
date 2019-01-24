#include "dialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include <QDBusReply>
#include <QDBusInterface>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    // 设置对话框大小
    setFixedWidth(300);

    // 搭建对话框内容控件
    QVBoxLayout *layout = new QVBoxLayout;

    m_key = new QLineEdit;
    m_key->setPlaceholderText("env");
    m_value = new QLineEdit;
    m_value->setPlaceholderText("value");
    QPushButton *btn = new QPushButton("Add");

    m_msg = new QLabel;
    m_msg->setWordWrap(true);

    layout->addWidget(m_key);
    layout->addWidget(m_value);
    layout->addWidget(m_msg);
    layout->addWidget(btn);

    setLayout(layout);

    connect(btn, &QPushButton::clicked, this, &Dialog::buttonClicked);
}

Dialog::~Dialog()
{

}

void Dialog::buttonClicked()
{
    if (m_key->text().isEmpty() || m_value->text().isEmpty())
        return;

    // 使用用户输入的数据作为参数，调用DBus方法
    QDBusInterface iface("com.deepin.examples.ch06.sysenvhelper",
                         "/com/deepin/examples/ch06/sysenvhelper",
                         "com.deepin.examples.ch06.SysEnvHelper",
                         QDBusConnection::systemBus());
    QDBusReply<bool> reply = iface.call("SetEnv", m_key->text(), m_value->text());

    // 在界面上反馈调用结果
    if (reply.isValid() && reply.value()) {
        m_msg->setText("success");
    } else {
        m_msg->setText("err: " + reply.error().message());
    }
}
