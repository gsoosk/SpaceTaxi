#include "SpaceTaxi.h"
using namespace std;
Galaxy:: Galaxy(std:: string name, std:: vector<Planet> p,std:: string g)
:Gate(g), Name(name), Planets(p){}

bool Galaxy:: does_this_name_match(string GalaxyName)
{
	return GalaxyName==Name;
}
string Galaxy:: get_gate()
{
	return Gate;
}
std:: vector<Planet> Galaxy:: get_planet()
{
	return Planets;
}
std:: string Galaxy:: get_name()
{
	return Name;
}