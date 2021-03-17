#pragma once
#include "Element.h"
#include "Iterator.h"
#include "ReverseIterator.h"

#define tab "\t"

template <typename T> class List
{
	Element <T>* Head;
	Element <T>* Tail;
	int Size;
public:
	const Iterator<T> begin()const { return Head; }
	Iterator<T> begin() { return Head; }
	const Iterator<T> end()const { return nullptr; }
	Iterator<T> end() { return nullptr; }
	const ReverseIterator<T> rbegin()const { return Tail; }
	ReverseIterator<T> rbegin() { return Tail; }
	const ReverseIterator<T> rend()const { return nullptr; }
	ReverseIterator<T> rend() { return nullptr; }
	
	List();
	explicit List(int size);
	List(const initializer_list<T>& list);
	List(const List& other);
	List(List&& other);
	~List();

	Element <T>* getHead()const { return Head; };
	int getSize()const { return Size; };
	Element <T>* getElement(int ind)const;

	void push_front(int data);
	void push_back(int data);
	void insert(int ind, int data);
	void pop_front();	
	void pop_back();	
	void erase(int ind);

	T& operator[](const int ind);
	List& operator =(const List& other);
	List& operator =( List&& other);

	bool empty()const;// Проверка наличия элементов в списке

	void print()const;
	void print_reverse()const;
	friend ostream& operator<<(ostream& os, const List& list)
	{
		for (Iterator<T> it = begin(); it != end(); it++)
			os << *it << tab;
		cout << "Размер списка " << list.getSize() << endl;
		return os;
	}
};

template <typename T> List <T> operator +(const List<T>& left, const List<T>& right);