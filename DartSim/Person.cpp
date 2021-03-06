#include "stdafx.h"

using namespace std;

//Create generic details for undefined Person
Person::Person()
{
	name = "John Doe";
	gender = "Unknown";
	birthYear = 0;
	birthMonth = 0;
	birthYear = 0;
}

//Create person from series of data inputs
Person::Person(string fullName, string mGender, int bYear, int bMonth, int bDate)
{
	name = fullName;
	gender = mGender;
	birthYear = bYear;
	birthMonth = bMonth;
	birthDate = bDate;
	string home = "home";
	//location = home.c_str(); //need to set location here
}

//Create a person given a parsed vector of strings from a file line
Person::Person(vector<string> v) {
	name = v[1];
	gender = v[2];
	birthYear = stoi(v[3], nullptr, 10);
	birthMonth = stoi(v[4], nullptr, 10);
	birthDate = stoi(v[5], nullptr, 10);
	string home = "home";
	//location = home.c_str(); //need to set location here
}


vector<Event>::iterator Person::addEvent(Event &evnt) {
	//Make an iterator for the end of the loop because insert takes an iter
	vector<Event>::iterator it = events.end();
	//Insert the event into the end of the vectors
	events.insert(events.end(), evnt);
	evnt.addPerson(name);
	//return the position 
	return it;
}

vector<Event> Person::getEvents() const
{
	//Return event vector
	return events;
}

void Person::onClock(MasterClock clock)
{
	//Create an iterator and set to start of vector
	vector<Event>::iterator it;
	//for each event in events
	bool found_event = false;
	for (it = events.begin(); it != events.end(); ++it)
	{
		for (DateAndTime dt : it->get_event_times()) {

			if (dt == clock.getDT()) {
				location = it->get_location();
				eventName = it->get_event_name();
				found_event = true;
				currEvent = (*it);
				break;
			}
		}
		if (found_event)
			break;
		else
			location = home;
		eventName = "bed";
	}
}

string Person::getBirthday() const
{
	const string bDay = to_string(birthMonth) + "/" + to_string(birthDate) + "/" + to_string(birthYear);
	return bDay;
}

string Person::getLocation() const
{
	return location;
}

string Person::getName() const
{
	return name;
}

string Person::getGender() const {
	return gender;
}

ostream& operator<<(std::ostream& os, Person pers) {
	os << "Name: " << pers.name << endl;
	os << "Gender: " << pers.gender << endl;
	os << "Birthdate: " << pers.getBirthday() << endl;
	os << "Events: ";
	for (Event vents : pers.events) {
		os << vents;
	}
	os << "Current location: " << pers.location << endl;
	return os;
}

void Person::setName(string n) {
	name = n;
}

void Person::setGender(string g) {
	gender = g;
}

void Person::setBirthday(int y, int m, int d) {
	birthYear = y;
	birthMonth = m;
	birthDate = d;
}

void Person::toString() {
	if (location == home) {
		cout << name << " is currently home" << endl;
	}
	else {
		cout << name << " is currently attending " << eventName << " at " << location << endl;
	}
}

Person::~Person()
{
}
