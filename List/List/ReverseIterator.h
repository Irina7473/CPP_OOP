#pragma once
#include "Element.h"

class ReverseIterator
{
	Element* Temp;
public:
	ReverseIterator(Element* temp) : Temp(temp) {};
	~ReverseIterator() {};

	const int& operator*()const { return Temp->Data; }
	int& operator*() { return Temp->Data; }

	ReverseIterator& operator++() //prefix increment
	{
		Temp = Temp->pPrev;
		return *this;
	}
	ReverseIterator operator++(int)//postfix increment
	{
		ReverseIterator old = *this;
		Temp = Temp->pPrev;
		return old;
	}

	ReverseIterator& operator--()
	{
		Temp = Temp->pNext;
		return *this;
	}
	ReverseIterator operator--(int)
	{
		ReverseIterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool operator==(const ReverseIterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const ReverseIterator& other)const
	{
		return !(*this == other);
	}


};

