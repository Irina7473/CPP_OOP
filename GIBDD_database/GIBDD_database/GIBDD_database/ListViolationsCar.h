#pragma once
#include<iostream>
#include<cstring>
#define tab "    "
#define sec "----------------------------------------- \n"

using namespace std;

//Конкретное нарушение автомобиля
class Violation
{
	int Data;  //дата нарушения
	string Location;  //место нарушения
	int Article;  //статья КоАП
	Violation* pPrev;
	Violation* pNext;
public:
	Violation(int data, string location, int article, Violation* pPrev = nullptr, Violation* pNext = nullptr) :
		Data(data), Location(location), Article(article), pPrev(pPrev), pNext(pNext) {};
	~Violation() {};
	friend class ListViolationsCar;
};

//Лист нарушений конкретного автомобиля
class ListViolationsCar
{
	Violation* Head;
	Violation* Tail;
	int Size;
public:
	ListViolationsCar():Head(nullptr), Tail(nullptr), Size(0) {};
	~ListViolationsCar() { while (Tail) pop_back(); };

	void push_front(int data, string location, int article)
	{
		if (empty())
			Head = Tail = new Violation(data, location, article);
		else Head = Head->pPrev = new Violation(data, location, article, nullptr, Head);
		Size++;
	}
	
	bool empty() const {return Head == nullptr && Tail == nullptr;}

	bool findViol(int article)
	{
		for (Violation* Temp = Head; Temp != nullptr; Temp=Temp->pNext)
			if (Temp->Article== article) return true;
		return false;
	}

	void printList()const
	{
		cout << "Total violations - " << Size << endl;
		cout << "|    Data    |" << "  Location  |" << "  Article  |" << endl;
		cout << sec;
		for (Violation* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
			cout << tab << Temp->Data << tab<< Temp->Location << tab << tab << Temp->Article << endl;
	}

private:
	void pop_back()
	{
		if (Tail)
		{
			Violation* Temp = Tail;
			if (Temp->pPrev)
			{
				Tail = Tail->pPrev;
				Tail->pNext = nullptr;
			}
			else Head = Tail = nullptr;
			delete Temp;
			Size--;
		}
	}

	friend class DBviolators;
};
