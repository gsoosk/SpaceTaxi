#include "Register.h"
#include "ui_register.h"
#include "connection.h"
#include <string>
#include <QMessageBox>
#include <login.h>
using namespace std;
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_RegisterBtn_clicked()
{
    Connection newConnection ;
    string Answer = newConnection.register_user(ui->UserTxt->text().toUtf8().constData(), ui->PassTxt->text().toUtf8().constData()
                                ,ui->PhoneTxt->text().toUtf8().constData(), ui->CodeTxt->text().toUtf8().constData());
    if(Answer == "You registered succesfully!\n" || Answer == "You registered with discount code succesfully!\n" )
    {
        Login *newLoginWin = new Login();
        newLoginWin->show();
        this->hide();
    }
    else
    {
        QMessageBox msg(this);
        msg.setText(QString::fromUtf8(Answer.c_str()));
        msg.exec();

    }

}
