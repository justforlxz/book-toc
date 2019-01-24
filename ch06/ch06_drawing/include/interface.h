#ifndef INTERFACE_H
#define INTERFACE_H

#include <QPoint>
#include <QPainter>

class PainterInterface {

public:
    // 画笔的绘制函数，每个插件都需要有自己的实现
    virtual void paint(QPainter *painter, const QPoint &pos) = 0;
    virtual ~PainterInterface() = default;

};

// 接口ID，全局唯一
#define PainterInterface_iid "com.deepin.examples.ch06_drawing"

// 声明接口
Q_DECLARE_INTERFACE(PainterInterface, PainterInterface_iid)

#endif // INTERFACE_H
