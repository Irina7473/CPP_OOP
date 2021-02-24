#pragma once
#include "Element.h"
#include "Iterator.h"
#define tab "\t"

class List
{
	Element* Head;
	Element* Tail;
	int Size;
public:
	
	List();
	List(int size);
	~List();

	Element* getHead()const { return Head; };
	int getSize()const { return Size; };
	Element* getElement(int ind)const;

	void push_front(int data);
	void push_back(int data);
	void insert(int ind, int data);

	int& operator[](const int ind);

	void print();
	
};

ostream& operator <<(ostream& os, const List list);

