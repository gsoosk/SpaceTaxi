#ifndef TOPOLOGY_H
#define TOPOLOGY_H
#include "SpaceTaxi.h"
class Topology{
public:
	Topology(std:: vector<Galaxy> g);
	std:: vector<Galaxy> get_galaxy();
	std:: vector<Planet> get_planets_of_galaxy(std:: string GalaxyName);
	std:: string gate_planet_of_galaxy(std:: string GalaxyName);

private:
	std:: vector<Galaxy> Galaxies;
};
#endif