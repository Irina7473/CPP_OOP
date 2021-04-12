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
	ListViolationsCar():Head(nullptr), Tail(nullptr), Size(0){ cout << "LVC con "<<this << endl; };
	~ListViolationsCar() 
	{ while (Tail) pop_back(); cout << "LVC de" << endl;};

	void push_front(/*ListViolationsCar& list,*/ int data, string location, int article)
	{
		if (empty())
			Head = Tail = new Violation(data, location, article);
		else Head = Head->pPrev = new Violation(data, location, article, nullptr, Head);
		Size++;
		cout <<this<<tab<< "Size " <<Size<<tab<<article<< endl;
	}

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

	bool empty() const {return Head == nullptr && Tail == nullptr;}
	void print()const
	{
		for (Violation* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
		{
			cout << Temp << tab << "Data - " << Temp->Data << tab;
			cout << "Location - " << Temp->Location << tab;
			cout << "Article - " << Temp->Article << endl;
		}
			cout << "Total violations by car - " << Size << endl;

	}
	/*
	friend ostream& operator<<(ostream& os, const ListViolationsCar& list)
	{
		for (Violation* Temp = list.Head; Temp != nullptr; Temp = Temp->getpPrev())
			os << "Data - " << Temp->getData() << tab << "Location - " << Temp->getLocation() << tab 
			<< "Article - " << Temp->getArticle() << endl << "Total violations by car - " << list.Size << endl;
		return os;
	}*/

	friend class DBviolators;
};



/*
void print_reverse()const
{
	for (ReverseIterator it = Tail; it != nullptr; it++)
		cout << *it << tab;
	cout << "Ðàçìåð ñïèñêà " << Size << endl;
}

ostream& operator<<(ostream& os, const List& list)
{
	for (Iterator it = list.getHead(); it != nullptr; it++)
		os << *it << tab;
	cout << "Ðàçìåð ñïèñêà " << list.getSize() << endl;
	return os;
}
*/
