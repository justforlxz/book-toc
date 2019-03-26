#include "effectspage.h"

#include <QGridLayout>
#include <QLabel>

EffectsPage::EffectsPage(QWidget *parent)
    : QFrame(parent),
      m_clipEffect(new DGraphicsClipEffect),
      m_glowEffect(new DGraphicsGlowEffect),
      m_blurInner(new DBlurEffectWidget),
      m_blurBackground(new DBlurEffectWidget)
{
    initUI();
    initConnections();
}

void EffectsPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (m_bg.isNull()) {
        QPixmap pix(":/images/effects-bg.jpg");
        m_bg = pix.scaled(rect().size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
    painter.drawPixmap(0, 0, m_bg);

    painter.end();

    QFrame::paintEvent(event);
}

void EffectsPage::initUI()
{
    // DBlurEffectWidget窗口内混合模式
    m_blurInner->setFixedSize(140, 140);
    m_blurInner->setBlendMode(DBlurEffectWidget::InWindowBlend);
    // 设置模糊半径
    m_blurInner->setRadius(30);

    // DBlurEffectWidget窗口背景混合模式
    m_blurBackground->setFixedSize(140, 140);
    m_blurBackground->setBlendMode(DBlurEffectWidget::BehindWindowBlend);
    // 设置遮罩层颜色为暗色
    m_blurBackground->setMaskColor(DBlurEffectWidget::DarkColor);
    // 设置控件X和Y方向的圆角半径
    m_blurBackground->setBlurRectXRadius(70);
    m_blurBackground->setBlurRectYRadius(70);

    // 创建切割路径
    QPainterPath path;
    path.moveTo(0, 0);
    path.lineTo(0, 140);
    path.lineTo(140, 140);
    path.closeSubpath();
    // 设置切割路径
    m_clipEffect->setClipPath(path);

    // 设置外发光X轴的偏移量
    m_glowEffect->setXOffset(10);
    // 设置外放光Y轴的偏移量
    m_glowEffect->setYOffset(10);

    QFrame *cliped = new QFrame;
    cliped->setStyleSheet("background: grey");
    cliped->setFixedSize(140, 140);
    cliped->setGraphicsEffect(m_clipEffect);

    QFrame *glowing = new QFrame;
    glowing->setStyleSheet("background: grey");
    glowing->setFixedSize(140, 140);
    glowing->setGraphicsEffect(m_glowEffect);

    QGridLayout *layout = new QGridLayout;
    layout->setSpacing(10);

    layout->addWidget(m_blurInner, 0, 0, 1, 1);
    layout->addWidget(m_blurBackground, 0, 1, 1, 1);
    layout->addWidget(cliped, 1, 0, 1, 1);
    layout->addWidget(glowing, 1, 1, 1, 1);

    // 竖直方向挤压内容，内容紧凑，而且会好看一点
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addStretch();
    vbox->addLayout(layout);
    vbox->addStretch();

    // 水平方向挤压内容，内容紧凑，而且会好看一点
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addLayout(vbox);
    hbox->addStretch();

    setLayout(hbox);
}

void EffectsPage::initConnections()
{

}
