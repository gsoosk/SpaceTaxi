#ifndef ESTIMATE_H
#define ESTIMATE_H

#include <QWidget>

namespace Ui {
class Estimate;
}

class Estimate : public QWidget
{
    Q_OBJECT

public:
    explicit Estimate(QWidget *parent = 0);
    ~Estimate();

private slots:
    void on_CancelBtn_clicked();

    void on_EstimateBtn_clicked();

private:
    Ui::Estimate *ui;
};

#endif // ESTIMATE_H
