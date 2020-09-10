#include "SpaceTaxi.h"
using namespace std;
Passenger:: Passenger(Date RT,std::string user,std::string pass, std::string phone, int code)
		:Person(RT,user,pass),PhoneNumber(phone)
			,PassengerDiscountCode(DISCOUNT_CODE_COUNT,DISCOUNT_CODE_CREDIT,code),DiscountCodeActivation(false)
			,DiscountedCredit(0), AcceptedTrip(NULL), RequestedTrip(NULL), RateStatus(false), Speciality(false){}
std::string Passenger:: get_phone()
{
	return PhoneNumber;
}
string  Passenger:: print_discount_code()
{

	string ReturnStr = to_string(PassengerDiscountCode.get_code()) + " " +
		 to_string(PassengerDiscountCode.get_available_count()) + "\n";
	return ReturnStr;
}
bool Passenger:: does_discount_code_actived()
{
  return DiscountCodeActivation;
}
void Passenger:: active_discount_code()
{
  DiscountCodeActivation=true;
}
bool Passenger:: does_discount_code_usable()
{
  if(PassengerDiscountCode.get_available_count()>0)
    return true;
  return false;
}
void Passenger:: dec_discount_code_count()
{
  --PassengerDiscountCode;
}
bool Passenger:: affort_one_trip(Trip* WantedTrip)
{
	return WantedTrip->does_credit_enough(credit+DiscountedCredit);
}
void Passenger::set_a_new_requested_trip(Trip* RT)
{
	RequestedTrip = RT;
	TripStatus = true;
	RateStatus = true;
}
string Passenger:: cancel_trip_request()
{
	try{
		if(TripStatus==false)
			throw BadException("There is no trip for cancel.\n");
		TripStatus = false;
		RateStatus = false;
		delete(RequestedTrip);
		return "Trip canceled!\n";
	}
	catch(BadException ex)
	{
		return ex.print_Exception();
	}
	
}
bool Passenger:: exist_in_requested_trips(std:: string DriverUser)
{
	
	if(RequestedTrip!=NULL)
	{
		if(RequestedTrip->driver_exist(DriverUser))
			return true	;
	}
	return false;
}
string Passenger:: print_trip_request()
{
	string ReturnStr= "[" + Username + " ";
		ReturnStr += RequestedTrip->print_trip();
	ReturnStr = ReturnStr + "]\n";
	return ReturnStr;
}
Trip* Passenger:: accept_trip()
{
		AcceptedTrip = RequestedTrip ;
		RequestedTrip = NULL ; 
		return AcceptedTrip;
}
bool Passenger:: does_it_have_requested_tirp()
{
	return RequestedTrip!=NULL;
}
string Passenger:: print_last_accepted_trip()
{
	if(AcceptedTrip!=NULL)
		return AcceptedTrip->print_trips_driver_details();
	return "";
}
void Passenger:: inc_discount_credit(int C)
{
	DiscountedCredit+=C;
}
void Passenger:: decrease_credit(int c)
{
	if(DiscountedCredit>=c)
		DiscountedCredit -= c;
	else if(DiscountedCredit<c)
	{
		credit -= (c - DiscountedCredit);
		DiscountedCredit = 0;
	}
}
int Passenger:: real_money(int c)
{
	if(DiscountedCredit>=c)
		return 0;
	else 
	 	return (c - DiscountedCredit);

}
void Passenger:: end_trip()
{
	EndedTrips.push_back(AcceptedTrip);
	AcceptedTrip = NULL;
	TripStatus = false ;
}
bool Passenger:: can_rate()
{
	return RateStatus;
}
void Passenger:: rate_last_trip_driver(int R , Date T)
{
	RateStatus = false;
	EndedTrips[EndedTrips.size() - 1]->rate_driver(R , T);
}
string Passenger:: print_credit()
{
	int temp = credit+DiscountedCredit;
	string ReturnStr = to_string(temp) + "\n";
	return ReturnStr;
}
int Passenger:: num_of_ended_trips()
{
	return EndedTrips.size();
}
int Passenger:: sum_of_space_of_last_n_trip(int N)
{
	long int Space = 0;
	Date tempDate = EndedTrips[EndedTrips.size() - N]-> get_date();
	for(int i= EndedTrips.size() - N + 1 ; i<EndedTrips.size(); i++)
	{
		Date tempDate2 = EndedTrips[i]->get_date();
		Space += tempDate.space_between(tempDate2);
		tempDate = EndedTrips[i]->get_date(); 
	}
	int returnSpace = Space / (24 * 60 * 60);
	return returnSpace;

}
bool Passenger:: get_speciality()
{
	return Speciality;
}
void Passenger:: set_speciality(bool x)
{
	Speciality = x;
}
bool Passenger:: does_it_must_exit_from_speciality(Date SystemDate)
{
	Date tempDate = EndedTrips[EndedTrips.size()-1]->get_date();
	long int Space = tempDate.space_between(SystemDate);
	if(Space/(24*60*60) < MIN_TIME_FOR_EXIT_SPECIAL)
		return false;
	return true;
}
int Passenger:: get_num_of_trips_by_time(Date FirstDate, Date SecondDate)
{
	int Counter=0;
	for(int i=0; i<EndedTrips.size(); i++)
	{
		Date tempDate = EndedTrips[i]->get_date();
		if(tempDate <= SecondDate && tempDate >= FirstDate)
		{
			Counter++;
		}
	}
	return Counter;
}



