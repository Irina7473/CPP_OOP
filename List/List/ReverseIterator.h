#pragma once
#include "Element.h"

template <typename T> class ReverseIterator
{
	Element<T>* Temp;
public:
	ReverseIterator(Element<T>* temp) : Temp(temp) {};
	~ReverseIterator() {};

	const T& operator*()const { return Temp->Data; }
	T& operator*() { return Temp->Data; }

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

