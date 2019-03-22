#include "titlebarcontent.h"

#include <QHBoxLayout>

TitlebarContent::TitlebarContent(QWidget *parent)
    : QFrame(parent),
      m_control(new DSegmentedControl)
{
    QHBoxLayout *layout = new QHBoxLayout;

    m_control->addSegmented("big file");
    m_control->addSegmented("rabbish");

    layout->addStretch();
    layout->addWidget(m_control);
    layout->addStretch();

    setLayout(layout);
}

DSegmentedControl *TitlebarContent::control() const
{
    return m_control;
}
