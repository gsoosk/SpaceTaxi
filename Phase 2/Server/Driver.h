#ifndef DRIVER_H
#define DRIVER_H
#include "SpaceTaxi.h"
class Driver : public Person{

public:
	Driver(Date RT,std::string user, std::string pass, SpaceShip SS, bool vip);
	bool does_space_ship_match(std::string SpaceShipNumber);
	std:: string print();
	void set_status(bool x);
	void set_address(std:: string Ad);
	std:: string get_address();
	bool does_it_VIP();
	std:: string get_galaxy();
	int make_magic_num(int Distance);
	void change_trip_status();
	bool triping();
	void change_accepted_trip(Trip* AT);
	std:: string print2();
	bool does_it_have_accepted_request();
	void arrived();
	bool does_it_have_arrived_request();
	Trip* end_trip(Admin* OurAdmin, Date SystemDate);
	void inc_Rate(int r, Date T);
	std:: string driver_report(Date FirstDate, Date SecondDate);
	void settle(Date FirstDate, Date SecondDate, Admin &ourAdmin);

private:
	SpaceShip SpaceShipOfDriver;
	bool VIP;
	bool Available;
	bool TripStatus;
	std::string Address;
	std:: vector<Rate> Rates;
	int AllRates;
	Trip* AcceptedTrip;
	Trip* ArrivedTrip;
	std:: vector<Trip*> EndedTrips;
	double Income;

};
#endif