#include "SpaceTaxi.h"
using namespace std;
SpaceShip:: SpaceShip(std::string number, std::string model, std::string year, std::string color)
: SpaceShipNumber(number),SpaceShipModel(model), ProductionYear(year), SpaceShipColor(color) {};

std::string SpaceShip:: get_number()
{return SpaceShipNumber;}

void SpaceShip:: print() 
{std::cout<<SpaceShipNumber<<" "<<SpaceShipModel<<" "<<ProductionYear<<" "<<SpaceShipColor;}

void SpaceShip:: print2()
{std::cout<<SpaceShipModel<<" "<<SpaceShipColor<<std::endl;}