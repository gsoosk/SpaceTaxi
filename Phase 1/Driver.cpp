#include "SpaceTaxi.h"
using namespace std;
Driver:: Driver(Date RT,std::string user, std::string pass, SpaceShip SS, bool vip)
: Person(RT,user,pass), SpaceShipOfDriver(SS)
	, VIP(vip), TripStatus(false), AcceptedTrip(NULL),Income(0){Available=false; Address="";}
void Driver:: set_status(bool x)
{
	Available=x;
}

void Driver:: set_address(std:: string Ad)
{
	Address=Ad;
}

bool Driver:: does_space_ship_match(string SpaceShipNumber)
{
	if(SpaceShipNumber==SpaceShipOfDriver.get_number())
		return true;
	return false;
}
void Driver:: print()
{
	cout<<Username<<" ";
	SpaceShipOfDriver.print();
	if(VIP)
	{
		cout<<" VIP\n";
	}
}
string Driver::  get_address()
{
	return Address;
}
bool Driver:: does_it_VIP()
{
	return VIP;
}
string Driver:: get_galaxy()
{
	return GetGalaxy(Address);

}
int Driver:: make_magic_num(int Distance)
{
	return Distance*10 + AllRates ;
}
void Driver:: change_trip_status()
{
	TripStatus = !TripStatus;
}
bool Driver:: triping()
{
	return TripStatus;
}
void Driver:: change_accepted_trip(Trip* AT)
{
	AcceptedTrip = AT;
}
void Driver:: print2()
{
	cout<<Username<<" "<<Address<<" ";
	SpaceShipOfDriver.print2();
}
bool Driver:: does_it_have_accepted_request()
{
	if(AcceptedTrip == NULL)
		return false;
	return true;
}
void Driver:: arrived()
{
	ArrivedTrip = AcceptedTrip ;
	AcceptedTrip = NULL;
}
bool Driver:: does_it_have_arrived_request()
{
	if(ArrivedTrip == NULL)
		return false;
	return true;
}
Trip* Driver:: end_trip(Admin* OurAdmin, Date SystemDate)
{
	TripStatus = false;

	Address = ArrivedTrip->get_last_destination();

	int Money = ArrivedTrip->real_money();
	OurAdmin->inc_credit(Money);
	OurAdmin->add_money(Money,SystemDate);

	EndedTrips.push_back(ArrivedTrip);
	ArrivedTrip=NULL;
	
	return EndedTrips[EndedTrips.size()-1];
}
void Driver:: inc_Rate(int r, Date T)
{
	Rate newRate (r,T);
	Rates.push_back(newRate);
	AllRates += r;
}
void Driver:: driver_report(Date FirstDate, Date SecondDate)
{
	int Count = 0;
	double Income =0;
	int TotalRate=0;
	for(int i=0; i<EndedTrips.size(); i++)
	{
		Date tempDate = EndedTrips[i]->get_date(); 
		if(tempDate < SecondDate && tempDate > FirstDate)
		{
			Income += EndedTrips[i]->get_cost();
			Count++;
		}
	}
	Income *= DRIVER_INCOME_PERCENTS;
	for(int i=0; i<Rates.size(); i++)
	{
		Date tempDate = Rates[i].get_date();
		if(tempDate < SecondDate && tempDate > FirstDate)
		{
			TotalRate += Rates[i].get_num();
		}
	}
	cout<<Count<<" "<<Income<<" "<<TotalRate<<endl;

}
void Driver:: settle(Date FirstDate, Date SecondDate, Admin &ourAdmin)
{
	double tIncome=0;
	for(int i=0; i<EndedTrips.size(); i++)
	{
		Date tempDate = EndedTrips[i]->get_date(); 
		if(tempDate <= SecondDate && tempDate >= FirstDate)
			tIncome += EndedTrips[i]->get_cost();
	}
	tIncome *= DRIVER_INCOME_PERCENTS;
	Income+=tIncome;
	ourAdmin.decrease_credit((int)tIncome);
	ourAdmin.add_money((int) -tIncome, SecondDate);

}