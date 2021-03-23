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

void Tree::erase(int data)
{
	if (this->Root == nullptr) return;
	Element* temper = Root; //óäàëÿåìûé ýëåìåíò
	Element* temppar = nullptr; // ðîäèòåëü óäàëÿåìîãî ýëåìåíòà
	while (temper && temper->Data != data)
	{
		temppar = temper;
		(data < temper->Data) ? temper = temper->pLeft : temper = temper->pRight;
	}
	if (!temper) return; //íå íàøëè ýëåìåíò
	if (temper->is_leaf())  // ó ýëåìåíòà íåò ïîòîìêîâ
	{
		if (!temppar) Root = nullptr;
		else (temppar->pLeft == temper) ? temppar->pLeft = nullptr : temppar->pRight = nullptr;
	}
	else if (!temper->pLeft) // ó ýëåìåíòà òîëüêî ïðàâûé ïîòîìîê
	{
		if (!temppar) Root = temper->pRight;
		else (temppar->pLeft == temper) ? temppar->pLeft = temper->pRight : temppar->pRight = temper->pRight;
	}
	else if (!temper->pRight) // ó ýëåìåíòà òîëüêî ëåâûé ïîòîìîê
	{
		if (!temppar) Root = temper->pLeft;
		else (temppar->pLeft == temper) ? temppar->pLeft = temper->pLeft : temppar->pRight = temper->pLeft;
	}
	else if (temper->pLeft && temper->pRight) // ó ýëåìåíòà åñòü îáà ïîòîìêà
	{
		{
			if (!temppar) Root = temper->pRight;
			else (temppar->pLeft == temper) ? temppar->pLeft = temper->pRight : temppar->pRight = temper->pRight;
			min(temper->pRight)->pLeft = temper->pLeft;
		}
	}
	delete temper;
}

void Tree::copy(Element* Root)
{
	if (Root == nullptr) return;  //âûõîä èç ïóñòîé âåòêè
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

Element* Tree::search(int data, Element* Root)
{
	if (Root == nullptr) return 0;
	if (Root->Data == data) return Root;
	else (data < Root->Data) ? search(data, Root->pLeft) : search(data, Root->pRight);
}

int Tree::count(Element* Root)
{
	if (Root == nullptr) return 0;
	return (Root->is_leaf()) ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;
	/*if (Root == nullptr)return 0;
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
	cout <<Root<<tab<< Root->Data << endl;
	print(Root->pRight);
}
