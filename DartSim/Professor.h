#pragma once
#include "Person.h"
#include "stdafx.h"
class Professor :
	public Person
{
public:
	Professor();
	Professor(string, string, int, int, int, string);
	Professor(vector<string>);
	~Professor();
	friend ostream& operator<<(std::ostream& os, const Professor prof);
	string get_Department();
	void set_Department(string);

private:
	string department;
};

