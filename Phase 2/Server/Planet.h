#ifndef PLANET_H
#define PLANET_H
#include "SpaceTaxi.h"
class Planet{
public:
	Planet(std::string name, std:: vector<std:: string> names);
	std:: string get_name();
	bool does_it_linked_to(std:: string PlanetName);
	bool does_this_name_match(std:: string name);

private:
	std:: vector<std:: string> LinkedPlanetsName;
	std::string Name;
};
#endif