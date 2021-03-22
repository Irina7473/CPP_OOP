#pragma once
#include "Element.h"

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* temp) : Temp(temp) {};
	~Iterator() {};

	const int& operator*()const { return Temp->Data; };
	int& operator*() { return Temp->Data; };

	Iterator& operator ++()
	{
		(Temp)? Temp = Temp->pLeft : Temp = Temp->pRight;
		return *this;
	}
	Iterator operator ++(int)
	{
		Iterator old = *this;
		(Temp) ? Temp = Temp->pLeft : Temp = Temp->pRight;
		return old;
	}

	bool operator==(const Iterator& other)const
	{return this->Temp == other.Temp;}
	bool operator!=(const Iterator& other)const
	{return !(*this == other);}

};

