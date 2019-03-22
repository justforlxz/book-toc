#ifndef SCANVIEW_H
#define SCANVIEW_H

#include <QFrame>
#include <QStackedLayout>

#include <dwaterprogress.h>
#include <dimagebutton.h>
#include <dlabel.h>
#include <dpushbutton.h>

DWIDGET_USE_NAMESPACE

class ScanView : public QFrame
{
    Q_OBJECT
public:
    explicit ScanView(QWidget *parent = nullptr);

    void showFileName(const QString &filename);
    void updateProgress(const qreal &progress);

signals:
    void startButtonClicked();
    void stopButtonClicked();

private:
    DWaterProgress *m_progress;
    DLabel *m_shiningText;
    DImageButton *m_startBtn;
    DPushButton *m_stopBtn;
    QStackedLayout *m_layout;

    void initUI();
    void initConnections();
};

#endif // SCANVIEW_H
