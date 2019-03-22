#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "scanresult.h"

class Scanner;
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:
    void fileScanned(const QString &file);
    void scanProgressChanged(const qreal &progress);

public slots:
    void startScan();

private:
    friend class Scanner;
    QStringList m_cacheDirectories;
    ScanResult *m_result;
    qreal m_progress;
};

#endif // CONTROLLER_H
