#pragma once
#include<iostream>
#include "Element.h"
#include "Iterator.h"
using namespace std;

class Tree
{
	Element* Root;
public:
	Element* getRoot() { return this->Root; }
	const Iterator begin()const { return Root; }
	Iterator begin() { return Root; }
	const Iterator end()const { return nullptr; }
	Iterator end() { return nullptr; }

	Tree() : Root(nullptr) { cout << "Construcktor Tree  " <<this<<endl; }
	Tree(const initializer_list <int> & tree);
	Tree(const Tree& other) : Tree()
	{ 
		copy(other.Root);
		cout << "CopyConstrucktor Tree  " <<this<<endl;
	}
	Tree(Tree&& other);
	~Tree() 
	{
		clear();
		cout << "Destrucktor Tree  " <<this<< endl;
	}

	void insert(int Data) {insert(Data, this->Root);}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	Element* search(int data) {return search(data, this->Root);} 
	void erase(int data) 
	{
		Element* temp = search(data, this->Root);
		if (temp) erase(data, search(data, temp));
	}
	int minValue() 	{return (this->Root) ? minValue(this->Root) : 0;}
	int maxValue() 	{return (this->Root) ? maxValue(this->Root) : 0;}
	int size() 	{return (this->Root) ? count(this->Root) : 0;}
	int sum() {return sum(this->Root);}
	double avg() {return (double)sum(this->Root) / count(this->Root);}
	void print()
	{
		print(this->Root);
		cout << endl;
	}

private:
	void copy(Element* Root);
	void insert(int Data, Element* Root);
	void clear(Element* Root);
	Element* search(int data, Element* Root);
	void erase(int data, Element* Root);
	int minValue(Element* Root) {return (Root->pLeft ) ? Root->Data : minValue(Root->pLeft);}
	int maxValue(Element* Root) {return (Root->pRight) ? maxValue(Root->pRight) : Root->Data;}
	int count(Element* Root);
	int sum(Element* Root);
	void print(Element* Root);
		
};

