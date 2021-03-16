#include "List.h"

List::List(): Head(nullptr), Tail(nullptr), Size(0)
{//cout << "LdefaultConstructor:\t" << this << endl;
}

List::List(int size): List()
{
	//while (size--)push_back(0);
	for (int i = 0; i < size; i++)
		push_back(0);
	//cout << "LConstructor:\t" << this << endl;
}

List::List(const initializer_list<int> &list): List()
{
	for (int const* it = list.begin(); it != list.end(); it++)
		push_back(*it);
	//cout << "LinitConstructor:\t" << this << endl;
}

List::List(const List& other): List()
{
	for (Iterator it = other.Head; it != nullptr; it++)
		push_back(*it);
	//cout << "LcopyConstructor:\t" << this << endl;
}

List::List(List&& other):
	Head(other.Head), Tail(other.Tail), Size(other.Size)
{
	other.Head = nullptr;
	other.Tail = nullptr;
	//cout << "LmoveConstructor:\t" << this << endl;
}

List::~List()
{
	while (Tail) pop_back();
	//cout << "LDestructor:\t" << this << endl;
}

Element* List::getElement(int ind) const
{
	Element* Temp;
	if (ind <= Size / 2)
	{
		Temp = Head;
		for (int i = 0; i < ind - 1; i++)
			Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < (Size-ind); i++)
			Temp = Temp->pPrev;
	}
	return Temp;
}

void List::push_front(int data)
{
	if (empty())
		Head = Tail = new Element(data, nullptr, nullptr);
	else Head = Head->pPrev = new Element(data, nullptr, Head);
	Size++;
}

void List::push_back(int data)
{
	if(empty())
		Head=Tail= new Element(data, nullptr, nullptr);
	else Tail = Tail->pNext=new Element(data, Tail,nullptr);
	Size++;
}

void List::insert(int ind, int data)
{
	if (ind<=0 || ind > Size+1) return;
	if (empty() || ind == 1)
	{
		push_front(data);
		return;
	}
	if (ind == Size + 1) push_back(data);
	   else
	{
		Element* Temp = this->getElement(ind);
		Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp->pPrev, Temp);
		Size++;
	}
}

void List::pop_front()
{
	if (Head)
	{
		Element* Temp = Head;
		if (Temp->pNext)
		{
			Head = Head->pNext;
			Head->pPrev = nullptr;
		}
		else Head = Tail = nullptr;
		delete Temp;
		Size--;
	}
}

void List::pop_back()
{
	if (Tail)
	{
		Element* Temp = Tail;
		if (Temp->pPrev )
		{
			Tail = Tail->pPrev;
			Tail->pNext = nullptr;
		}
		else Head = Tail=nullptr;
		delete Temp;
		Size--;
	}
}

void List::erase(int ind)
{
	if (ind == 1) pop_front();
	else if (ind == Size) pop_back();
	else
	{
		Element* Temp = this->getElement(ind);
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		Size--;
	}
}

int& List::operator[](const int ind)
{
	if (ind<0 || ind > Size) throw exception("Out of range");
	return this->getElement(ind)->Data;
}

List& List::operator=(const List& other)
{
	if (this != &other)
	{
		while (Head) pop_front();
		for (Iterator it = other.Head; it != nullptr; it++)
			push_back(*it);
	}
	//cout << "LCopyAssignment " << this << endl;
	return *this;
}

List& List::operator=(List&& other)
{
	while (Head) pop_front();
	Size = other.Size;
	Head = other.Head;
	Tail = other.Tail;
	other.Head = nullptr;
	other.Tail=nullptr;
	//cout << "LMoveAssignment " << this << endl;
	return *this;
}

void List::print()const
{
	for (Element* Temp = Head; Temp!=nullptr; Temp=Temp->pNext)
		cout<< Temp << tab << Temp->Data << tab << Temp->pPrev << tab << Temp->pNext << endl;
	cout << "Размер списка " << Size << endl;
	
}
void List::print_reverse()const
{
	/*
	for (Element* Temp = Tail; Temp; Temp=Temp->pPrev)
		cout << Temp << tab << Temp->Data << tab << Temp->pPrev << tab << Temp->pNext << endl;*/
	
	for (ReverseIterator it = Tail; it != nullptr; it++)
		cout << *it << tab;
	cout << "Размер списка " << Size << endl;


}

bool List::empty() const
{
	return Head==nullptr && Tail==nullptr;
}

ostream& operator<<(ostream& os, const List& list)
{
	for (Iterator it = list.getHead(); it != nullptr; it++)
		os << *it << tab;
	cout << "Размер списка " << list.getSize() << endl;
	return os;
}

List operator+(const List& left, const List& right)
{
	List result(left);
	for (Iterator it = right.getHead(); it != nullptr; it++)
		result.push_back(*it);
	return result;
}
