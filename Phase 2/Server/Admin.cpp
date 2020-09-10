#include "SpaceTaxi.h"
using namespace std;
Admin:: Admin(Date RT,std::string user,std::string pass)
: Person(RT,user,pass){}

void Admin:: add_money(int Credit, Date SystemDate)
{
	SystemMoney newMoney(Credit, SystemDate);
	Money.push_back(newMoney);
}
int Admin:: get_credit_by_time(Date FirstDate, Date SecondDate)
{
	int SystemCredit=0;
	for(int i=0; i<Money.size(); i++)
	{
		if(Money[i].does_it_between_times(FirstDate,SecondDate))
		{
			SystemCredit += Money[i].get_money();
		}
	}
	return SystemCredit;
}