#include "SpaceTaxi.h"
using namespace std;
Topology:: Topology(std:: vector<Galaxy> g)
: Galaxies(g){}

std:: vector<Galaxy> Topology:: get_galaxy()
{ return Galaxies;}

vector<Planet> Topology:: get_planets_of_galaxy(string GalaxyName)
{
	try{
		for(int i=0; i<Galaxies.size(); i++)
		{
			if(Galaxies[i].does_this_name_match(GalaxyName))
				return Galaxies[i].get_planet();
		}
		throw BadException("This Planet doesnt exists in topology.\n");
	}
	catch(BadException ex)
	{
		ex.print_Exception();
		vector<Planet> Planets;
		return Planets;
	}
	
}

string Topology:: gate_planet_of_galaxy(string GalaxyName)
{
	try{
		for(int i=0; i<Galaxies.size(); i++)
		{
			if(Galaxies[i].does_this_name_match(GalaxyName))
				return Galaxies[i].get_gate();
		}
		throw BadException("This Galaxy doesnt exists \n");
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
	
}