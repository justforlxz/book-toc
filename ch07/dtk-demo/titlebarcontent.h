#ifndef TITLEBARCONTENT_H
#define TITLEBARCONTENT_H

#include <QFrame>

#include <DSegmentedControl>

DWIDGET_USE_NAMESPACE

class TitlebarContent : public QFrame
{
    Q_OBJECT
public:
    explicit TitlebarContent(QWidget *parent = nullptr);

    DSegmentedControl *control() const;

private:
    DSegmentedControl *m_control;
};

#endif // TITLEBARCONTENT_H
