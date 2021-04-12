#pragma once
#include "CarViolator.h"

//���� ������ �����������-����������� ���
class DBviolators
{
	CarViolator* Root;
public:
	DBviolators() :Root(nullptr) { cout << "DB con" << endl; };
	~DBviolators()
	{
		clear(this->Root);
		cout << "DB de" << endl;
	};
	
	void insert(int namberCar, int data, string location, int article)
	{ insert(namberCar, data, location, article, this->Root);
	cout << "DB ins" << endl;
	}

	CarViolator* search(int namberCar) { return search(namberCar, this->Root); }

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
	void insert(int namberCar, int data, string location, int article, CarViolator* Root)
	{
		CarViolator* existCar = search(namberCar, Root);
		if (existCar) existCar->List->push_front(data, location, article);
		else
		{
			if (!this->Root)
			{
				cout << "ins Root" << endl;
				this->Root = new CarViolator(namberCar);
				this->Root->List->push_front(data, location, article);
			}
			if (!Root) return;
			if (namberCar < Root->NamberCar)
			{
				if (!Root->pLeft)
				{
					Root->pLeft = new CarViolator(namberCar);
					Root->pLeft->List->push_front(data, location, article);
				}
				else insert(namberCar, data, location, article, Root->pLeft);
			}
			else //if (namberCar > Root->NamberCar)
			{
				if (Root->pRight) insert(namberCar, data, location, article, Root->pRight);
				else
				{
					Root->pRight = new CarViolator(namberCar);
					Root->pRight->List->push_front(data, location, article);
				}
			}
		}
	}

	CarViolator* search(int namberCar, CarViolator* Root)
	{
		if (!Root) return nullptr;
		if (Root->NamberCar == namberCar) return Root;
		else (namberCar < Root->NamberCar) ? search(namberCar, Root->pLeft) : search(namberCar, Root->pRight);
	}
		
	void clear(CarViolator* Root)
	{
		if (Root == nullptr) return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	void print(CarViolator* Root)
	{
		if (!Root) return;
		print(Root->pLeft);
		cout << Root->List<<tab<<Root->NamberCar << tab << Root->List->Size << endl;
		//cout<< Root->List->print() << endl;
		print(Root->pRight);
	}
	

	
};

