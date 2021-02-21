#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string.h>
#include "Human.h"

using namespace std;

class Student :public Human
{
	string specialty;
	int year;//год обучения
	int rating;//рейтинг
	int attendance; //посещаемость

public:
	const string& getspecilaty()const { return specialty; }
	int getyear()const { return year; }
	int getrating()const { return rating; }
	int getattendance()const { return attendance; }

	void setspecialty(const string& specialty) { this->specialty = specialty; }
	int setyear(int year) { return this->year = year; }
	int setrating(int rating) { return this->rating = rating; }
	int setattendance(int attendance) { return this->attendance = attendance; }

	//costructors
	Student(const string& lastname, const string& firstname, int age,
		const string& specialty, int year, int rating, int attendance) :
		Human(lastname, firstname, age)
	{

		setspecialty(specialty);
		setyear(year);
		setrating(rating);
		setattendance(attendance);
		cout << "StConctructor:\t" << this << endl;
	}
	~Student() { cout << "StDectructor:\t" << this << endl; }

	void print()
	{
		Human::print();
		cout << year << "-й курс, успеваемость- " << rating << " посещаемость-  " << attendance << endl;
	}



};