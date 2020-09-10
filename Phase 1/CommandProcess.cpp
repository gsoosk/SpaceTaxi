#include "SpaceTaxi.h"
using namespace std;
CommandProcess:: CommandProcess(SpaceTaxi *c)
{
	Controller = c ;
}

void CommandProcess:: recognize_command(string Username, string Command, string CommandLine)
{
	if(Command=="register_passenger")
		this->register_passenger(Username, CommandLine);
	else if(Command=="register_driver")
		this->register_driver(Username, CommandLine);
	else if(Username=="admin" && Command=="accept_registration")
		this->accept_registration(CommandLine);
	else if(Username=="admin" && Command=="reject_registration")
		this->reject_registration(CommandLine);
	else if(Username=="admin" && Command=="show_registration_requests")
		this->show_registration_requests();
	else if(Command=="login")
		Controller->login(Username,CommandLine);
	else if(Command=="logout")
		Controller->logout(Username);
	else if(Command=="get_discount_code")
		Controller->get_discount_code(Username);
	else if(Command=="set_status")
		this->set_status(CommandLine,Username);
	else if(Command=="estimate_trip")
		this->estimate_trip(CommandLine, Username);
	else if(Command=="request_trip")
		this->request_trip(CommandLine, Username);
	else if(Command=="cancel_trip_request")
		Controller->cancel_trip_request(Username);
	else if(Command=="show_trip_requests")
		Controller->show_trip_requests(Username);
	else if(Command=="accept_trip_request")
		this->accept_trip_request(Username,CommandLine);
	else if(Command=="trip_status")
		Controller->trip_status(Username);
	else if(Command=="arrived")
		Controller->arrived(Username);
	else if(Command=="end_trip")
		Controller->end_trip(Username);
	else if(Command=="rate_driver")
		this->rate_driver(Username, CommandLine);
	else if(Command=="charge_account")
		this->charge_account(Username, CommandLine);
	else if(Command=="get_credit")
		Controller->get_credit(Username);
	else if(Username=="admin" && Command=="set_time")
		this->set_time(CommandLine);
	else if(Username=="admin" && Command=="driver_report")
		this->driver_report(CommandLine);
	else if(Username=="admin" && Command=="passenger_report")
		this->passenger_report(CommandLine);
	else if(Username=="admin" && Command=="system_report")
		this->system_report(CommandLine);
}
void CommandProcess:: register_passenger(string Username, string CommandLine)
{
	string Password;
	string PhoneNumber;
	Password=GetSubStrFromLine(CommandLine, ' ');
	PhoneNumber=GetSubStrFromLine(CommandLine, ' ');
	string DiscountCodeStr ="";
	bool UseDiscountCode = false ;
	
	if(CommandLine!="")
	{
		UseDiscountCode = true ;
		DiscountCodeStr = CommandLine;
	}

	Controller->register_passenger(Username, Password, PhoneNumber, UseDiscountCode, DiscountCodeStr);
	
}
void CommandProcess:: register_driver(std:: string Username, std:: string CommandLine)
{
	string Password = GetSubStrFromLine(CommandLine,' ');
	string SpaceShipNumber = GetSubStrFromLine(CommandLine,' ');
	string SpaceShipModel = GetSubStrFromLine(CommandLine,' ');
	string ProductionYear = GetSubStrFromLine(CommandLine,' ');
	string SpaceShipColor = GetSubStrFromLine(CommandLine,' ');
	SpaceShip newSpaceShip(SpaceShipNumber, SpaceShipModel, ProductionYear, SpaceShipColor);

	bool VIP=false;
	if(CommandLine=="VIP")
		VIP=true;
	Controller->register_driver(Username, Password, SpaceShipNumber, SpaceShipModel, newSpaceShip, VIP);
}
void CommandProcess:: accept_registration(string CommandLine)
{
	string Username = GetSubStrFromLine(CommandLine,' ');
	Controller->accept_registration(Username);
}
void CommandProcess:: reject_registration(string CommandLine)
{
	string Username = GetSubStrFromLine(CommandLine,' ');
	Controller->reject_registration(Username);
}
void CommandProcess:: show_registration_requests()
{
	Controller-> show_registration_requests();
}
void CommandProcess:: set_status(string CommandLine, string Username)
{
	string temp=GetSubStrFromLine(CommandLine,' ');
	if(temp=="available")
	{
		string Address = CommandLine;
		try{
			if(CommandLine=="")
				throw BadException("Bad command !\n");
			if(!Controller->address_check(Address))
				throw BadException("Bad Address !\n");
			Controller->set_status_available(Address , Username);
		}
		catch(BadException ex)
		{
			ex.print_Exception();
		}
	}
	else if(temp=="unavailable")
		Controller->set_status_unavailable(Username); 
}
void CommandProcess:: estimate_trip(string CommandLine, string Username)
{
	string Line=CommandLine;
	string temp = GetSubStrFromLine(CommandLine,' ');
	bool VIP = false;
	string SourceAddress;
	try{
		if(temp=="")
			throw BadException("Bad Command!\n");
		if(temp=="VIP")
		{
			VIP = true;
			SourceAddress = GetSubStrFromLine(CommandLine,' ');
		}
		else
			SourceAddress=temp;

		if(!Controller->address_check(SourceAddress))
			throw BadException("Bad source address!\n");
		if(CommandLine=="")
			throw BadException("Bad Command!\n");
		vector<string> Destinations;
		while(CommandLine!="")
		{
			string DestinationAddress = GetSubStrFromLine(CommandLine,' ');
			if(!Controller->address_check(DestinationAddress))
				throw BadException("Bad destination address!\n");
			Destinations.push_back(DestinationAddress);
		}
		Trip* estimatedTrip = Controller->estimate_trip(Username, SourceAddress, Destinations, VIP);
		estimatedTrip->print_cost_and_distance();
		delete(estimatedTrip);
	}
	catch(BadException ex){
		ex.print_Exception();
	}
}
void CommandProcess:: request_trip(string CommandLine,string Username)
{
	string Line=CommandLine;
	string temp = GetSubStrFromLine(CommandLine,' ');
	bool VIP = false;
	string SourceAddress;
	try{
		if(temp=="")
			throw BadException("Bad Command!\n");
		if(temp=="VIP")
		{
			VIP = true;
			SourceAddress = GetSubStrFromLine(CommandLine,' ');
		}
		else
			SourceAddress=temp;

		if(!Controller->address_check(SourceAddress))
			throw BadException("Bad source address!\n");
		if(CommandLine=="")
			throw BadException("Bad Command!\n");
		vector<string> Destinations;
		while(CommandLine!="")
		{
			string DestinationAddress = GetSubStrFromLine(CommandLine,' ');
			if(!Controller->address_check(DestinationAddress))
				throw BadException("Bad destination address!\n");
			Destinations.push_back(DestinationAddress);
		}
		Trip* RequestedTrip = Controller->estimate_trip(Username, SourceAddress, Destinations, VIP);
		if(RequestedTrip->bad_trip())
			throw BadException("Can not estimate trip!\n");
		RequestedTrip->update_near_drivers(Controller->find_drivers(SourceAddress, VIP));
		RequestedTrip->print_cost_and_distance();
		Controller->request_trip(SourceAddress, Username, RequestedTrip, VIP);
	}
	catch(BadException ex){
		ex.print_Exception();
	}
}
void CommandProcess:: accept_trip_request(string Username, string CommandLine)
{
	string PassengerUsername = GetSubStrFromLine(CommandLine, ' ');
	Controller->accept_trip_request(Username, PassengerUsername);
}
void CommandProcess:: rate_driver(string Username, string CommandLine)
{
	try{
		string RateStr = GetSubStrFromLine(CommandLine,' ');
		int AllRate = atoi(RateStr.c_str());
		if(AllRate<1 || AllRate>10)
			throw BadException("The rate number should be 1-10. \n");
		Controller->rate_driver(Username , AllRate);
	}
	catch(BadException ex)
	{
		ex.print_Exception();
	}
}
void CommandProcess:: charge_account(string Username, string CommandLine)
{
	string CreditStr = GetSubStrFromLine(CommandLine,' ');
	int Credit = atoi(CreditStr.c_str());
	Controller->charge_account(Username, Credit);
}
void CommandProcess:: set_time(string CommandLine)
{
	try{
		int Day = atoi(GetSubStrFromLine(CommandLine,'-').c_str());
		int Hour = atoi(GetSubStrFromLine(CommandLine,':').c_str());
		int Minute = atoi(GetSubStrFromLine(CommandLine,':').c_str());
		int Second = atoi(GetSubStrFromLine(CommandLine,' ').c_str());
		if(!Controller->check_time(Day,Hour,Minute,Second))
			throw BadException("Bad Date\n");
		Controller->set_time(Day, Hour, Minute, Second);
	}
	catch(BadException ex)
	{
		ex.print_Exception();
	}
}
void CommandProcess:: driver_report(string CommandLine)
{
	string DriverUsername = GetSubStrFromLine(CommandLine, ' ');
	Date FirstDate(GetSubStrFromLine(CommandLine,' '));
	Date SecondDate(GetSubStrFromLine(CommandLine,' '));
	Controller->driver_report(DriverUsername, FirstDate, SecondDate);
}
void CommandProcess:: passenger_report(string CommandLine)
{
	try{
		if(CommandLine=="")
			throw BadException("Bad Command!\n");
		string PassengerUsername = GetSubStrFromLine(CommandLine, ' ');
		Controller->passenger_report(PassengerUsername);

	}
	catch(BadException ex)
	{
		ex.print_Exception();
	}
}
void CommandProcess:: system_report(string CommandLine)
{
	if(CommandLine=="")
		Controller->usual_system_report();
	else if(CommandLine!="")
	{
		try{
			Date FirstDate(GetSubStrFromLine(CommandLine,' '));
			if(CommandLine=="")
				throw BadException("Bad command!\n");
			Date SecondDate(GetSubStrFromLine(CommandLine,' '));
			Controller->system_report_by_time(FirstDate, SecondDate);
		}
		catch(BadException ex)
		{
			ex.print_Exception();
		}
	}
}