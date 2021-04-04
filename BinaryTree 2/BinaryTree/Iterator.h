#pragma once
#include "Element.h"

template <typename T> class Iterator
{
	Element<T>* Root;
	Element<T>* Temp;
public:
	Iterator(Element<T>* Root, Element<T>* temp=nullptr) : Temp(temp) {};
	~Iterator() {};

	const T& operator*()const { return Temp->Data; };
	T & operator*() { return Temp->Data; };

	bool operator==(const Iterator& other)const
	{return this->Temp == other.Temp;}
	bool operator!=(const Iterator& other)const
	{return !(*this == other);}
	
	/*
	operator Element<T>* ()const
	{	return Temp;}*/

	Element<T>*& operator->()
	{	return Temp;	}


	Iterator& operator ++()
	{
		findnext();
		return *this;
	}


};

