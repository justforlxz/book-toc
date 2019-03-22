#ifndef SCANRESULT_H
#define SCANRESULT_H

#include <QFileInfoList>

struct ScanResult
{
    QFileInfoList fileOver1G;
    QFileInfoList fileOver500M;

    qint64 garbageSize;
};

#endif // SCANRESULT_H
