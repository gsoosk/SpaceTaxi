#ifndef COMMAND_PROCESS_H
#define COMMAND_PROCESS_H
#include "SpaceTaxi.h"
class SpaceTaxi;
class CommandProcess{
public:
	CommandProcess(SpaceTaxi *c);
	std:: string recognize_command(std:: string Type,std:: string Username, std:: string Command, std:: string CommandLine);
	std:: string register_passenger(std:: string Username, std:: string CommandLine);
	std:: string register_driver(std:: string Username, std:: string CommandLine);
	std:: string accept_registration(std:: string CommandLine);
	std:: string reject_registration(std:: string CommandLine);
	std:: string show_registration_requests();
	std:: string set_status(std:: string CommandLine, std:: string Username);
	std:: string estimate_trip(std:: string CommandLine, std:: string Username);
	std:: string request_trip(std:: string CommandLine, std:: string Username);
	std:: string accept_trip_request(std:: string Username, std:: string CommandLine);
	std:: string rate_driver(std:: string Username, std:: string CommandLine);
	std:: string charge_account(std:: string Username, std:: string CommandLine);
	std:: string set_time(std:: string CommandLine);
	std:: string driver_report(std:: string CommandLine);
	std:: string passenger_report(std:: string CommadnLine);
	std:: string system_report(std:: string CommandLine);
private:
	SpaceTaxi* Controller;
};
#endif