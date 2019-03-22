#include "cacheresultview.h"

#include <QVBoxLayout>

CacheResultView::CacheResultView(QWidget *parent)
    : QWidget(parent),
    m_resultLabel(new DLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addStretch();
    layout->addWidget(m_resultLabel);
    layout->setAlignment(m_resultLabel, Qt::AlignHCenter);
    layout->addStretch();

    setLayout(layout);
}

void CacheResultView::setResult(const ScanResult *result)
{
    const qreal size = result->garbageSize / 1024.0 / 1024.0;
    QString resultTxt = QString("grabage size: %1M").arg(size);
    m_resultLabel->setText(resultTxt);
}
