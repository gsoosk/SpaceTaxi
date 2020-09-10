#ifndef RATE_H
#define RATE_H

#include <QWidget>

namespace Ui {
class Rate;
}

class Rate : public QWidget
{
    Q_OBJECT

public:
    explicit Rate(QWidget *parent = 0);
    ~Rate();

private slots:
    void on_B_10_clicked();

    void on_B_9_clicked();

    void on_B_8_clicked();

    void on_B_7_clicked();

    void on_B_6_clicked();

    void on_B_5_clicked();

    void on_B_4_clicked();

    void on_B_3_clicked();

    void on_B_2_clicked();

    void on_B_1_clicked();

    void on_CancelBtn_clicked();

    void on_RateBtn_clicked();

private:
    Ui::Rate *ui;
    int RateNum;
};

#endif // RATE_H
