#include "SpaceTaxi.h"
using namespace std;
Person:: Person(Date RT, std::string user, std::string pass)
:RegisterTime(RT), Username(user), Password(pass)
		, credit(0), TripStatus(false){};

std::string Person:: get_username()
{
	return Username;
}
bool Person:: check_user_and_pass_matched(string &user,string &pass)
{
	if(Username==user && Password==pass)
		return true;
	return false;
}
void Person:: inc_credit(int C)
{
	credit+=C;
}
bool Person:: check_user_match(string user)
{
	if(user==Username)
		return true;
	return false;
}
bool Person:: triping()
{
	return TripStatus;
}
void Person:: set_a_new_trip(Trip _Trip)
{
	PersonTrips.push_back(_Trip);
	TripStatus = true;
}
void Person:: decrease_credit(int C)
{
	credit-=C;
}
string Person:: print_credit()
{
	string ReturnStr = to_string(credit) + "\n";
	return ReturnStr;
}
int Person:: get_credit()
{
	return credit;
}
bool Person:: does_it_registered_between_times(Date FirstDate, Date SecondDate)
{
	if(RegisterTime <= SecondDate && RegisterTime >= FirstDate)
		return true;
	return false;
}