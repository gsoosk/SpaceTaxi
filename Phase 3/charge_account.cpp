#include "charge_account.h"
#include "ui_chargeaccount.h"
#include "connection.h"
#include <string>
#include <QMessageBox>
#include <panel.h>
using namespace std;
ChargeAccount::ChargeAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeAccount)
{
    ui->setupUi(this);
}

ChargeAccount::~ChargeAccount()
{
    delete ui;
}

void ChargeAccount::on_pushButton_clicked()
{
    Connection newConnection;
    string Answer = newConnection.charge_account(ui->AmountCode->text().toUtf8().constData());
    if(Answer == "You charge your account succesfully!\n")
    {
        Panel *PanelWin = new Panel();
        PanelWin->show();
        this->hide();
    }else
    {
        QMessageBox msg(this);
        msg.setText(QString::fromUtf8(Answer.c_str()));
        msg.exec();
    }
}

void ChargeAccount::on_CancelBtn_clicked()
{
    Panel *PanelWin = new Panel();
    PanelWin->show();
    this->hide();
}

void ChargeAccount::on_pushButton_2_clicked()
{

}
