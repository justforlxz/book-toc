#include "scanview.h"


ScanView::ScanView(QWidget *parent)
    : QFrame(parent),
      m_progress(new DWaterProgress),
      m_shiningText(new DLabel),
      m_startBtn(new DImageButton),
      m_stopBtn(new DPushButton),
      m_layout(new QStackedLayout)
{
    initUI();
    initConnections();
}

void ScanView::showFileName(const QString &filename)
{
    m_shiningText->setText(filename);
}

void ScanView::updateProgress(const qreal &progress)
{
    m_progress->setValue(progress * 100);
}

void ScanView::initUI()
{
    m_startBtn->setNormalPic(":/images/logo.svg");

    m_stopBtn->setText("stop");
    m_stopBtn->setFixedWidth(200);

    m_progress->setSizePolicy(QSizePolicy::Fixed,
                              QSizePolicy::Fixed);
    m_progress->start();

    m_shiningText->setText("hello");

    QWidget *startPage = new QWidget;
    QVBoxLayout *startLayout = new QVBoxLayout(startPage);
    startLayout->addStretch();
    startLayout->addWidget(m_startBtn);
    startLayout->addStretch();

    QWidget *scanningPage = new QWidget;
    QVBoxLayout *scanningLayout = new QVBoxLayout(scanningPage);
    scanningLayout->addStretch();
    scanningLayout->addWidget(m_progress);
    scanningLayout->setAlignment(m_progress, Qt::AlignHCenter);
    scanningLayout->addSpacing(40);
    scanningLayout->addWidget(m_shiningText);
    scanningLayout->addSpacing(10);
    scanningLayout->addWidget(m_stopBtn);
    scanningLayout->setAlignment(m_stopBtn, Qt::AlignHCenter);
    scanningLayout->addStretch();

    m_layout->addWidget(startPage);
    m_layout->addWidget(scanningPage);

    setLayout(m_layout);
}

void ScanView::initConnections()
{
    connect(m_startBtn, &DImageButton::clicked,
            this, &ScanView::startButtonClicked);
    connect(m_stopBtn, &DPushButton::clicked,
            this, &ScanView::stopButtonClicked);

    connect(m_startBtn, &DImageButton::clicked, this, [this] {
        m_layout->setCurrentIndex(1);
    });
    connect(m_stopBtn, &DPushButton::clicked, this, [this] {
        m_layout->setCurrentIndex(0);
    });
}
