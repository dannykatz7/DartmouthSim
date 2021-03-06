#pragma once
class DateAndTime
{
public:
	DateAndTime();
	DateAndTime(int, int);
	~DateAndTime();
	int getDay() const;
	void setDay(int);
	int getHour() const;
	void setHour(int);
	bool operator==(const DateAndTime &other);
private:
	int day; //Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6
	int hour; //24h clock, all events are on an hour so noon is 12, 4pm is 16;
};

