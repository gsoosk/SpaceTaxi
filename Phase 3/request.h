#ifndef REQUEST_H
#define REQUEST_H

#include <QWidget>

namespace Ui {
class Request;
}

class Request : public QWidget
{
    Q_OBJECT

public:
    explicit Request(QWidget *parent = 0);
    ~Request();

private slots:
    void on_CancelBtn_clicked();

    void on_RequestBtn_clicked();

    void on_DestinationTxt_textChanged();

    void on_SourcTxt_textChanged(const QString &arg1);

    void on_VipBox_pressed();

    void on_VipBox_clicked();

private:
    Ui::Request *ui;
};

#endif // REQUEST_H
