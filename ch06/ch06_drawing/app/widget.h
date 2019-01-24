#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPaintEvent>
#include <QMouseEvent>

#include "painterplugin.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    PainterPlugin *painter() const;
    void setPainter(PainterPlugin *painter);

private:
    PainterPlugin *m_painter;
    QPoint m_clickPoint;
};

#endif // WIDGET_H
