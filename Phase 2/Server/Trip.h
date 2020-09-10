#ifndef TRIP_H
#define TRIP_H
#include "SpaceTaxi.h"
class Driver;
class Passenger;
class Trip{
public:
	Trip(int cost, int dis,std::string sourceAddress, std::vector<std:: string> destinations,Passenger* user, Date TDate);
	std:: string print_cost_and_distance();
	bool bad_trip();
	bool does_credit_enough(int credit);
	int get_cost();
	void update_near_drivers(std::vector<Driver*> FindedDrivers);
	bool driver_exist(std:: string Username);
	std:: string print_trip();
	void accepted_by(Driver* D);
	std:: string print_trips_driver_details();
	std:: string get_last_destination();
	void decrease_credit_from_user();
	int real_money();
	void end_trip_for_passenger();
	void rate_driver(int R, Date T);
	Date get_date();

private:
	int Distance;
	int Cost;
	std::vector<Driver*> NearDrivers;
	std::string SourceAddress;
	std:: vector<std::string> Destinations;
	Passenger* Username;
	Driver* AcceptedBy ;
	Date TripDate;

};
#endif