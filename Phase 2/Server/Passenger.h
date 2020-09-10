#ifndef PASSENGER_H
#define PASSENGER_H
#include "SpaceTaxi.h"
class Passenger : public Person{

public:
	Passenger(Date RT,std::string user,std::string pass, std::string phone, int code);
	std:: string get_phone();
	std:: string print_discount_code();
	bool does_discount_code_actived();
	void active_discount_code();
	bool does_discount_code_usable();
	void dec_discount_code_count();
	bool affort_one_trip(Trip* WantedTrip);
	void set_a_new_requested_trip(Trip* RT);
	std:: string cancel_trip_request();
	bool exist_in_requested_trips(std:: string DriverUser);
	std:: string print_trip_request();
	Trip* accept_trip();
	bool does_it_have_requested_tirp();
	std:: string print_last_accepted_trip();
	void inc_discount_credit(int c);
	void decrease_credit(int c);
	int real_money(int c);
	void end_trip();
	bool can_rate();
	void rate_last_trip_driver(int R , Date T);
	std:: string print_credit();
	int num_of_ended_trips();
	int sum_of_space_of_last_n_trip(int N);
	bool get_speciality();
	void set_speciality(bool x);
	bool does_it_must_exit_from_speciality(Date SystemDate);
	int get_num_of_trips_by_time(Date FirstDate, Date SecondDate);
private:
	std::string PhoneNumber;
	DiscountCode PassengerDiscountCode;
	bool DiscountCodeActivation;
	int DiscountedCredit;
	Trip* RequestedTrip;
	Trip* AcceptedTrip;
	std:: vector<Trip*> EndedTrips;
	bool RateStatus;
	bool Speciality;


};
#endif
