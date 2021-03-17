#pragma once
#include<iostream>
using namespace std;

template <typename T> class Element
{
	T Data;
	Element* pPrev;
	Element* pNext;

public:
	Element(T data);
	Element(T data, Element* pPrev, Element* pNext);
	Element(const Element& other);
	Element(Element&& other);
	~Element() { //cout << "EDestructor:\t" << this << endl; 
	};

	Element& operator=(const Element& other);
	Element& operator=(Element&& other);

	template <typename T> friend class Iterator;
	template <typename T> friend class ReverseIterator;
	template <typename T> friend class List;
};

