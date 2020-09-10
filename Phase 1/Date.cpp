#include "SpaceTaxi.h"
using namespace std;
Date :: Date()
{
	Day = 1;
	Hour = 0;
	Minute = 0;
	Second = 0;
}
void Date:: set_date(int day, int hour, int minute, int second)
{
	Day = day;
	Hour = hour;
	Minute = minute;
	Second = second;
}
int Date:: space_between(Date& AnotherDate)
{
	// suppose that AnotherDate is bigger than *this
	int D = (AnotherDate.Day - Day) * 24 * 60 * 60 ;
	int H = (AnotherDate.Hour - Hour) * 60 * 60 ;
	int M = (AnotherDate.Minute - Minute) * 60;
	int S = (AnotherDate.Second - Second) ;
	return D + H + M + S ;
}
Date:: Date(string CommandLine)
{
	Day = atoi(GetSubStrFromLine(CommandLine,'-').c_str());
	Hour = atoi(GetSubStrFromLine(CommandLine,':').c_str());
	Minute = atoi(GetSubStrFromLine(CommandLine,':').c_str());
	Second = atoi(GetSubStrFromLine(CommandLine,' ').c_str());
}
bool Date:: operator< (Date& AnotherDate)
{
	if(Day < AnotherDate.Day)
		return true;
	else if (Day == AnotherDate.Day)
	{
		if(Hour < AnotherDate.Hour)
			return true;
		else if(Hour == AnotherDate.Hour)
		{
			if(Minute<AnotherDate.Minute)
				return true;
			else if(Minute == AnotherDate.Minute)
			{
				if(Second < AnotherDate.Second)
					return true;
				else 
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	else 
		return false;

}
bool Date:: operator> (Date& AnotherDate)
{
	if(Day > AnotherDate.Day)
		return true;
	else if (Day == AnotherDate.Day)
	{
		if(Hour > AnotherDate.Hour)
			return true;
		else if(Hour == AnotherDate.Hour)
		{
			if(Minute>AnotherDate.Minute)
				return true;
			else if(Minute == AnotherDate.Minute)
			{
				if(Second > AnotherDate.Second)
					return true;
				else 
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	else 
		return false;

}
bool Date:: operator<= (Date& AnotherDate)
{
	if(Day < AnotherDate.Day)
		return true;
	else if (Day == AnotherDate.Day)
	{
		if(Hour < AnotherDate.Hour)
			return true;
		else if(Hour == AnotherDate.Hour)
		{
			if(Minute<AnotherDate.Minute)
				return true;
			else if(Minute == AnotherDate.Minute)
			{
				if(Second < AnotherDate.Second)
					return true;
				else if(Second== AnotherDate.Second)
					return true;
				else
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	else 
		return false;

}
bool Date:: operator>= (Date& AnotherDate)
{
	if(Day > AnotherDate.Day)
		return true;
	else if (Day == AnotherDate.Day)
	{
		if(Hour > AnotherDate.Hour)
			return true;
		else if(Hour == AnotherDate.Hour)
		{
			if(Minute>AnotherDate.Minute)
				return true;
			else if(Minute == AnotherDate.Minute)
			{
				if(Second > AnotherDate.Second)
					return true;
				else if(Second == AnotherDate.Second)
					return true;
				else
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	else 
		return false;

}
bool Date:: day_changed(int D)
{
	return D != Day;
}