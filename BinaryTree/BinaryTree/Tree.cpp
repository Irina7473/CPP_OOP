#include "Tree.h"

Tree::Tree(const initializer_list <int> & tree): Tree()
{
	for (int const* it = tree.begin(); it != tree.end(); it++)
		insert (*it);
	cout << "LIConstructor Tree  " << this << endl;
}

Tree::Tree(Tree&& other) : Tree()
{
	Root = other.Root;
	copy(other.Root);
	other.Root = nullptr;
	cout << "AssConstrucktor Tree  " << this << endl;
}

void Tree::copy(Element* Root)
{
	if (Root == nullptr) return;  //выход из пустой ветки
	insert(Root->Data, this->Root);
	copy(Root->pLeft);
	copy(Root->pRight);
}

void Tree::insert(int Data, Element* Root)
{
	if (this->Root == nullptr) this->Root = new Element(Data);
	if (Root == nullptr) return;
	if (Data < Root->Data)
	{
		if (Root->pLeft == nullptr)
			Root->pLeft = new Element(Data);
		else
			insert(Data, Root->pLeft);
	}
	else if (Data> Root->Data)
	{
		if (Root->pRight) insert(Data, Root->pRight);
		else Root->pRight = new Element(Data);
	}
}

void Tree::clear(Element* Root)
{
	if (Root == nullptr) return;
	clear(Root->pLeft);
	clear(Root->pRight);
	delete Root;
}

int Tree::count(Element* Root)
{
	if (Root == nullptr) return 0;
	return (Root->is_leaf()) ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;

	/*
	if (Root == nullptr)return 0;
	static int s = 0;
	size(Root->pLeft);
	s++;
	size(Root->pRight);
	return s;*/
}

int Tree::sum(Element* Root)
{
	if (Root == nullptr) return 0;
	return (Root->is_leaf()) ? Root->Data : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
}

void Tree::print(Element* Root)
{
	if (Root == nullptr) return;
	print(Root->pLeft);
	cout << Root->Data << tab;
	print(Root->pRight);
}
