#ifndef BAD_EXCEPTION_H
#define BAD_EXCEPTION_H
#include "SpaceTaxi.h"
class BadException{
public:
	BadException(std::string _eror);
	void print_Exception();
private:
	std::string Error;

};
#endif