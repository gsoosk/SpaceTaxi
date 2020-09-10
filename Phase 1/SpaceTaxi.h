#ifndef SPACE_TAXI_H
#define SPACE_TAXI_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "DiscountCode.h"
#include "Date.h"
#include "Rate.h"
#include "SystemMoney.h"
#include "Trip.h"
#include "Person.h"
#include "Admin.h"
#include "Passenger.h"
#include "SpaceShip.h"
#include "Driver.h"
#include "FindingDriverHelpingClass.h"
#include "Functions.h"
#include "BadException.h"
#include "Planet.h"
#include "Galaxy.h"
#include "Topology.h"
#include "CommandProcess.h"

#define EXISTS_PENDING 1
#define EXISTS 2
#define DOESNT_EXISTS 3
#define EXISTS_IN_FILE 4
#define ADMIN_USER "admin"
#define ADMIN_PASS "s3cret"
#define VIP_COEFFICIENT 2
#define SPECIAL_PASSENGERS_COEFFICIENT 0.5
#define MIN_TRIPS_FOR_SPECIAL_PASSENGER 3
#define MAX_TIME_FOR_ENTRANCE_SPECIAL 1
#define MIN_TIME_FOR_EXIT_SPECIAL 2
#define COST_ERROR -1
#define DISTANCE_ERROR -1
#define CAN_NEGETIVE_COST 10
#define MAX_DRIVER_FOUNDED 4
#define AVAILABLE true
#define UNAVAILABLE false
#define DRIVER_INCOME_PERCENTS 0.8

class SpaceTaxi{
public:
	SpaceTaxi(std::string vehicle, std::string topology):VehiclesLocation(vehicle), TopologyLocation(topology)
		,ourAdmin(Date("1-0:0:0"),ADMIN_USER,ADMIN_PASS), Topo(this->get_galaxies_from_file(topology)){}
	void register_passenger(std:: string Username, std::string Password, std::string PhoneNumber, bool UseDiscountCode, std:: string DiscountCodeStr);
	bool passenger_exist(std::string Username, std::string PhoneNumber);
	bool passenger_exist(std::string Username);
	bool driver_exist(std:: string Username);
	void register_driver(std::string Username, std::string Password, std:: string SpaceShipNumber, std:: string SpaceShipModel, SpaceShip newSpaceShip, bool VIP);
	int driver_existence_status(std::string &Username ,std::string &SpaceShipNumber, std::string &SpaceShipModel);
	void accept_registration(std::string &Username);
	void reject_registration(std::string &Username);
	void show_registration_requests();
	void login(std::string &Username, std::string &Password);
	void logout(std::string &Username);
	bool does_it_loged_in(std::string Username);
	void get_discount_code(std::string &Username);
	void use_discount_code(std::string CommandLine);
	std:: vector<Galaxy> get_galaxies_from_file(std:: string TopologyFileLocation);
	void set_status_available(std:: string Address, std:: string Username);
	bool address_check(std:: string Address);
	void set_status_unavailable(std:: string Username);
	Trip* estimate_trip(std::string Username,std::string SourceAddress, std:: vector<std:: string> Destinations, bool VIP);
	bool backtrack_min_distance (int &i, std:: string HomePlanet, std:: string DestinationPlanet, std:: vector<Planet> Planets
			, std:: string HeadPlanet);
	int minimum_distance(std::string HomePlanet, std::string Destination);
	void request_trip(std::string SourceAddress, std:: string Username, Trip* RequestedTrip, bool VIP);
	Person* find_loged_in_person(std::string Username);
	Passenger* find_passenger(std:: string Username);
	Driver* find_driver(std:: string Username);
	void cancel_trip_request(std:: string Username);
	std:: vector<Driver*> find_drivers(std:: string Address, bool VIP);
	void show_trip_requests(std:: string Username);
	void accept_trip_request(std:: string DriverUsername , std:: string PassengerUsername);
	void trip_status(std:: string Username);
	void arrived(std:: string Username);
	void end_trip(std:: string Username);
	void rate_driver(std:: string Username, int AllRate);
	void charge_account(std:: string Username,int Credit);
	void get_credit(std:: string Username);
	void set_time(int Day, int Hour, int Minute, int Second);
	bool check_time(int Day, int Hour, int Minute, int Second);
	bool does_it_special_passenger(Passenger * OurPassenger);
	void driver_report( std:: string DriverUsername, Date FirstDate, Date SecondDate);
	void passenger_report(std:: string PassengerUsername);
	void usual_system_report();
	void system_report_by_time(Date FirstDate, Date SecondDate);
	void settle_with_drivers(Date SecondDate);
private:
	std::vector<Driver*> RegisteredDrivers;
	std::vector<Driver*> PendingDrivers;
	std::vector<Passenger*> RegisteredPassengers;
	std::vector<Person*> LogedInPeople;
	Admin ourAdmin;
	std::string VehiclesLocation;
	std::string TopologyLocation;
	Topology Topo;
	Date SystemDate;
};
#endif
