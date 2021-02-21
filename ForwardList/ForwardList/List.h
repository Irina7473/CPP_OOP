#pragma once
#include "Element.h"
#include "Iterator.h"

#define tab "\t"

class List
{
	Element* Head;  //��������� �� ��������� ������� ������
	int size;
public:
	const Iterator begin()const { return Head; }
	Iterator begin() { return Head; }
	const Iterator end()const { return nullptr; }
	Iterator end() { return nullptr; }

	List();	
	explicit List(int size);
	List(const initializer_list<int> list); //����������� �� ����������
	List(const List& other);
	List(List&& other);
	~List();
	
	Element* getHead()const { return Head; }
	Element* getElement(int ind)const;  //����� �������� �� �������
	Element* search_data_list(int data)const;  //����� �������� �� ��������
	//int lengthList();  //���������� ����� ������
	void push_front(int Data); //���������� �������� � ������ ������
	void push_back(int Data); //���������� �������� � ����� ������
	void insert(int ind, int Data); //���������� �������� �� �������

	void pop_front();	//������� ��������� ������� ������
	void pop_back();	//������� ��������� ������� ������
	void erase(int ind);	//������� �������� �� ������ �� ���������� �������
	
	void print();
	
	List& operator =(const List& other);
	List& operator =(List&& other);
	int& operator[](const int ind);
	
		
};
ostream& operator<<(ostream& os, const List& list);
List operator +(const List& left, const List& right);

