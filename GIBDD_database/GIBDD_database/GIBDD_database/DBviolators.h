#pragma once
#include "ListViolationsCar.h"

//база данных автомобилей-нарушителей ПДД
class DBviolators
{
	//автомобиль со списком своих нарушений
	class CarViolator
	{
		int NamberCar;
		ListViolationsCar* List;
		CarViolator* pLeft;
		CarViolator* pRight;
	public:

		CarViolator(int namberCar, CarViolator* pleft = nullptr, CarViolator* pright = nullptr) :
			NamberCar(namberCar), pLeft(pLeft), pRight(pRight)
		{
			List = new ListViolationsCar;
		};

		~CarViolator() {};

		bool is_leaf() { return pLeft == pRight; }
		friend class DBviolators;
	}* Root;

public:
	DBviolators() :Root(nullptr) {};
	~DBviolators()	{clear(this->Root);}
	
	void insert(int namberCar, int data, string location, int article)
	{ insert(namberCar, data, location, article, this->Root);}

	CarViolator* search(int namberCar) { return search(namberCar, this->Root); }

	void print() { print(this->Root); }
	
	void print(int namberCar) {	print(this->Root, namberCar); }

	void printViol(int article)	
	{ 
		cout << "Violation - " << article << " found in cars : " << endl;
		printViol(this->Root, article);
		cout << endl;
	}
	
private:
	void insert(int namberCar, int data, string location, int article, CarViolator* Root)
	{
		CarViolator* existCar = search(namberCar, Root);
		if (existCar) existCar->List->push_front(data, location, article);
		else
		{
			if (!this->Root)
			{				
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
			else 
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

	void print(CarViolator* Root, int namberCar = 0)
	{
		if (!Root) return;
		if (!namberCar)
		{
			print(Root->pLeft);
			cout << "By car - " << Root->NamberCar << "  total violations - " <<Root->List->Size << endl;
			print(Root->pRight);
		}
		else
		{
			if (search(namberCar, Root))
			{
				cout << "By car - " << namberCar << tab;
				search(namberCar, Root)->List->printList();
			}
			else cout << "No violations were found for the car - " << namberCar << endl;
		}

	}
	
	void printViol(CarViolator* Root, int article)
	{ 
		if (!Root) return;
		printViol(Root->pLeft, article);
		if(Root->List->findViol(article)) cout << Root->NamberCar << tab;
		printViol(Root->pRight, article);
	}
	
};

