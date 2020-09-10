#include "SpaceTaxi.h"
using namespace std;
BadException :: BadException(string error)
: Error(error){};
string  BadException:: print_Exception()
{
	return Error;
}