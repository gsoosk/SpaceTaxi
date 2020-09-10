#ifndef DISCOUNT_CODE_H
#define DISCOUNT_CODE_H
#include "SpaceTaxi.h"
#define DISCOUNT_CODE_CREDIT 10
#define DISCOUNT_CODE_COUNT 5
class DiscountCode {
public:
  DiscountCode(int ac, int dcc, int code);
  int get_available_count();
  int get_discount_code_credit();
  int get_code();
  DiscountCode& operator--();
private:
  int AvailableCount;
  int DiscountCodeCredit;
  int Code;
};
#endif
