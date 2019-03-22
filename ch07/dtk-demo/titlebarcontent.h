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

signals:
    void bigFileSelected();
    void cacheSelected();

private:
    DSegmentedControl *m_control;

    void initUI();
    void initConnections();
};

#endif // TITLEBARCONTENT_H
