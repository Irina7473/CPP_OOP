#pragma once
#include "CarViolator.h"

//база данных автомобилей-нарушителей ПДД
class DBviolators
{
	CarViolator* Root;
public:
	DBviolators() :Root(nullptr) { cout << "DBcon" << endl; };
	~DBviolators() { cout << "DBde" << endl; };
	
	void insert(int namberCar, int data, string location, int article)
	{ insert(namberCar, data, location, article, this->Root);
	cout << "DBins" << endl;
	}

	/*
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}*/
	void print()
	{
		print(this->Root);
		cout << endl;
	}
	/*
	void print(int namberCar)
	{
		print(this->Root);
		cout << endl;
	}*/
	
private:
	void insert(int namberCar, int data, string location, int article, CarViolator*& root)
	{
		//if (!root) return;
		if (!this->Root) 
		{
			cout << "ins Root" << endl;
			this->Root = new CarViolator(namberCar);
			Root->List->push_front(data, location,article);
		}
		//if (namberCar = Root->NamberCar) return;
		//else 
			if (namberCar < Root->NamberCar)
		{
			if (!Root->pLeft)
			{
				Root->pLeft = new CarViolator(namberCar);
				Root->List->push_front(data, location, article);
			}
			else
				insert(namberCar,data,location,article,Root->pLeft);
		}
		else if (namberCar > Root->NamberCar)
		{
			if (Root->pRight) insert(namberCar, data, location, article, Root->pRight);
			else 
			{
				Root->pRight = new CarViolator(namberCar);
				Root->List->push_front(data, location, article);
			}
		}
	}
	/*
	void clear(CarViolator* Root)
	{
		if (Root == nullptr) return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}*/

	void print(CarViolator* Root)
	{
		if (!Root) return;
		print(Root->pLeft);
		cout << Root->List<<tab<<Root->NamberCar << tab << Root->List->Size << endl;
		//cout<< Root->List->print() << endl;
		print(Root->pRight);
	}
	

	
};

