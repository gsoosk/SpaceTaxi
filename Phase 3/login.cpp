#include "login.h"
#include "ui_login.h"
#include "connection.h"
#include <QMessageBox>
#include <string>
#include <QString>
#include "Register.h"
#include "panel.h"
using namespace std;
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginBtn_clicked()
{
    Connection newConnection ;
    string Answer = newConnection.LoginUser(ui->UserTxt->text().toUtf8().constData(), ui->PassTxt->text().toUtf8().constData());
    if(Answer == "You loged in succesfully!\n")
    {
        newConnection.LoginStatus = true;
        newConnection.PassengerUsername = ui->UserTxt->text().toUtf8().constData() ;
        Panel *PanelWin = new Panel();
        PanelWin->show();
        this->hide();

    }
    else
    {
        QMessageBox msg(this);
        msg.setText(QString::fromUtf8(Answer.c_str()));
        msg.exec();
    }
}

void Login::on_RegisterBtn_clicked()
{
    Register *RegisterWin = new Register();
    RegisterWin->show();
    this->hide();

}
