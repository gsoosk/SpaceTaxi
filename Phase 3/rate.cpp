#include "rate.h"
#include "ui_rate.h"
#include <QPixmap>
#include <QPalette>
#include "panel.h"
#include "connection.h"
#include <string>
#include <QMessageBox>
using namespace std;
Rate::Rate(QWidget *parent) :
    QWidget(parent),RateNum(1),
    ui(new Ui::Rate)
{
    ui->setupUi(this);
    QPixmap pixmap(":/Rate/star1.png");
    QIcon ButtonIcon(pixmap);
    ui->B_1->setIcon(ButtonIcon);
    ui->B_2->setIcon(ButtonIcon);
    ui->B_3->setIcon(ButtonIcon);
    ui->B_4->setIcon(ButtonIcon);
    ui->B_5->setIcon(ButtonIcon);
    ui->B_6->setIcon(ButtonIcon);
    ui->B_7->setIcon(ButtonIcon);
    ui->B_8->setIcon(ButtonIcon);
    ui->B_9->setIcon(ButtonIcon);
    ui->B_10->setIcon(ButtonIcon);
}

Rate::~Rate()
{
    delete ui;
}

void Rate::on_B_10_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);
    ui->B_5->setIcon(ButtonIcon2);
    ui->B_6->setIcon(ButtonIcon2);
    ui->B_7->setIcon(ButtonIcon2);
    ui->B_8->setIcon(ButtonIcon2);
    ui->B_9->setIcon(ButtonIcon2);
    ui->B_10->setIcon(ButtonIcon2);
    RateNum = 10;

}

void Rate::on_B_9_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);
    ui->B_5->setIcon(ButtonIcon2);
    ui->B_6->setIcon(ButtonIcon2);
    ui->B_7->setIcon(ButtonIcon2);
    ui->B_8->setIcon(ButtonIcon2);
    ui->B_9->setIcon(ButtonIcon2);

    RateNum = 9;

}

void Rate::on_B_8_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);
    ui->B_5->setIcon(ButtonIcon2);
    ui->B_6->setIcon(ButtonIcon2);
    ui->B_7->setIcon(ButtonIcon2);
    ui->B_8->setIcon(ButtonIcon2);

    RateNum = 8;

}

void Rate::on_B_7_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);
    ui->B_5->setIcon(ButtonIcon2);
    ui->B_6->setIcon(ButtonIcon2);
    ui->B_7->setIcon(ButtonIcon2);

    RateNum = 7;

}

void Rate::on_B_6_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);
    ui->B_5->setIcon(ButtonIcon2);
    ui->B_6->setIcon(ButtonIcon2);

    RateNum = 6;

}

void Rate::on_B_5_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);
    ui->B_5->setIcon(ButtonIcon2);

    RateNum = 5;

}

void Rate::on_B_4_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);
    ui->B_4->setIcon(ButtonIcon2);

    RateNum = 4;

}

void Rate::on_B_3_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);
    ui->B_3->setIcon(ButtonIcon2);

    RateNum = 3;

}

void Rate::on_B_2_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);
    ui->B_2->setIcon(ButtonIcon2);

    RateNum = 2;

}

void Rate::on_B_1_clicked()
{
    QPixmap pixmap_star_1(":/Rate/star1.png");
    QPixmap pixmap_star_2(":/Rate/star2.png");
    QIcon ButtonIcon1(pixmap_star_1);
    QIcon ButtonIcon2(pixmap_star_2);
    ui->B_1->setIcon(ButtonIcon1);
    ui->B_2->setIcon(ButtonIcon1);
    ui->B_3->setIcon(ButtonIcon1);
    ui->B_4->setIcon(ButtonIcon1);
    ui->B_5->setIcon(ButtonIcon1);
    ui->B_6->setIcon(ButtonIcon1);
    ui->B_7->setIcon(ButtonIcon1);
    ui->B_8->setIcon(ButtonIcon1);
    ui->B_9->setIcon(ButtonIcon1);
    ui->B_10->setIcon(ButtonIcon1);

    ui->B_1->setIcon(ButtonIcon2);

    RateNum = 1;

}

void Rate::on_CancelBtn_clicked()
{
    Panel *PanelWin = new Panel();
    PanelWin->show();
    this->hide();
}

void Rate::on_RateBtn_clicked()
{
    Connection newConnection ;
    string Answer = newConnection.rate(RateNum);
    if(Answer == "You rate succesfully!\n")
    {
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
