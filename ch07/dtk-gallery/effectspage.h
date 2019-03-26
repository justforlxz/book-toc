#ifndef EFFECTSPAGE_H
#define EFFECTSPAGE_H

#include <QFrame>

#include <dgraphicsclipeffect.h>
#include <dgraphicsgloweffect.h>
#include <dblureffectwidget.h>

DWIDGET_USE_NAMESPACE

class EffectsPage : public QFrame
{
    Q_OBJECT
public:
    explicit EffectsPage(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

private:
    DGraphicsClipEffect *m_clipEffect;
    DGraphicsGlowEffect *m_glowEffect;
    DBlurEffectWidget *m_blurInner;
    DBlurEffectWidget *m_blurBackground;

    QPixmap m_bg;

    void initUI();
    void initConnections();
};

#endif // EFFECTSPAGE_H
