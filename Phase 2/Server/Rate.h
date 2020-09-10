#ifndef RATE_H
#define RATE_H
#include "SpaceTaxi.h"
class Rate{
public:
	Rate(int r,Date t);
	Date get_date();
	int get_num();
private:
	int RateNum;
	Date RateTime;

};
#endif