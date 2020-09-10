#ifndef COMMAND_PROCESS_H
#define COMMAND_PROCESS_H
#include "SpaceTaxi.h"
class SpaceTaxi;
class CommandProcess{
public:
	CommandProcess(SpaceTaxi *c);
	void recognize_command(std:: string Username, std:: string Command, std:: string CommandLine);
	void register_passenger(std:: string Username, std:: string CommandLine);
	void register_driver(std:: string Username, std:: string CommandLine);
	void accept_registration(std:: string CommandLine);
	void reject_registration(std:: string CommandLine);
	void show_registration_requests();
	void set_status(std:: string CommandLine, std:: string Username);
	void estimate_trip(std:: string CommandLine, std:: string Username);
	void request_trip(std:: string CommandLine, std:: string Username);
	void accept_trip_request(std:: string Username, std:: string CommandLine);
	void rate_driver(std:: string Username, std:: string CommandLine);
	void charge_account(std:: string Username, std:: string CommandLine);
	void set_time(std:: string CommandLine);
	void driver_report(std:: string CommandLine);
	void passenger_report(std:: string CommadnLine);
	void system_report(std:: string CommandLine);
private:
	SpaceTaxi* Controller;
};
#endif