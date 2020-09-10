#include "SpaceTaxi.h"
using namespace std;
FindingDriverHelpingClass:: FindingDriverHelpingClass(int magic, Driver* finding)
:MagicNumber(magic), FindedDriver(finding){}

int FindingDriverHelpingClass:: get_magic_num()
{
	return MagicNumber;
}

Driver* FindingDriverHelpingClass:: get_driver()
{
	return FindedDriver;
}