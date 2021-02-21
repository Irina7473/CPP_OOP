#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string.h>
#include "Human.h"

using namespace std;

class Teacher :public Human
{
	string specialty;
	int experience;
public:
	const string& getspecialty()const { return specialty; }
	int getexperience()const { return experience; }
	void setspecialty(const string& specialty) { this->specialty = specialty; }
	void setexperience(int experience) { this->experience = experience; }
	//costructors
	Teacher(const string& lastname, const string& firstname, int age, 
		const string& specialty, int experience):
		Human(lastname, firstname, age)
	{
		setspecialty(specialty);
		setexperience(experience);
		cout << "TConctructor:\t" << this << endl;
	}
	~Teacher() { cout << "TDectructor:\t" << this << endl; }

	void print()
	{
		Human::print();
		cout << specialty << " " << experience << endl;
	}
};

