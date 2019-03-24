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
    // 通知界面更新，显示大文件扫描结果
    void bigFileSelected();
    // 通知界面更新，显示缓存扫描结果
    void cacheSelected();

private:
    DSegmentedControl *m_control;

    void initUI();
    void initConnections();
};

#endif // TITLEBARCONTENT_H
