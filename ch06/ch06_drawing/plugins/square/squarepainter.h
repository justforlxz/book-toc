#ifndef SQUAREPAINTER_H
#define SQUAREPAINTER_H

#include <QObject>

#include "interface.h"

class SquarePainter : public QObject, public PainterInterface
{
    Q_OBJECT
    // 给插件添加静态元数据，这些数据在插件加载的过程中可以用作静态检查项
    Q_PLUGIN_METADATA(IID PainterInterface_iid FILE "square.json")
    // 声明实现的接口
    Q_INTERFACES(PainterInterface)

public:
    // 实现PainterInterface中的paint方法
    void paint(QPainter *painter, const QPoint &pos) Q_DECL_OVERRIDE;
};

#endif //SQUAREPAINTER_H
