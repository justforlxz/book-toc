#include "bigfileresultview.h"

#include <QVBoxLayout>

BigFileResultView::BigFileResultView(QWidget *parent)
    : QWidget(parent),
      m_1G(new DArrowLineExpand),
      m_500M(new DArrowLineExpand),
      m_1GFiles(new QListWidget),
      m_500MFiles(new QListWidget)
{
    m_1GFiles->setStyleSheet("margin: 10px");
    m_1GFiles->setFixedHeight(100);

    m_500MFiles->setStyleSheet("margin: 10px");
    m_500MFiles->setFixedHeight(100);

    m_1G->setTitle("Size over 1G");
    m_1G->setContent(m_1GFiles);

    m_500M->setTitle("Size over 500M");
    m_500M->setContent(m_500MFiles);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(10);

    layout->addWidget(m_1G);
    layout->addWidget(m_500M);
    layout->addStretch();

    setLayout(layout);
}

void BigFileResultView::setResult(const ScanResult *result)
{
    for (const QFileInfo &info : result->fileOver1G) {
        m_1GFiles->addItem(info.fileName());
    }

    for (const QFileInfo &info : result->fileOver500M) {
        m_500MFiles->addItem(info.fileName());
    }
}
