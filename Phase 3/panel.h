#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

namespace Ui {
class Panel;
}

class Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = 0);
    ~Panel();

private slots:
    void on_pushButton_clicked();



    void on_ChargeBtn_clicked();

    void on_RateBtn_clicked();

    void on_CodeBtn_clicked();

    void on_RequestBtn_clicked();

    void on_CancelTrip_clicked();

    void on_UpdateStatusBtn_clicked();

private:
    Ui::Panel *ui;
};

#endif // PANEL_H
