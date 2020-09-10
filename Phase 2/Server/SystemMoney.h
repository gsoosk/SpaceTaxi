#ifndef SYSTEM_MONEY_H
#define SYSTEM_MONEY_H
#include "SpaceTaxi.h"
class SystemMoney
{
public:
	SystemMoney(int M, Date MT);
	bool does_it_between_times(Date FirstDate, Date SecondDate);
	int get_money();

private:
	int Money;
	Date MoneyTime;
	
};
#endif