#include "stdafx.h"
#include "DateAndTime.h"


DateAndTime::DateAndTime()
{
}

DateAndTime::DateAndTime(int d, int t)
{
	day = d;
	hour = t;
}

DateAndTime::~DateAndTime()
{
}

int DateAndTime::getDay() const
{
	return day;
}

void DateAndTime::setDay(int day1) {
	day = day1;
}

int DateAndTime::getHour() const
{
	return hour;
}

void DateAndTime::setHour(int hour1) {
	hour = hour1;
}

bool DateAndTime::operator==(const DateAndTime & other)
{
	if (this->getDay() == other.getDay() && this->getHour() == other.getHour()) {
		return true;
	}
	else
		return false;
}
