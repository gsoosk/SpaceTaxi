#ifndef GALAXY_H
#define GALAXY_H
#include "SpaceTaxi.h"
class Galaxy{
public:
	Galaxy(std:: string name, std:: vector<Planet> p,std:: string g);
	std:: vector<Planet> get_planet();
	std:: string get_name();
	bool does_this_name_match(std:: string GalaxyName);
	std:: string get_gate();
private:
	std:: vector<Planet> Planets;
	std:: string Name;
	std:: string Gate;
};
#endif