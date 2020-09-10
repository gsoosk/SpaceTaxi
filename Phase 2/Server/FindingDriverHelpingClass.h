#ifndef FINDING_DRIVER_HELPING_CLASS_H
#define FINDING_DRIVER_HELPING_CLASS_H
#include "SpaceTaxi.h"
class FindingDriverHelpingClass 
{
public:
	FindingDriverHelpingClass(int magic, Driver* finding);
	int get_magic_num();
	Driver* get_driver();
private:
	int MagicNumber;
	Driver* FindedDriver;
};
#endif