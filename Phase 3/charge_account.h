#ifndef CHARGE_ACCOUNT_H
#define CHARGE_ACCOUNT_H

#include <QWidget>

namespace Ui {
class ChargeAccount;
}

class ChargeAccount : public QWidget
{
    Q_OBJECT

public:
    explicit ChargeAccount(QWidget *parent = 0);
    ~ChargeAccount();

private slots:
    void on_pushButton_clicked();

    void on_CancelBtn_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChargeAccount *ui;
};

#endif // CHARGE_ACCOUNT_H
