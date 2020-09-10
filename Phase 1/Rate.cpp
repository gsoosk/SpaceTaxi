#include "SpaceTaxi.h"
using namespace std;
Rate:: Rate (int r, Date t)
{
	RateNum = r;
	RateTime = t;
}
Date Rate:: get_date ()
{
	return RateTime;
}
int Rate:: get_num()
{
	return RateNum;
}