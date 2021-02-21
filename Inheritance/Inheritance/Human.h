#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string.h>

using namespace std;

class Human
{
	string lastname;
	string firstname;
	int age;
public:
	const string& getlastname()const { return lastname; }
	const string& getfirstname()const { return firstname; }
	int getage()const { return age; }
	void setlastname(const string& lastname) { this->lastname = lastname; }
	void setfirstname(const string& firstname) { this->firstname = firstname; }
	void setage(int age) { this->age = age; }
	//costructors
	Human(const string& lastname, const string& firstname, int age)
	{
		setlastname(lastname);
		setfirstname(firstname);
		setage(age);
		cout << "HConctructor:\t" << this << endl;
	}
	virtual ~Human() { cout << "HDectructor:\t" << this << endl; }

	virtual void print() { cout << lastname << " " << firstname << " " << age << endl; }

};

