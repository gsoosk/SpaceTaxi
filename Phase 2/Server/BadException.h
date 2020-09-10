#ifndef BAD_EXCEPTION_H
#define BAD_EXCEPTION_H
#include "SpaceTaxi.h"
class BadException{
public:
	BadException(std::string _eror);
	std:: string print_Exception();
private:
	std::string Error;

};
#endif