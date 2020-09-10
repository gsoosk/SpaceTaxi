#include "estimate.h"
#include "ui_estimate.h"
#include "panel.h"
#include <string>
#include "connection.h"
#include "Functions.h"
#include <QMessageBox>
using namespace std;
Estimate::Estimate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Estimate)
{
    ui->setupUi(this);
}

Estimate::~Estimate()
{
    delete ui;
}

void Estimate::on_CancelBtn_clicked()
{
    Panel *newPanel = new Panel;
    newPanel->show();
    this->hide();
}

void Estimate::on_EstimateBtn_clicked()
{
    Connection newConnection ;
    bool VIP = ui->VipBox->isChecked();
    string Answer = newConnection.estimate(ui->SourcTxt->text().toUtf8().constData(), ui->DestinationTxt->toPlainText().toUtf8().constData() , VIP);
    string subAnswer = GetSubStrFromLine(Answer, '!');
    if(Answer == "")
    {
        string TripCost = GetSubStrFromLine(subAnswer, ' ');
        string TripDistance = subAnswer;
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
        Answer = subAnswer + Answer ;
        QMessageBox msg(this);
        msg.setText(QString::fromUtf8(Answer.c_str()));
        msg.exec();
    }

}
