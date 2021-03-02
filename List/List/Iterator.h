#pragma once
#include "Element.h"

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* temp) : Temp(temp) {};
	~Iterator() {};

	const int& operator*()const {return Temp->Data;}
	int& operator*() {return Temp->Data;}

	Iterator& operator++() 
	{
		Temp = Temp->pNext;
		return *this; 
	}
	Iterator& operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	Iterator& operator--()
	{
		Temp = Temp->pPrev;
		return *this;
	}
	Iterator& operator--(int)
	{
		Iterator old = *this;
		Temp = Temp->pPrev;
		return old;
	}

	bool operator==(const Iterator& other)const
	{return this->Temp == other.Temp;}
	bool operator!=(const Iterator& other)const
	{return !(this->Temp == other.Temp);}

};

