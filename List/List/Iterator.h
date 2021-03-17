#pragma once
#include "Element.h"

template <typename T> class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* temp) : Temp(temp) {};
	~Iterator() {};

	const T& operator*()const {return Temp->Data;}
	T& operator*() {return Temp->Data;}

	Iterator& operator++() //prefix increment
	{
		Temp = Temp->pNext;
		return *this; 
	}
	Iterator operator++(int)//postfix increment
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
	Iterator operator--(int)
	{
		Iterator old = *this;
		Temp = Temp->pPrev;
		return old;
	}

	bool operator==(const Iterator& other)const
	{return this->Temp == other.Temp;}
	bool operator!=(const Iterator& other)const
	{return !(*this == other);}

};

