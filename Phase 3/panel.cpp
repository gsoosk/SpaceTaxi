#include "panel.h"
#include "ui_panel.h"
#include "connection.h"
#include <string>
#include "login.h"
#include "charge_account.h"
#include "rate.h"
#include "Functions.h"
#include <QMessageBox>
#include "estimate.h"
#include "request.h"
using namespace std;
Panel::Panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel)
{
    ui->setupUi(this);
    Connection newConnection;
    ui->UserLable->setText(QString::fromUtf8(newConnection.PassengerUsername.c_str()));
    string DateStr = newConnection.get_date();
    ui->DateLable->setText(QString::fromUtf8(DateStr.c_str()));
    string CreditStr = newConnection.get_credit();
    ui->CreditLable->setText(QString::fromUtf8(CreditStr.c_str()));
    string TripStr = newConnection.trip_status();
    ui->TripStatus->setText(QString::fromUtf8(TripStr.c_str()));

   // newConnection.PassengerUsername
}

Panel::~Panel()
{
    delete ui;
}

void Panel::on_pushButton_clicked()
{
    Connection newConnection;
    newConnection.logout();
    Login *LoginWin = new Login();
    LoginWin->show();
    this->hide();
}


void Panel::on_ChargeBtn_clicked()
{
    ChargeAccount *ChargeWin = new ChargeAccount();
    ChargeWin->show();
    this->hide();
}

void Panel::on_RateBtn_clicked()
{
    Rate *RateWin = new Rate();
    RateWin->show();
    this->hide();
}

void Panel::on_CodeBtn_clicked()
{
    Connection newConnection;
    string Answer = newConnection.get_discount();
    string DCode = GetSubStrFromLine(Answer, ' ');
    string ACount = GetSubStrFromLine(Answer, '\n');
    Answer = "Discount Code : " + DCode + "\nAvailable Count : " + ACount;
    QMessageBox msg(this);
    msg.setText(QString::fromUtf8(Answer.c_str()));
    msg.exec();
}



void Panel::on_RequestBtn_clicked()
{
    Request *RequestWin = new Request();
    RequestWin->show();
    this->hide();
}

void Panel::on_CancelTrip_clicked()
{
    Connection newConnection;
    string Answer = newConnection.cancel_trip();

    QMessageBox msg(this);
    msg.setText(QString::fromUtf8(Answer.c_str()));
    msg.exec();
    this->hide();
    Panel *newPanel = new Panel();
    newPanel->show();

}

void Panel::on_UpdateStatusBtn_clicked()
{
    Panel* newPanel = new Panel();
    newPanel->show();
    this->hide();
}
