#include "SpaceTaxi.h"
using namespace std;
SpaceShip:: SpaceShip(std::string number, std::string model, std::string year, std::string color)
: SpaceShipNumber(number),SpaceShipModel(model), ProductionYear(year), SpaceShipColor(color) {};

std::string SpaceShip:: get_number()
{return SpaceShipNumber;}

string SpaceShip:: print() 
{string ReturnStr = SpaceShipNumber+ " " + SpaceShipModel + " " + ProductionYear + " " + SpaceShipColor;
return ReturnStr;}

string SpaceShip:: print2()
{string ReturnStr = SpaceShipModel + " " +SpaceShipColor+ "\n";
return ReturnStr;}