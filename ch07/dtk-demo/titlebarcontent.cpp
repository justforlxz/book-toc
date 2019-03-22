#include "titlebarcontent.h"

#include <QHBoxLayout>

TitlebarContent::TitlebarContent(QWidget *parent)
    : QFrame(parent),
      m_control(new DSegmentedControl)
{
    initUI();
    initConnections();
}

void TitlebarContent::initUI()
{
    QHBoxLayout *layout = new QHBoxLayout;

    m_control->addSegmented("garbage");
    m_control->addSegmented("big files");

    layout->addStretch();
    layout->addWidget(m_control);
    layout->addStretch();

    setLayout(layout);
}

void TitlebarContent::initConnections()
{
    connect(m_control, &DSegmentedControl::currentChanged, this, [this](int index) {
        if (index == 1) {
            emit bigFileSelected();
        } else {
            emit cacheSelected();
        }
    });
}
