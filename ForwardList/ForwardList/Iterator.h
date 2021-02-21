#pragma once
#include "Element.h"

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* temp) :Temp(temp) {}
	~Iterator()	{}

	Iterator& operator++() //prefix
	{
		Temp = Temp->getpNext();
		return *this;
	}
	Iterator operator++(int)//suffix
	{
		Iterator old = *this;
		Temp = Temp->getpNext();
		return old;
	}

	const int& operator *()const
	{return Temp->getData();}
	int& operator *()
	{return Temp->getData();}

	bool operator==(const Iterator& other)const
	{return this->Temp == other.Temp;}
	bool operator!=(const Iterator& other)const
	{return !(*this == other);}

};

