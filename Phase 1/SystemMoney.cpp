#include "SpaceTaxi.h"
using namespace std;
SystemMoney :: SystemMoney(int M, Date MT)
{
	Money = M;
	MoneyTime = MT;
}
bool SystemMoney:: does_it_between_times(Date FirstDate, Date SecondDate)
{
	if(MoneyTime >= FirstDate && MoneyTime <= SecondDate)
		return true;
	return false;
}
int SystemMoney:: get_money()
{
	return Money;
}