#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H
#include "SpaceTaxi.h"
class SpaceShip {
public:
	SpaceShip(std::string number, std::string model, std::string year, std::string color);
	std::string get_number();
	void print();
	void print2();

private:
	std::string SpaceShipNumber;
	std::string SpaceShipModel;
	std::string ProductionYear;
	std::string SpaceShipColor;
};
#endif
