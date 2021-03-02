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
	const Iterator begin()const { return Head; }
	Iterator begin() { return Head; }
	const Iterator end()const { return Tail; }
	Iterator end() { return Tail; }

	List();
	explicit List(int size);
	List(const initializer_list<int> list);
	List(const List& other);
	List(List&& other);
	~List();

	Element* getHead()const { return Head; };
	int getSize()const { return Size; };
	Element* getElement(int ind)const;

	void push_front(int data);
	void push_back(int data);
	void insert(int ind, int data);
	void pop_front();	
	void pop_back();	
	void erase(int ind);

	int& operator[](const int ind);
	List& operator =(const List& other);
	List& operator =( List&& other);

	void print();
	
};

ostream& operator <<(ostream& os, const List& list);
List operator +(const List& left, const List& right);