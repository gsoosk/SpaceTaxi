#ifndef PERSON_H
#define PERSON_H
#include "SpaceTaxi.h"
class Person{
public:
	Person(Date RT, std::string user, std::string pass);
 	std::string get_username();
 	bool check_user_and_pass_matched(std::string &user,std::string &pass);
	void inc_credit(int C);
	bool check_user_match(std:: string user);
	bool triping();
	void set_a_new_trip(Trip _Trip);
	virtual void decrease_credit(int C);
	virtual std:: string print_credit();
	int get_credit();
	bool does_it_registered_between_times(Date FirstDate, Date SecondDate);
protected:
	std::string Username;
	std::string Password;
	int credit;
	bool TripStatus;
	std:: vector<Trip> PersonTrips;
	Date RegisterTime;


};
#endif
