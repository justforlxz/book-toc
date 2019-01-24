#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void buttonClicked();

private:
    QLabel *m_msg;
    QLineEdit *m_key;
    QLineEdit *m_value;
};

#endif // DIALOG_H
