#ifndef CONTROLSPAGE_H
#define CONTROLSPAGE_H

#include <QWidget>

#include <dwaterprogress.h>
#include <dcircleprogress.h>
#include <dimagebutton.h>

#include <dlinkbutton.h>
#include <dpushbutton.h>
#include <dswitchbutton.h>

#include <dlineedit.h>
#include <dsearchedit.h>
#include <dpasswordedit.h>
#include <dipv4lineedit.h>

#include <darrowrectangle.h>
#include <dtoast.h>

DWIDGET_USE_NAMESPACE

class ControlsPage : public QWidget
{
    Q_OBJECT
public:
    explicit ControlsPage(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event);

private:
    DWaterProgress *m_waterProgress;
    DCircleProgress *m_circleProgress;
    DImageButton *m_catButton;

    DLinkButton *m_linkButton;
    DSwitchButton *m_switchButton;

    DLineEdit *m_lineEdit;
    DSearchEdit *m_searchEdit;
    DPasswordEdit *m_passwordEdit;
    DIpv4LineEdit *m_ipv4Edit;

    QLabel *m_message;
    DArrowRectangle *m_arrowRectangle;

    DToast *m_toast;

    void initUI();
    void initConnections();
};

#endif // CONTROLSPAGE_H
