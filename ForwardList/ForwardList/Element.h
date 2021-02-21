#pragma once
#include<iostream>
using namespace std;

class Element
{
	int Data;        //значение элемента
	Element* pNext;  //адрес следующего элемента
	static int count; //кол-во элементов
public:
	const int& getData()const { return Data; }
	int& getData(){ return Data; }
	Element* getpNext()const { return pNext; }
	void setData(int Data) { this->Data =Data; }
	void setpNext(Element* pNext) { this->pNext=pNext; }

	Element(int Data, Element* pNext);
	Element(const Element& other);
	Element(Element&& other);
	~Element();
	
	Element& operator =(const Element& other);
	Element& operator =(Element&& other);
	Element* operator ++();

	friend class List;
	friend class Iterator;
};
