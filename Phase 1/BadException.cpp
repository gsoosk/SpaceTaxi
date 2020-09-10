#include "SpaceTaxi.h"
using namespace std;
BadException :: BadException(string error)
: Error(error){};
void BadException:: print_Exception()
{
	cout<<Error;
}