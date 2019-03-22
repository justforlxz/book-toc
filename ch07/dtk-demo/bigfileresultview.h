#ifndef BIGFILERESULTVIEW_H
#define BIGFILERESULTVIEW_H

#include <QWidget>
#include <QListWidget>

#include <dlabel.h>
#include <darrowlineexpand.h>

#include "scanresult.h"

DWIDGET_USE_NAMESPACE

class BigFileResultView : public QWidget
{
    Q_OBJECT
public:
    explicit BigFileResultView(QWidget *parent = nullptr);

    void setResult(const ScanResult *result);

private:
    DArrowLineExpand *m_1G;
    DArrowLineExpand *m_500M;
    QListWidget *m_1GFiles;
    QListWidget *m_500MFiles;
};

#endif // BIGFILERESULTVIEW_H
