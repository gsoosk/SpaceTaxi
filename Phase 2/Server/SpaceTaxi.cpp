#include "SpaceTaxi.h"
using namespace std;
string SpaceTaxi:: register_passenger(string Username, string Password,string PhoneNumber, bool UseDiscountCode, string DiscountCodeStr)
{
	try{
		if(this->passenger_exist(Username, PhoneNumber))
			throw BadException("A user with the same phone or username exists.\n");

		Passenger* newPassenger = new Passenger(SystemDate,Username, Password, PhoneNumber, RegisteredPassengers.size()+1);
		RegisteredPassengers.push_back(newPassenger);
		if(UseDiscountCode)
			return this->use_discount_code(DiscountCodeStr);
		return "You registered succesfully!\n";
		 
	}
	catch(BadException exception){
		return exception.print_Exception();
	}
	
}

bool SpaceTaxi:: passenger_exist (string Username, string PhoneNumber)
{
	for(int i=0; i<RegisteredPassengers.size(); i++)
	{
		if(Username==RegisteredPassengers[i]->get_username())
			return true;
		if(PhoneNumber==RegisteredPassengers[i]->get_phone())
			return true;
	}
	for(int i=0; i<RegisteredDrivers.size(); i++)
		if(Username==RegisteredDrivers[i]->get_username())
			return true;
	for(int i=0; i<PendingDrivers.size(); i++)
		if(Username==PendingDrivers[i]->get_username())
			return true;
	return false;
}
bool SpaceTaxi:: passenger_exist(string Username)
{
	for(int i=0; i<RegisteredPassengers.size(); i++)
	{
		if(Username==RegisteredPassengers[i]->get_username())
			return true;
	}
	return false;
}
string SpaceTaxi:: register_driver(string Username, string Password, string SpaceShipNumber, string SpaceShipModel, SpaceShip newSpaceShip, bool VIP)
{
	
	try{
		int DriverExistenceStatus = this->driver_existence_status(Username, SpaceShipNumber, SpaceShipModel);
		if(DriverExistenceStatus==EXISTS)
			throw BadException("A user with the same username or spaceship number exist.\n");
		else if(DriverExistenceStatus==EXISTS_PENDING)
			throw BadException("A driver with the same username or spaceship number is pending.\n");
		else if(DriverExistenceStatus==DOESNT_EXISTS)
			throw BadException("This vehicle model doesnt exists in our data base.\n");
		Driver* newDriver = new Driver(SystemDate, Username, Password, newSpaceShip, VIP);
		PendingDrivers.push_back(newDriver);
		return "Driver Registered ! \n";
	}
	catch(BadException exception){
		return exception.print_Exception();
	}


}
int SpaceTaxi:: driver_existence_status(string &Username ,string &SpaceShipNumber, string &SpaceShipModel)
{
	for(int i=0; i<RegisteredPassengers.size(); i++)
		if(Username==RegisteredPassengers[i]->get_username())
			return EXISTS;
	for(int i=0; i<RegisteredDrivers.size(); i++)
	{
		if(Username==RegisteredDrivers[i]->get_username())
			return EXISTS;
		if(RegisteredDrivers[i]->does_space_ship_match(SpaceShipNumber))
			return EXISTS;
	}
	for(int i=0; i<PendingDrivers.size(); i++)
	{
		if(Username==PendingDrivers[i]->get_username())
			return EXISTS_PENDING;
		if(PendingDrivers[i]->does_space_ship_match(SpaceShipNumber))
			return EXISTS_PENDING;
	}
	ifstream VehiclesFile(VehiclesLocation.c_str());
	if(!VehiclesFile)
	{
		cout<<"Could not open the vehicle file"<<endl;
		return DOESNT_EXISTS;
	}
	string Model;
	while(VehiclesFile>>Model)
	{
		if(SpaceShipModel==Model)
			return EXISTS_IN_FILE;
	}

	return DOESNT_EXISTS;
}
string SpaceTaxi:: accept_registration(std::string &Username)
{
	try{
		if(!this->does_it_loged_in(ourAdmin.get_username()))
			throw BadException("Admin doesnt loged in\n");
		for(int i=0; i<PendingDrivers.size(); i++)
		{
			if(PendingDrivers[i]->get_username()==Username)
			{
				RegisteredDrivers.push_back(PendingDrivers[i]);
				PendingDrivers.erase(PendingDrivers.begin()+i);
				return "User accepted.\n";
			}
		}
		return "The user doesnt exist.\n";

	}
	catch(BadException ex){
		return ex.print_Exception();
	}

}
string  SpaceTaxi:: reject_registration(std::string &Username)
{
	try{
		if(!this->does_it_loged_in(ourAdmin.get_username()))
			throw BadException("Admin doesnt loged in\n");
		for(int i=0; i<PendingDrivers.size(); i++)
			if(PendingDrivers[i]->get_username()==Username)
			{
				delete(PendingDrivers[i]);
				PendingDrivers.erase(PendingDrivers.begin()+i);
				return "Registration rejected succesfully!\n";
			}
		return "There is not any registration with this Username.\n";
	}
	catch(BadException ex){
		return ex.print_Exception();
	}
}
string SpaceTaxi:: show_registration_requests()
{
	try{
		if(!this->does_it_loged_in(ourAdmin.get_username()))
			throw BadException("Admin doesnt loged in\n");
		string ReturnStr="";
		if(PendingDrivers.size()!=0)
		{
			ReturnStr += "[";
			for(int i=0; i<PendingDrivers.size(); i++)
			{
				ReturnStr+= PendingDrivers[i]->print();
			}
			ReturnStr += "]*\n";
		}
		return ReturnStr;
	}
	catch(BadException ex){
		return ex.print_Exception();
	}

}
std:: string SpaceTaxi:: login(string &Username, string &Password)
{
	bool Flag= false;
	for(int i=0; i<LogedInPeople.size(); i++)
	{
		if(LogedInPeople[i]->check_user_and_pass_matched(Username,Password))
			return "you loged in already. \n";

	}
	if(Flag==false)
	{
		for(int i=0; i<RegisteredDrivers.size(); i++)
		{
			if(RegisteredDrivers[i]->check_user_and_pass_matched(Username,Password))
			{
				LogedInPeople.push_back(RegisteredDrivers[i]);
				return "You loged in succesfully!\n";
			}
		}
		for(int i=0; i<RegisteredPassengers.size(); i++)
		{
			if(RegisteredPassengers[i]->check_user_and_pass_matched(Username,Password))
			{
				LogedInPeople.push_back(RegisteredPassengers[i]);
				return "You loged in succesfully!\n";
			}
		}
		for(int i=0; i<PendingDrivers.size(); i++)
		{
			if(PendingDrivers[i]->check_user_and_pass_matched(Username,Password))
				return "This user is pending\n";
		}
		if(ourAdmin.check_user_and_pass_matched(Username,Password))
		{
			LogedInPeople.push_back(&ourAdmin);
			return "You loged in succesfully!\n";
		}
	}
	return "You Can not login!\n";

}
string SpaceTaxi:: logout(string &Username)
{
	for(int i=0; i<LogedInPeople.size(); i++)
	{
		if(LogedInPeople[i]->get_username()==Username)
		{
			LogedInPeople.erase(LogedInPeople.begin()+i);
			return "You loged out succesfully!\n";
		}
	}
	return "You did not loged in at all.\n";
}
bool SpaceTaxi:: does_it_loged_in(std::string Username)
{
	for(int i=0; i<LogedInPeople.size(); i++)
		if(LogedInPeople[i]->get_username()==Username)
			return true;
	return false;
}
string SpaceTaxi:: get_discount_code(std::string &Username)
{
	try{
		if(!this->passenger_exist(Username))
			throw BadException("There is'nt any passenger with this username\n");
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		for(int i=0; i<RegisteredPassengers.size(); i++)
		{
			if(Username==RegisteredPassengers[i]->get_username())
			{
				if(!RegisteredPassengers[i]->does_discount_code_actived())
					RegisteredPassengers[i]->active_discount_code();
				return RegisteredPassengers[i]->print_discount_code();
			}
		}
		return "";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: use_discount_code(string CommandLine)
{
	int Code = atoi(CommandLine.c_str());
	try{
		if(Code<=0 || Code > RegisteredPassengers.size())
			throw BadException("This Code doesn't exists\n");
		if(!RegisteredPassengers[Code-1]->does_discount_code_actived())
			throw BadException("This Code doesn't exists\n");
		if(!RegisteredPassengers[Code-1]->does_discount_code_usable())
			throw BadException("You can't use this code\n");
		RegisteredPassengers[Code-1]->inc_discount_credit(DISCOUNT_CODE_CREDIT);
		RegisteredPassengers[Code-1]->dec_discount_code_count();
		RegisteredPassengers[RegisteredPassengers.size()-1]->inc_discount_credit(DISCOUNT_CODE_CREDIT);
		return "You registered with discount code succesfully!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}

}
vector<Galaxy> SpaceTaxi:: get_galaxies_from_file(string TopologyFileLocation)
{
	ifstream TopoFile(TopologyFileLocation.c_str());
	int NumberOfGalaxies;
	TopoFile >> NumberOfGalaxies;
	vector<Galaxy> Galaxies;
	for(int i=0; i<NumberOfGalaxies; i++)
	{

		string GalaxyName;
		TopoFile >> GalaxyName;
		int NumberOfPlanets;
		TopoFile >> NumberOfPlanets;
		vector<Planet> Planets;
		string Gate;
		for(int j=0; j<NumberOfPlanets; j++)
		{
			string PlanetName;
			TopoFile >> PlanetName;
			if(j==0)
				Gate=PlanetName;
			int NumberOfLinkedPlanets;
			TopoFile >> NumberOfLinkedPlanets;
			vector<string> LinkedPlanetsName;
			for(int k=0; k<NumberOfLinkedPlanets; k++)
			{
				string tempName;
				TopoFile >> tempName;
				LinkedPlanetsName.push_back(tempName);
			}
			Planet tempPlanet(PlanetName,LinkedPlanetsName);
			Planets.push_back(tempPlanet);
		}
		Galaxy tempGalaxy(GalaxyName,Planets,Gate);
		Galaxies.push_back(tempGalaxy);
	}
	return Galaxies;
}
string SpaceTaxi:: set_status_available(string Address,string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		for(int i=0; i<RegisteredDrivers.size(); i++)
		{
			if(Username==RegisteredDrivers[i]->get_username())
			{
				RegisteredDrivers[i]->set_status(AVAILABLE);
				RegisteredDrivers[i]->set_address(Address);
				break;
			}
		}
		return "You set your status available\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}

}
bool SpaceTaxi:: address_check(string Address)
{
	bool Flag=false;
	for(int i=0; i<Address.size(); i++)
		if(Address[i]==',')
		{
			Flag=true;
			break;
		}
	if(Flag==false)
		return false;
	string GalaxyName=GetSubStrFromLine(Address,',');
	string PlanetName=Address;
	bool GalaxyFlag=false;
	bool PlanetFlag=false;
	vector<Galaxy> Galaxies=Topo.get_galaxy();
	for(int i=0; i<Galaxies.size(); i++)
	{
		if(Galaxies[i].get_name() == GalaxyName)
			GalaxyFlag=true;
		vector<Planet> Planets = Galaxies[i].get_planet();
		for(int j=0; j<Planets.size(); j++)
		{
			if(Planets[j].get_name()==PlanetName && GalaxyFlag==true)
			{
				return true;
			}
		}
		GalaxyFlag=false;
	}
	return false;

}
string SpaceTaxi:: set_status_unavailable(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		for(int i=0; i<RegisteredDrivers.size(); i++)
		{
			if(Username==RegisteredDrivers[i]->get_username())
			{
				RegisteredDrivers[i]->set_status(UNAVAILABLE);
				break;
			}
		}
		return "You set your status unavailable.\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}

}

Trip* SpaceTaxi:: estimate_trip(string Username,string SourceAddress, vector<string> Destinations, bool VIP)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		if(!this->passenger_exist(Username))
			throw BadException("There is'nt any passenger with this username\n");

		int Cost=0 , Distance=0 ;
		string temp = SourceAddress;
		for(int i=0; i<Destinations.size(); i++)
		{
			Cost += this->minimum_distance(temp,Destinations[i]);
			Distance += this->minimum_distance(temp,Destinations[i]);
			temp=Destinations[i];
		}
		if(VIP)
			Cost *= VIP_COEFFICIENT;
		Passenger*  OurPassenger=this->find_passenger(Username);
		if(this->does_it_special_passenger(OurPassenger))
			Cost*= SPECIAL_PASSENGERS_COEFFICIENT;
		Trip* returnTrip = new Trip(Cost,Distance,SourceAddress,Destinations,OurPassenger,SystemDate);
		return returnTrip;
	}
	catch(BadException ex){
		Trip* returnTrip = new Trip(COST_ERROR,DISTANCE_ERROR,SourceAddress,Destinations,NULL,SystemDate);
		return returnTrip;
	}
}
bool SpaceTaxi:: does_it_special_passenger(Passenger* OurPassenger)
{
	if(!OurPassenger->get_speciality())
	{
		if(OurPassenger->num_of_ended_trips() < MIN_TRIPS_FOR_SPECIAL_PASSENGER)
		{
			return false;
		}
		if(OurPassenger->sum_of_space_of_last_n_trip(MIN_TRIPS_FOR_SPECIAL_PASSENGER) < MAX_TIME_FOR_ENTRANCE_SPECIAL)
		{
			OurPassenger->set_speciality(true);
			return true;
		}
		return false;
	}
	else
	{
		if(OurPassenger->does_it_must_exit_from_speciality(SystemDate))
		{
			OurPassenger->set_speciality(false);
			return false;
		}
		return true;
	}

}
int SpaceTaxi:: minimum_distance(std::string HomePlanetAddress, std::string DestinationAddress)
{
	string HomeGalaxy=GetSubStrFromLine(HomePlanetAddress,',');
	string HomePlanet=HomePlanetAddress;
	string DestinationGalaxy=GetSubStrFromLine(DestinationAddress,',');
	string Destination=DestinationAddress;
	vector<Planet> HomePlanets = Topo.get_planets_of_galaxy(HomeGalaxy);
	vector<Planet> DestinationPlanets = Topo.get_planets_of_galaxy(DestinationGalaxy);
	int Distance =0 ;
	if(HomeGalaxy==DestinationGalaxy)
		backtrack_min_distance(Distance, HomePlanet, Destination, HomePlanets,"");
	else
	{
		backtrack_min_distance(Distance, HomePlanet, Topo.gate_planet_of_galaxy(HomeGalaxy),HomePlanets , "");
		backtrack_min_distance(Distance, Topo.gate_planet_of_galaxy(DestinationGalaxy), Destination, DestinationPlanets, "");	
	}
	return Distance;
}

bool SpaceTaxi:: backtrack_min_distance (int &Distance, string HomePlanet, string DestinationPlanet,vector<Planet> Planets, 
			string HeadPlanet)
{
	vector<Planet> LinkedPlanets;
	for(int i=0; i<Planets.size(); i++)
	{
		if(Planets[i].does_it_linked_to(HomePlanet) && !Planets[i].does_this_name_match(HeadPlanet))
			LinkedPlanets.push_back(Planets[i]);
	}
	if(HomePlanet == DestinationPlanet)
		return true;
	if(LinkedPlanets.size()==0)
		return false;
	Distance++;
	for(int i=0; i<LinkedPlanets.size(); i++)
	{
		int j;
		j=Distance;
		bool temp = this->backtrack_min_distance(j, LinkedPlanets[i].get_name(), DestinationPlanet, Planets, HomePlanet);
		if(temp==true)
		{
			Distance=j;
			return true;
		}
	}
	return false;
}
string SpaceTaxi:: request_trip(string SourceAddress, string Username, Trip* RequestedTrip, bool VIP)
{
	try{
		Passenger* TripPassenger;
		TripPassenger = this->find_passenger(Username);
		if(TripPassenger==NULL)
			throw BadException("There is'nt any loged in user with this username\n");
		if(TripPassenger->triping())
			throw BadException("This User is triping now\n");
		if(TripPassenger->can_rate())
			throw BadException("First you should rate your last trip's driver.\n");
		if(!TripPassenger->affort_one_trip(RequestedTrip))
			throw BadException("Your credit is not enough for this trip.\n");

		TripPassenger->set_a_new_requested_trip(RequestedTrip);
		return "You request a trip succesfully!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}

}
Person* SpaceTaxi:: find_loged_in_person(string Username)
{
	for(int i=0; i<LogedInPeople.size(); i++)
	{
		if(LogedInPeople[i]->check_user_match(Username))
			return LogedInPeople[i];
	}
	return NULL;
}
Passenger* SpaceTaxi:: find_passenger(string Username)
{
	for(int i=0; i<RegisteredPassengers.size(); i++)
		if(RegisteredPassengers[i]->check_user_match(Username))
			return RegisteredPassengers[i];
	return NULL;
}
string SpaceTaxi:: cancel_trip_request(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		if(!this->passenger_exist(Username))
			throw BadException("There is'nt any passenger with this username\n");
		Passenger* TripPassenger;
		TripPassenger = this->find_passenger(Username);
		if(TripPassenger==NULL)
			throw BadException("There is'nt any loged in user with this username\n");
		return TripPassenger->cancel_trip_request();
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
vector<Driver*> SpaceTaxi:: find_drivers(std:: string Address, bool VIP)
{
	vector<FindingDriverHelpingClass> FindedDrivers;
	for(int i=0; i<RegisteredDrivers.size(); i++)
	{
		if(RegisteredDrivers[i]->does_it_VIP() != VIP)
			continue;
		if(RegisteredDrivers[i]->get_galaxy() != GetGalaxy(Address))
			continue;
		string DriverAddress = RegisteredDrivers[i]->get_address();
		int Distance = this->minimum_distance(Address,DriverAddress);
		int MagicNumber = RegisteredDrivers[i]->make_magic_num(Distance);    //MagicNumber = Distance*10 + Rate
		FindingDriverHelpingClass newFindedDriver(MagicNumber, RegisteredDrivers[i]);
		FindedDrivers.push_back(newFindedDriver);
	}
	sort(FindedDrivers.begin(), FindedDrivers.end(), pred);
	int Counter=0;
	if(FindedDrivers.size()< MAX_DRIVER_FOUNDED)
		Counter = FindedDrivers.size();
	else
		Counter = MAX_DRIVER_FOUNDED;
	vector<Driver*> ReturnDrivers;
	for(int i=0; i<Counter; i++)
		ReturnDrivers.push_back((FindedDrivers[i].get_driver()));
	return ReturnDrivers;
}

string SpaceTaxi:: show_trip_requests(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again\n");
		if(!this->driver_exist(Username))
			throw BadException("You are not a driver!\n");
		Driver* OurDriver = this->find_driver(Username);
		if(OurDriver->triping())
			throw BadException("This driver is triping now!\n");
		for(int i=0; i<RegisteredPassengers.size(); i++)
		{
			if(RegisteredPassengers[i]->exist_in_requested_trips(Username))
			{
				return RegisteredPassengers[i]->print_trip_request();
			}
		}
		return "";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
bool SpaceTaxi:: driver_exist(string Username)
{
	for(int i=0; i<RegisteredDrivers.size(); i++)
		if(RegisteredDrivers[i]->check_user_match(Username))
			return true;
	return false;
}

string SpaceTaxi:: accept_trip_request(string DriverUsername, string PassengerUsername)
{
	try{
		if(!this->does_it_loged_in(DriverUsername))
			throw BadException("Please login and then try again\n");
		if(!this->driver_exist(DriverUsername))
			throw BadException("You are not a driver!\n");
		if(!this->passenger_exist(PassengerUsername))
			throw BadException("There is not any passenger with this username!\n");
		Driver* OurDriver = this->find_driver(DriverUsername);
		if(OurDriver->triping())
			throw BadException("This Driver is triping!\n");
		Passenger* OurPassenger = this->find_passenger(PassengerUsername);
		if(!OurPassenger->does_it_have_requested_tirp())
			throw BadException("This Passenger doesn't have any requested trip \n");
		if(!OurPassenger->exist_in_requested_trips(DriverUsername))
			throw BadException("You can't accept this trip.\n");
		OurDriver->change_trip_status();
		Trip* AcceptedTrip = OurPassenger->accept_trip();
		OurDriver->change_accepted_trip(AcceptedTrip);
		AcceptedTrip->accepted_by(OurDriver);
		return "Trip Accepted!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
	
}
Driver* SpaceTaxi:: find_driver(string Username)
{
	for(int i=0; i<RegisteredDrivers.size(); i++)
		if(RegisteredDrivers[i]->check_user_match(Username))
			return RegisteredDrivers[i];

	return NULL;
}
string SpaceTaxi:: trip_status(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again!\n");
		if(!this->passenger_exist(Username))
			throw BadException("You are not a passenger!\n");
		Passenger* OurPassenger = this->find_passenger(Username);
		if(OurPassenger->triping())
		{	
			if(OurPassenger->does_it_have_requested_tirp())
				return "waiting\n";
			else
			{
				string ReturnStr = "accepted ";
				ReturnStr += OurPassenger->print_last_accepted_trip();
				return ReturnStr;
			}
		}
		else
			throw BadException("This passenger doesnt have any trip request!\n");


	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: arrived(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again!\n");
		if(!this->driver_exist(Username))
			throw BadException("You are not a driver!\n");
		Driver* OurDriver = this->find_driver(Username);
		if(OurDriver->triping())
		{
			if(OurDriver->does_it_have_accepted_request())
			{
				OurDriver->arrived();
			}
		}
		else 
			throw BadException("You cant use this Command!\n");
		return "You set that you arrived!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: end_trip(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again!\n");
		if(!this->driver_exist(Username))
			throw BadException("You are not a driver!\n");
		Driver* OurDriver = this->find_driver(Username);
		if(OurDriver->triping())
		{
			if(OurDriver->does_it_have_arrived_request())
			{

				Trip* OurTrip = OurDriver->end_trip(&ourAdmin, SystemDate);
				OurTrip->end_trip_for_passenger();
			}
		}
		else 
			throw BadException("You cant use this Command!\n");
		return "Trip ended!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: rate_driver(string Username, int AllRate)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again!\n");
		if(!this->passenger_exist(Username))
			throw BadException("You are not a passenger!\n");
		Passenger* OurPassenger = this->find_passenger(Username);
		if(!OurPassenger->can_rate())
			throw BadException("You don't have any trip for rating!\n");

		OurPassenger->rate_last_trip_driver(AllRate,SystemDate);
		return "You rate succesfully!\n";

	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: charge_account(string Username, int Credit)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again!\n");
		if(!this->passenger_exist(Username))
			throw BadException("You are not a passenger!\n");

		Passenger* OurPassenger = this->find_passenger(Username);
		OurPassenger->inc_credit(Credit);
		return "You charge your account succesfully!\n";

	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: get_credit(string Username)
{
	try{
		if(!this->does_it_loged_in(Username))
			throw BadException("Please login and then try again!\n");
		if(!this->passenger_exist(Username))
			throw BadException("You are not a passenger!\n");

		Passenger* OurPassenger = this->find_passenger(Username);
		return OurPassenger->print_credit();

	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: set_time(int Day, int Hour, int Minute, int Second)
{
	try{
		if(!this->does_it_loged_in(ourAdmin.get_username()))
			throw BadException("Admin doesnt loged in!\n");

		Date tempDate;
		tempDate.set_date(Day, Hour, Minute, Second);
		this->settle_with_drivers(tempDate);
		
		SystemDate.set_date(Day, Hour, Minute, Second);
		return "Time seted succesfully!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
void SpaceTaxi:: settle_with_drivers(Date SecondDate)
{
	for(int i=0; i<RegisteredDrivers.size(); i++)
	{
		RegisteredDrivers[i]->settle(SystemDate, SecondDate, ourAdmin);
	}
}
bool SpaceTaxi:: check_time(int Day, int Hour, int Minute, int Second)
{
	if(Day < 1 || Day > 31 )
		return false;
	if(Hour < 0 || Hour > 23)
		return false;
	if(Minute < 0 || Minute > 59)
		return false;
	if(Second < 0 || Second > 59)
		return false;
	return true;
}
string SpaceTaxi:: driver_report(string DriverUsername, Date FirstDate, Date SecondDate)
{
	try{
		if(!this->does_it_loged_in(ourAdmin.get_username()))
			throw BadException("Admin doesnt loged in!\n");
		Driver* OurDriver = this->find_driver(DriverUsername);
		return OurDriver->driver_report(FirstDate, SecondDate);
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}

string SpaceTaxi:: passenger_report(string PassengerUsername)
{
	try{
		if(!this->does_it_loged_in(ourAdmin.get_username()))
			throw BadException("Admin doesnt loged in!\n");
		Passenger* OurPassenger = this->find_passenger(PassengerUsername);
		return OurPassenger->print_credit();

	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
}
string SpaceTaxi:: usual_system_report()
{
	int DriversCount = RegisteredDrivers.size();
	int PassengersCount = RegisteredPassengers.size();
	int TripsCount = 0;
	for(int i=0; i<RegisteredPassengers.size(); i++)
	{
		TripsCount += RegisteredPassengers[i]->num_of_ended_trips();
	}
	int SystemCredit = ourAdmin.get_credit();

	string ReturnStr = to_string(SystemCredit)+" "+to_string(TripsCount)+" "
		+to_string(DriversCount)+" "+to_string(PassengersCount)+"\n";
	return ReturnStr;
}
string SpaceTaxi:: system_report_by_time(Date FirstDate, Date SecondDate)
{
	int SystemCredit = ourAdmin.get_credit_by_time(FirstDate,SecondDate);
	int TripsCount = 0;
	for(int i=0; i<RegisteredPassengers.size(); i++)
	{
		TripsCount += RegisteredPassengers[i]->get_num_of_trips_by_time(FirstDate,SecondDate);
	}
	int DriversCount=0;
	for(int i=0; i<RegisteredDrivers.size(); i++)
	{
		if(RegisteredDrivers[i]->does_it_registered_between_times(FirstDate,SecondDate))
			DriversCount++;
	}
	int PassengersCount=0;
	for(int i=0; i<RegisteredPassengers.size(); i++)
	{
		if(RegisteredPassengers[i]->does_it_registered_between_times(FirstDate, SecondDate))
			PassengersCount++;
	}
	string ReturnStr = to_string(SystemCredit)+" "+to_string(TripsCount)+" "
		+to_string(DriversCount)+" "+to_string(PassengersCount)+"\n";
	return ReturnStr;
}


