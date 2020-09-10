#include "request.h"
#include "ui_request.h"
#include "panel.h"
#include <string>
#include "connection.h"
#include "Functions.h"
#include <QMessageBox>
#include <QString>
using namespace std;
Request::Request(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Request)
{
    ui->setupUi(this);
}

Request::~Request()
{
    delete ui;
}

void Request::on_CancelBtn_clicked()
{
    Panel *newPanel = new Panel;
    newPanel->show();
    this->hide();
}

void Request::on_RequestBtn_clicked()
{
    Connection newConnection ;
    bool VIP = ui->VipBox->isChecked();
    string Answer = newConnection.request(ui->SourcTxt->text().toUtf8().constData(), ui->DestinationTxt->toPlainText().toUtf8().constData() , VIP);
    string subAnswer = Answer;
    string TripCost = GetSubStrFromLine(subAnswer, ' ');
    string TripDistance = GetSubStrFromLine(subAnswer, '\n');
    if(subAnswer == "\nYou request a trip succesfully\n")
    {

        subAnswer = "Trip Cost: " + TripCost + "\nTrip Distance: " + TripDistance ;

        QMessageBox msg(this);
        msg.setText(QString::fromUtf8(subAnswer.c_str()));
        msg.exec();

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

void Request::on_DestinationTxt_textChanged()
{
    Connection newConnection ;
    bool VIP = ui->VipBox->isChecked();
    string Answer = newConnection.estimate(ui->SourcTxt->text().toUtf8().constData(), ui->DestinationTxt->toPlainText().toUtf8().constData() , VIP);
    string subAnswer = GetSubStrFromLine(Answer, '!');
    if(Answer == "")
    {
        string TripCost = GetSubStrFromLine(subAnswer, ' ');
        string TripDistance = GetSubStrFromLine(subAnswer, '\n');;
        ui->CostLabel->setText(QString::fromUtf8(TripCost.c_str()));
        ui->DistanceLabel->setText(QString::fromUtf8(TripDistance.c_str()));

    }


}

void Request::on_SourcTxt_textChanged(const QString &arg1)
{
    Connection newConnection ;
    bool VIP = ui->VipBox->isChecked();
    string Answer = newConnection.estimate(ui->SourcTxt->text().toUtf8().constData(), ui->DestinationTxt->toPlainText().toUtf8().constData() , VIP);
    string subAnswer = GetSubStrFromLine(Answer, '!');
    if(Answer == "")
    {
        string TripCost = GetSubStrFromLine(subAnswer, ' ');
        string TripDistance = GetSubStrFromLine(subAnswer, '\n');;
        ui->CostLabel->setText(QString::fromUtf8(TripCost.c_str()));
        ui->DistanceLabel->setText(QString::fromUtf8(TripDistance.c_str()));

    }
}

void Request::on_VipBox_pressed()
{

    Connection newConnection ;
    bool VIP = ui->VipBox->isChecked();
    string Answer = newConnection.estimate(ui->SourcTxt->text().toUtf8().constData(), ui->DestinationTxt->toPlainText().toUtf8().constData() , VIP);
    string subAnswer = GetSubStrFromLine(Answer, '!');
    if(Answer == "")
    {
        string TripCost = GetSubStrFromLine(subAnswer, ' ');
        string TripDistance = GetSubStrFromLine(subAnswer, '\n');;
        ui->CostLabel->setText(QString::fromUtf8(TripCost.c_str()));
        ui->DistanceLabel->setText(QString::fromUtf8(TripDistance.c_str()));

    }
}

void Request::on_VipBox_clicked()
{
    Connection newConnection ;
    bool VIP = ui->VipBox->isChecked();
    string Answer = newConnection.estimate(ui->SourcTxt->text().toUtf8().constData(), ui->DestinationTxt->toPlainText().toUtf8().constData() , VIP);
    string subAnswer = GetSubStrFromLine(Answer, '!');
    if(Answer == "")
    {
        string TripCost = GetSubStrFromLine(subAnswer, ' ');
        string TripDistance = GetSubStrFromLine(subAnswer, '\n');;
        ui->CostLabel->setText(QString::fromUtf8(TripCost.c_str()));
        ui->DistanceLabel->setText(QString::fromUtf8(TripDistance.c_str()));

    }
}
