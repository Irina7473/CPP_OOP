#pragma once
#include<iostream>
#include<cstring>
#define tab "    "

using namespace std;
//Конкретное нарушение автомобиля
class Violation
{
	int Data;  //дата нарушения
	string Location;  //место нарушения
	int Article;  //статья КоАП
	Violation* pPrev;
	Violation* pNext;
public:
	int getData() { return Data; }
	string getLocation() { return Location; }
	int getArticle() { return Article; }
	Violation* getpPrev() { return pPrev; }

	Violation(int data, string location, int article, Violation* pPrev = nullptr, Violation* pNext = nullptr) :
		Data(data), Location(location), Article(article), pPrev (pPrev), pNext(pNext)
	{
		cout << this<<tab<< article << endl;
	};
	~Violation() {};

	/*
	Violation(const Violation& other) :
		Data(other.Data), Location(other.Location), Article(other.Article), pPrev(other.pPrev), pNext(other.pNext) {};
	Violation& operator=(const Violation& other)
	{
		if (this != &other)
		{
			Data = other.Data;
			Location = other.Location;
			Article = other.Article;
			pPrev = other.pPrev;
			pNext = other.pNext;
		}
		return *this;
	}*/

	friend class ListViolationsCar;
};

