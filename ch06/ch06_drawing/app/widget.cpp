#include "widget.h"

#include "pluginmanager.h"

#include <QAction>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_painter(nullptr)
{
    // 设置窗口绘制和清理由程序自己完全负责，Qt无需自动处理
    // 这样做以后窗口背景默认变为黑色
    setAttribute(Qt::WA_OpaquePaintEvent);
    // 添加右键菜单
    setContextMenuPolicy(Qt::ActionsContextMenu);

    // 获取所有画笔插件，每个画笔作为一个菜单项加入到菜单中
    QList<PainterPlugin*> painters = PluginManagerInstance->painters();
    for (PainterPlugin *painter : painters) {
        QAction *action =  new QAction(painter->name());
        action->setCheckable(true);

        addAction(action);
        // 设置默认画笔
        if (!m_painter) {
            setPainter(painter);
        }

        connect(action, &QAction::triggered, this, [this, painter] {
            setPainter(painter);
        });
    }
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 设置反锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    // 设置画笔颜色为白色
    painter.setPen(Qt::white);

    // 在用户点击的位置，使用当前画笔绘图
    if (m_painter && m_clickPoint != QPoint(0, 0)) {
        m_painter->painter()->paint(&painter, m_clickPoint);
    }

    painter.end();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    // 在用户点击时记录点击位置
    if (event->button() == Qt::LeftButton) {
        m_clickPoint = event->pos();
        update();
    }

    QWidget::mousePressEvent(event);
}

PainterPlugin *Widget::painter() const
{
    return m_painter;
}

void Widget::setPainter(PainterPlugin *painter)
{
    m_painter = painter;

    // 菜单项的互斥效果实现
    for (QAction *action : actions()) {
        action->setChecked(action->text() == painter->name());
    }
}
