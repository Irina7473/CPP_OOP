#pragma once
#include<iostream>
using namespace std;

class Element
{
	int Data;
	Element* pPrev;
	Element* pNext;

public:
	Element(int data, Element* pPrev, Element* pNext);
	Element(const Element& other);
	Element(Element&& other);
	~Element() { cout << "EDestructor:\t" << this << endl; };

	Element& operator=(const Element& other);
	Element& operator=(Element&& other);

	friend class Iterator;
	friend class List;
};

