#include "SpaceTaxi.h"
using namespace std;
CommandProcess:: CommandProcess(SpaceTaxi *c)
{
	Controller = c ;
}

std:: string CommandProcess:: recognize_command(string Type, string Username, string Command, string CommandLine)
{
	if(Type == "admin")
	{
		if(Command=="login")
			return Controller->login(Username,CommandLine);
		else if(Command=="logout")
			return Controller->logout(Username);
		else if(Username=="admin" && Command=="accept_registration")
			return this->accept_registration(CommandLine);
		else if(Username=="admin" && Command=="reject_registration")
			return this->reject_registration(CommandLine);
		else if(Username=="admin" && Command=="show_registration_requests")
			return this->show_registration_requests();
		else if(Username=="admin" && Command=="set_time")
			return this->set_time(CommandLine);
		else if(Username=="admin" && Command=="driver_report")
			return this->driver_report(CommandLine);
		else if(Username=="admin" && Command=="passenger_report")
			return this->passenger_report(CommandLine);
		else if(Username=="admin" && Command=="system_report")
			return this->system_report(CommandLine);
		else 
			return "Bad Command!\n";
	} 
	else if(Type == "driver")
	{
		if(Command=="login")
			return Controller->login(Username,CommandLine);
		else if(Command=="logout")
			return Controller->logout(Username);
		else if(Command=="register_driver")
			return this->register_driver(Username, CommandLine);
		else if(Command=="set_status")
			return this->set_status(CommandLine,Username);
		else if(Command=="show_trip_requests")
			return Controller->show_trip_requests(Username);
		else if(Command=="accept_trip_request")
			return this->accept_trip_request(Username,CommandLine);
		else if(Command=="arrived")
			return Controller->arrived(Username);
		else if(Command=="end_trip")
			return Controller->end_trip(Username);
		else 
			return "Bad Command!\n";
	}
	else if(Type == "passenger")
	{
		if(Command=="login")
			return Controller->login(Username,CommandLine);
		else if(Command=="logout")
			return Controller->logout(Username);
		else if(Command=="register_passenger")
			return this->register_passenger(Username, CommandLine);
		else if(Command=="get_discount_code")
			return Controller->get_discount_code(Username);
		else if(Command=="estimate_trip")
			return this->estimate_trip(CommandLine, Username);
		else if(Command=="request_trip")
			return this->request_trip(CommandLine, Username);
		else if(Command=="cancel_trip_request")
			return Controller->cancel_trip_request(Username);
		else if(Command=="trip_status")
			return Controller->trip_status(Username);
		else if(Command=="rate_driver")
			return this->rate_driver(Username, CommandLine);
		else if(Command=="charge_account")
			return this->charge_account(Username, CommandLine);
		else if(Command=="get_credit")
			return Controller->get_credit(Username);
		else
			return "Bad Command!\n";
	}
	else 
		return "Bad Type and Command.\n";

}
std:: string CommandProcess:: register_passenger(string Username, string CommandLine)
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

	return Controller->register_passenger(Username, Password, PhoneNumber, UseDiscountCode, DiscountCodeStr);
	
}
std:: string CommandProcess:: register_driver(std:: string Username, std:: string CommandLine)
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
	return Controller->register_driver(Username, Password, SpaceShipNumber, SpaceShipModel, newSpaceShip, VIP);
}
std:: string CommandProcess:: accept_registration(string CommandLine)
{
	string Username = GetSubStrFromLine(CommandLine,' ');
	return Controller->accept_registration(Username);
}
std:: string CommandProcess:: reject_registration(string CommandLine)
{
	string Username = GetSubStrFromLine(CommandLine,' ');
	return Controller->reject_registration(Username);
}
std:: string CommandProcess:: show_registration_requests()
{
	return Controller-> show_registration_requests();
}
std:: string CommandProcess:: set_status(string CommandLine, string Username)
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
			return Controller->set_status_available(Address , Username);
		}
		catch(BadException ex)
		{
			return ex.print_Exception();
		}
	}
	else if(temp=="unavailable")
		return Controller->set_status_unavailable(Username); 
	else 
		return "Bad Command!\n";
}
std:: string CommandProcess:: estimate_trip(string CommandLine, string Username)
{
	string Line=CommandLine;
	string temp = GetSubStrFromLine(CommandLine,' ');
	bool VIP = false;
	string SourceAddress;
	try{
		if(!Controller->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		if(!Controller->passenger_exist(Username))
			throw BadException("There is'nt any passenger with this username\n");
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
		string ReturnStr = estimatedTrip->print_cost_and_distance();
		delete(estimatedTrip);
		return ReturnStr;
	}
	catch(BadException ex){
		return ex.print_Exception();
	}
}
std:: string CommandProcess:: request_trip(string CommandLine,string Username)
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
		string ReturnStr = RequestedTrip->print_cost_and_distance();
		ReturnStr += "\n";
		ReturnStr += Controller->request_trip(SourceAddress, Username, RequestedTrip, VIP);
		return ReturnStr;
	}
	catch(BadException ex){
		return ex.print_Exception();
	}
}
std:: string CommandProcess:: accept_trip_request(string Username, string CommandLine)
{
	string PassengerUsername = GetSubStrFromLine(CommandLine, ' ');
	return Controller->accept_trip_request(Username, PassengerUsername);
}
std:: string CommandProcess:: rate_driver(string Username, string CommandLine)
{
	try{
		string RateStr = GetSubStrFromLine(CommandLine,' ');
		int AllRate = atoi(RateStr.c_str());
		if(AllRate<1 || AllRate>10)
			throw BadException("The rate number should be 1-10. \n");
		return Controller->rate_driver(Username , AllRate);
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
std:: string CommandProcess:: charge_account(string Username, string CommandLine)
{
	string CreditStr = GetSubStrFromLine(CommandLine,' ');
	int Credit = atoi(CreditStr.c_str());
	return Controller->charge_account(Username, Credit);
}
std:: string CommandProcess:: set_time(string CommandLine)
{
	try{
		int Day = atoi(GetSubStrFromLine(CommandLine,'-').c_str());
		int Hour = atoi(GetSubStrFromLine(CommandLine,':').c_str());
		int Minute = atoi(GetSubStrFromLine(CommandLine,':').c_str());
		int Second = atoi(GetSubStrFromLine(CommandLine,' ').c_str());
		if(!Controller->check_time(Day,Hour,Minute,Second))
			throw BadException("Bad Date\n");
		return Controller->set_time(Day, Hour, Minute, Second);
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
std:: string CommandProcess:: driver_report(string CommandLine)
{
	string DriverUsername = GetSubStrFromLine(CommandLine, ' ');
	Date FirstDate(GetSubStrFromLine(CommandLine,' '));
	Date SecondDate(GetSubStrFromLine(CommandLine,' '));
	return Controller->driver_report(DriverUsername, FirstDate, SecondDate);
}
std:: string CommandProcess:: passenger_report(string CommandLine)
{
	try{
		if(CommandLine=="")
			throw BadException("Bad Command!\n");
		string PassengerUsername = GetSubStrFromLine(CommandLine, ' ');
		return Controller->passenger_report(PassengerUsername);

	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
std:: string CommandProcess:: system_report(string CommandLine)
{
	if(CommandLine=="")
		return Controller->usual_system_report();
	else
	{
		try{
			Date FirstDate(GetSubStrFromLine(CommandLine,' '));
			if(CommandLine=="")
				throw BadException("Bad command!\n");
			Date SecondDate(GetSubStrFromLine(CommandLine,' '));
			return Controller->system_report_by_time(FirstDate, SecondDate);
		}
		catch(BadException ex)
		{
			return ex.print_Exception();
		}
	}

}