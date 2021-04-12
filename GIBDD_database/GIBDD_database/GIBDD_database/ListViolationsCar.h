#pragma once
#include "Violation.h"
//Лист нарушений конкретного автомобиля
class ListViolationsCar
{
	Violation* Head;
	Violation* Tail;
	int Size;
public:
	Violation* getHead() { return Head; }
	ListViolationsCar():Head(nullptr), Tail(nullptr), Size(0)
	{ cout << "LVC con "<<this << endl; };
	~ListViolationsCar() 
	{ while (Tail) pop_back(); cout << "LVC de" << endl;};

	void push_front(int data, string location, int article)
	{
		if (empty())
			Head = Tail = new Violation(data, location, article);
		else Head = Head->pPrev = new Violation(data, location, article, nullptr, Head);
		Size++;
	}
	
	bool empty() const {return Head == nullptr && Tail == nullptr;}
	void print()const
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
