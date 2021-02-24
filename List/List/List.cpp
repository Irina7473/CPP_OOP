#include "List.h"

List::List(): Head(nullptr), Tail(nullptr), Size(0)
{cout << "LdefaultConstructor:\t" << this << endl;}

List::List(int size): List()
{
	for (int i = 0; i < size; i++)
		push_front(0);
	cout << "LConstructor:\t" << this << endl;
}

List::~List()
{
	cout << "LDestructor:\t" << this << endl;
}

Element* List::getElement(int ind) const
{
	Element* Temp = Head;
	if (ind <= Size / 2)
		for (int i = 0; i < ind - 1; i++)
			Temp = Temp->pNext;
	else
	{
		Temp = Tail;
		for (int i = 0; i < (Size-ind); i++)
			Temp = Temp->pPrev;
	}
	cout << Temp->Data << endl;
	return Temp;
}

void List::push_front(int data)
{
	Element* Temp = Head;
	Head=new Element(data, nullptr, Head);
	if(Temp!=nullptr)Temp->pPrev = Head;
	else Tail = Head;
	Size++;
}

void List::push_back(int data)
{
	Element* Temp = Tail; 
	Tail= new Element(data, Tail,nullptr);
	if (Temp != nullptr)Temp->pNext = Tail;
	else Head = Tail;
	Size++;
}

void List::insert(int ind, int data)
{
	if (ind == 1) push_front(data);
	else
	{
		Element* Temp = this->getElement(ind);
		Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp->pPrev, Temp);
		Size++;
	}
}

int& List::operator[](const int ind)
{
	if (ind > (Size + 1)) throw exception("Out of range");
	return this->getElement(ind)->Data;
}

void List::print()
{
	Element* Temp = Head;
	for (int i = 0; i < Size; i++)
	{
		cout<< Temp << tab << Temp->Data << tab << Temp->pPrev << tab << Temp->pNext << endl;
		Temp = Temp->pNext;
	}
	cout << "Размер списка " << Size << endl;
	
}

ostream& operator<<(ostream& os, const List list)
{
	for (Iterator it = list.getHead(); it != nullptr; it++)
		os << *it << tab;
	cout << "Размер списка " << list.getSize() << endl;
	return os;
}
