#ifndef CACHERESULTVIEW_H
#define CACHERESULTVIEW_H

#include <QWidget>

#include <dlabel.h>

#include "scanresult.h"

DWIDGET_USE_NAMESPACE

class CacheResultView : public QWidget
{
    Q_OBJECT
public:
    explicit CacheResultView(QWidget *parent = nullptr);

    void setResult(const ScanResult *result);

private:
    DLabel *m_resultLabel;
};

#endif // CACHERESULTVIEW_H
