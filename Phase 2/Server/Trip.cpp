#include "SpaceTaxi.h"
using namespace std;
string Trip:: print_cost_and_distance()
{
	string ReturnStr = to_string(Cost)+ " " +to_string(Distance) + "\n";
	return ReturnStr;
}
int Trip:: get_cost()
{return Cost;}
bool Trip:: bad_trip()
{
	if(Cost==COST_ERROR && Distance==DISTANCE_ERROR)
		return true;
	return false;
}
bool Trip:: does_credit_enough(int credit)
{
	if(credit > (Cost- CAN_NEGETIVE_COST))
		return true;
	return false;
}
void Trip:: update_near_drivers(vector<Driver*> FindedDrivers)
{
	for(int i=0; i<FindedDrivers.size(); i++)
		NearDrivers.push_back(FindedDrivers[i]);
}
Trip ::Trip(int cost, int dis, string sourceAddress, vector<string> destinations , Passenger* user, Date TDate)
{
	TripDate = TDate;
	AcceptedBy=NULL;
	Cost=cost;
	Distance=dis;
	Username=user;
	SourceAddress = sourceAddress;
	Destinations = destinations;
}
bool Trip:: driver_exist(std:: string Username)
{
	for(int i=0; i<NearDrivers.size(); i++)
	{
		if(NearDrivers[i]->check_user_match(Username))
			return true;
	}
	return false;
}
string Trip:: print_trip()
{
	string ReturnStr = SourceAddress;
	for(int i=0; i<Destinations.size(); i++)
		ReturnStr = ReturnStr + " " + Destinations[i];
	ReturnStr = ReturnStr +" "+ to_string(Cost) +" "+ to_string(Distance);
	return ReturnStr;
}
void Trip:: accepted_by(Driver* D)
{
	AcceptedBy = D;
}
string Trip:: print_trips_driver_details()
{
	return AcceptedBy->print2();
}
string Trip:: get_last_destination()
{
	return Destinations[Destinations.size() - 1];
}
void Trip:: decrease_credit_from_user()
{
	Username->decrease_credit(Cost);
}
int Trip:: real_money()
{
	return Username->real_money(Cost);
}
void Trip:: end_trip_for_passenger()
{
	this->decrease_credit_from_user();
	Username->end_trip();
}
void Trip:: rate_driver(int R , Date T)
{
	AcceptedBy -> inc_Rate(R, T);
}
Date Trip:: get_date()
{
	return TripDate;
}