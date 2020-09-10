#include "SpaceTaxi.h"
using namespace std;
Planet:: Planet(std::string name, std:: vector<std:: string> names)
: Name(name), LinkedPlanetsName(names) {}

std:: string Planet::get_name(){ 
	return Name;
}

bool Planet:: does_it_linked_to(string PlanetName)
{
	for(int i=0; i<LinkedPlanetsName.size(); i++)
	{
		if(LinkedPlanetsName[i]==PlanetName)
			return true;
	}
	return false;
}
bool Planet:: does_this_name_match(string name)
{
	return name==Name;
}