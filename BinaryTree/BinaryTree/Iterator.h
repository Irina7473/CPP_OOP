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
		Temp = Temp->pLeft;
		return *this;
	}

};

