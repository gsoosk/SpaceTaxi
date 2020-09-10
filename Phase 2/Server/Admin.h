#ifndef ADMIN_H
#define ADMIN_H
#include "SpaceTaxi.h"
class Admin : public Person{

public:
	Admin(Date RT,std::string user,std::string pass);
	void add_money(int Credit, Date SystemDate);
	int get_credit_by_time(Date FirstDate, Date SecondDate);
	
private:
	std:: vector<SystemMoney> Money;
};
#endif