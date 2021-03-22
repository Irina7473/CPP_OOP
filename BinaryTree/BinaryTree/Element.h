#pragma once
#include<iostream>
using namespace std;

#define tab "\t"
//#define DEBUG

class Element
{
	int Data;
	Element* pLeft, * pRight;
public:
	Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
		Data(Data), pLeft(pLeft), pRight(pRight) {
#ifdef DEBUG
		cout << "EConstrucktor" << endl;
#endif DEBUG
	};
	~Element() {
#ifdef DEBUG
		//cout << "EDestrucktor" << endl;
#endif DEBUG
	};

	bool is_leaf() { return pLeft == pRight; }
	friend class Tree;
	friend class Iterator;
};