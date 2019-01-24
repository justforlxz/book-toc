#include "circlepainter.h"

#include <QRect>

static const int Radius = 20;

void CirclePainter::paint(QPainter *painter, const QPoint &pos)
{
    QRect r(pos.x() - Radius, pos.y() - Radius, Radius * 2, Radius * 2);
    painter->drawRoundedRect(r, Radius, Radius);
}
