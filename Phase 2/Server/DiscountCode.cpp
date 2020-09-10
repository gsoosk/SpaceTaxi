#include "SpaceTaxi.h"
using namespace std;
DiscountCode :: DiscountCode(int ac, int dcc, int code)
: AvailableCount(ac), DiscountCodeCredit(dcc), Code(code) {};

int DiscountCode:: get_available_count()
{return AvailableCount;}

int DiscountCode:: get_discount_code_credit()
{
	return DiscountCodeCredit;
}

 int DiscountCode:: get_code()
 {
 	return Code;
 }

 DiscountCode& DiscountCode:: operator--()
 {
    AvailableCount--;
    return (*this);
 }