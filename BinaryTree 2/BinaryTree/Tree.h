#pragma once
#include<iostream>
#include "Element.h"
#include "Iterator.h"

template <typename T>  class Tree
{
	Element<T>* Root;
public:
	Iterator<T> begin()
	{
		return find(minValue(this->Root), this->Root);
	}
	Iterator<T> end()
	{
		return find(maxValue(this->Root), this->Root);
	}

	Element<T>*& find(T Data, Element<T>*& Root)
	{
		if (Root == nullptr) return Root;
		find(Data, Root->pLeft);
		find(Data, Root->pRight);
		if (Root->Data == Data) return Root;
	}
	Element<T>*& findnext(Element<T>*& Root, Element<T>*& Paren=nullptr)
	{
		if (Root->pLeft == nullptr) return Root;
		if (Root->pRight) findnext(Root->pRight, Root);
		findnext(Root->pLeft, Root);
	}
	Element<T>*& findnext()
	{

		findnext(this->Root, nullptr);
	}


	Element<T>* getRoot() { return this->Root; }
	//const Iterator<T> begin()const { return Root; }
	//Iterator<T> begin() { return Root; }
	//const Iterator<T> end()const { return nullptr; }
	//Iterator<T> end() { return nullptr; }

	Tree() : Root(nullptr) { cout << "Construcktor Tree  " <<this<<endl; }
	Tree(const initializer_list <T> & tree);
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

	void insert(T Data) {insert(Data, this->Root);}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	Element<T>* search(int data) {return search(data, this->Root);}
	void erase(T data);

	T minValue() 	{return (this->Root) ? minValue(this->Root) : 0;}
	T maxValue() 	{return (this->Root) ? maxValue(this->Root) : 0;}
	T size() 	{return (this->Root) ? count(this->Root) : 0;}
	T sum() {return sum(this->Root);}
	T avg() {return sum(this->Root) / count(this->Root);}
	void print()
	{
		print(this->Root);
		cout << endl;
	}

private:
	void copy(Element<T>* Root);
	void insert(T Data, Element<T>* Root);
	void clear(Element<T>* Root);
	Element<T>* search(T data, Element<T>* Root);

	Element<T>* min(Element<T>* Root) { return (Root->pLeft) ? min (Root->pLeft) : Root; }
	Element<T>* max(Element<T>* Root) { return (Root->pRight) ? max(Root->pRight) : Root; }
	T minValue(Element<T>* Root) {return (Root->pLeft ) ? minValue(Root->pLeft) : Root->Data;}
	T maxValue(Element<T>* Root) {return (Root->pRight) ? maxValue(Root->pRight) : Root->Data;}
	T count(Element<T>* Root);
	T sum(Element<T>* Root);
	void print(Element<T>* Root);
		

	/*
	void erase(T Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
			//return;
		}*/

	



};

#include "Tree.inl"