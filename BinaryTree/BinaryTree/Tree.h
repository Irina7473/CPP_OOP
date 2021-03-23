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
	void erase(int data);

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

	Element* min(Element* Root) { return (Root->pLeft) ? min (Root->pLeft) : Root; }
	Element* max(Element* Root) { return (Root->pRight) ? max(Root->pRight) : Root; }
	int minValue(Element* Root) {return (Root->pLeft ) ? minValue(Root->pLeft) : Root->Data;}
	int maxValue(Element* Root) {return (Root->pRight) ? maxValue(Root->pRight) : Root->Data;}
	int count(Element* Root);
	int sum(Element* Root);
	void print(Element* Root);
		
};

/*

class tree_elem
{
 public:
	 int m_data;
	 tree_elem * m_left;
	 tree_elem * m_right;
	 tree_elem(int val)
	 {
		 m_left = NULL; // В С++11 лучше использовать nullptr
		 m_right = NULL;
		 m_data = val;
	 }
};
class binary_tree
{
 private:
	tree_elem * m_root;
	int m_size;
	void print_tree(tree_elem *);
	void delete_tree(tree_elem *);

 public:
	binary_tree(int);
	~binary_tree();
	void print();
	bool find(int);
	void insert(int);
	void erase(int);
	int size();
};

Удаление элемента из дерева - наиболее сложный из методов. Сначала найдем элемент, который нужно удалить (указатель curr), 
указатель parent указывает на его предка.
Если у curr нет левого поддерева (условие curr->m_left == NULL), то вместо curr можно подвесить его правое поддерево целиком, 
то есть элемент curr удаляется, а на его место становится его правое поддерево curr->m_right.
Аналогично, если у curr нет правого поддерева, то вместо него можно подвесить целиком левое поддерево.
Самый сложный случай - если у curr есть и левое, и правое поддерево. В этом случае на место элемента curr поставим наименьший элемент, 
который больше него. Для этого нужно спуститься в правое поддерево элемента curr, 
и в этом поддереве найти наименьший элемент - для этого будем двигаться указателем всегда в левого потомка текущего элемента, 
пока не найдем элемент, у которого нет левого потомка. 
Этот элемент можно удалить той же самой процедурой (т.к. у него нет левого потомка, то это простой случай удаления), 
а его значение записать на место элемента curr.

void binary_tree::erase(int key)
{
	tree_elem * curr = m_root;
	tree_elem * parent = NULL;
	while (curr && curr->m_data != key)
	{
		parent = curr;
		if (curr->m_data > key)
		{
			curr = curr->m_left;
		}
		else
		{
			curr = curr->m_right;
		}
	}


	if (!curr)
		return;
	if (curr->m_left == NULL)
	{
		// Вместо curr подвешивается его правое поддерево
		if (parent && parent->m_left == curr)
			parent->m_left = curr->m_right;
		if (parent && parent->m_right == curr)
			parent->m_right = curr->m_right;
		--m_size;
		delete curr;
		return;
	}
	if (curr->m_right == NULL)
	{
		// Вместо curr подвешивается его левое поддерево
		if (parent && parent->m_left == curr)
			parent->m_left = curr->m_left;
		if (parent && parent->m_right == curr)
			parent->m_right = curr->m_left;
		--m_size;
		delete curr;
		return;
	}
	// У элемента есть два потомка, тогда на место элемента поставим
	// наименьший элемент из его правого поддерева
	tree_elem * replace = curr->m_right;
	while (replace->m_left)
		replace = replace->m_left;
	int replace_value = replace->m_data;
	erase(replace_value);
	curr->m_data = replace_value;
}



*/