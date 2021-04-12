#pragma once
#include<iostream>
#include<cstring>
#define tab "    "
#define sec "----------------------------------------- \n"


using namespace std;
//���������� ��������� ����������
class Violation
{
	int Data;  //���� ���������
	string Location;  //����� ���������
	int Article;  //������ ����
	Violation* pPrev;
	Violation* pNext;
public:
	//int getData() { return Data; }
	//string getLocation() { return Location; }
	//int getArticle() { return Article; }
	//Violation* getpPrev() { return pPrev; }
	//Violation* getpNext() { return pNext; }

	Violation(int data, string location, int article, Violation* pPrev = nullptr, Violation* pNext = nullptr) :
		Data(data), Location(location), Article(article), pPrev (pPrev), pNext(pNext) {};
	~Violation() {};
	
	friend class ListViolationsCar;
};

