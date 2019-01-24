#ifndef CIRCLEPAINTER_H
#define CIRCLEPAINTER_H

#include <QObject>

#include "interface.h"

class CirclePainter : public QObject, public PainterInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PainterInterface_iid FILE "circle.json")
    Q_INTERFACES(PainterInterface)

public:
    void paint(QPainter *painter, const QPoint &pos) Q_DECL_OVERRIDE;
};

#endif // CIRCLEPAINTER_H
