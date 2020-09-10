#ifndef DATE_H
#define DATE_H
#include "SpaceTaxi.h"
class Date
{
public:
	Date();
	Date(std:: string d);
	void set_date(int day, int hour, int minute, int second);
	int space_between(Date& AnotherDate);
	bool operator<(Date& AnotherDate);
	bool operator>(Date& AnotherDate);
	bool operator<=(Date& AnotherDate);
	bool operator>=(Date& AnotherDate);
	bool day_changed(int D);
private:
	int Day;
	int Hour;
	int Minute;
	int Second;
};
#endif