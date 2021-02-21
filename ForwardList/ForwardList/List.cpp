#include "List.h"

List::List()
{
	Head = nullptr;
	size = 0;
	//cout << "LConstructor:\t" << this << endl;
}

List::List(int size):List()
{while (size--)	push_front(0);}

List::List(const initializer_list<int> il):List()
//����������� �� ����������
{
	for (int const* it = il.begin(); it!=il.end(); it++)
	{
		push_back(*it);
	}
	//size = 0;
	//for (auto& element : list)	this->push_back(element);
}

List::List(const List& other):List()
//����������� �������� ��� ��������
{
	Element* Temp = other.Head;
	while (Temp)
	{
		push_back(Temp->Data);  
		Temp = Temp->pNext;
	}
	//push_back(Temp->getData());
	cout << "LCopyConstructor:\t" << this << endl;
}

List::List(List&& other) : Head(other.Head), size (other.size)
{
	other.Head = nullptr;
	cout << "LMoveConstructor:\t" << this << endl;
}

List::~List() 
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}

Element* List::getElement(int ind)const
//����� �������� �� �������
{
	Element* Temp = Head;
	int i = 1;
	while (i < ind && Temp != NULL)
	{
		Temp = Temp->pNext;
		i++;
	}
	if (Temp == NULL)
		return 0;
	else
		return Temp;
}

Element* List::search_data_list(int data) const
//����� �������� �� ��������
{
	Element* Temp = Head;
	if (Head != nullptr)
	{
		while (Temp->pNext != nullptr)
		{
			if (Temp->Data == data) return Temp;
			Temp = Temp->pNext;
		}
	}
	return Temp;
}
/*
int List::lengthList()
//���������� ����� ������
{
	int length = 0;
	if (Head != nullptr)
	{ 
		Element* Temp = Head;
		while (Temp->pNext != nullptr) 
		{ 
			Temp = Temp->pNext; 
			length++;
		}
	}
	return ++length;
}*/

	void List:: push_front(int Data) 
	//���������� �������� � ������ ������
	{   
		Head = new Element(Data, Head);
		size++;
	}

	void List::push_back(int Data)
		//���������� �������� � ����� ������
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head; 
		while (Temp->pNext != nullptr) { Temp = Temp->pNext; }
		Temp->pNext = new Element(Data,nullptr);
		size++;
	}

	void List:: insert(int ind, int Data) 
		//���������� �������� �� �������
	{
		if (ind > size+1)
		{
			cout << "����� ������� ��������� ������ ������, ������� ����� �� ������, ��� " << (size+1) << endl;
			cin >> ind;
		}
		if (ind == 1) push_front(Data);
		else this->getElement(ind-1)->pNext = new Element(Data, this->getElement(ind-1)->pNext);
		size++;
	}

	void List::pop_front()//������� ��������� ������� ������
	{
		if (Head != nullptr)
		{
			Element* Temp = Head;
			Head = Head->pNext;
			delete Temp;
		}
		size--;
	}

	void List::pop_back()//������� ��������� ������� ������
	{
		if (Head != nullptr)
		{
			Element* Temp = Head;
			while (Temp->pNext->pNext != nullptr)
				Temp = Temp->pNext;
			Temp->pNext->~Element();
			Temp->pNext= nullptr;
		}
		size--;
	}

	void List::erase(int ind)//������� �������� �� ������ �� ���������� �������
	{
		if (ind > size)
		{
			cout << "����� ������� ��������� ������ ������, ������� ����� �� ������, ��� " << size << endl;
			cin>> ind;
		}
		if (ind == 1) pop_front();
		else
		{
			Element* Temper = getElement(ind-1)->pNext;
			getElement(ind-1)->pNext = getElement(ind-1)->pNext->pNext;
			delete Temper;
		}
		size--;
	}

		void List:: print()
	{
		for(Iterator it=Head; it!=nullptr; it++)
			cout << *it << endl;
		cout << "���������� ��������� ������: " << size << endl;
		}
		
	List& List::operator =(const List& other)
{
		if (this != &other)
			{
			
			while (Head)pop_front();
			for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
				push_back(Temp->Data);
			}
		return *this;
	}

	List& List::operator =(List&& other)
	{
		while (Head)pop_front();
		size = other.size;
		Head = other.Head;
		other.Head = nullptr;
		cout << "MoveAssignment " << this << endl;
		return *this;
	}

		int& List:: operator[](const int ind)
	{
		if (ind >= size) throw exception("Out of range");//���������� � ���������� �� ������
		return this->getElement(ind)->Data;
	}

	ostream& operator<<(ostream& os, const List& list)
	{
		Element* Temp = list.getHead();
		while (Temp->getpNext() != nullptr)
		{
			os << Temp->getData() << tab;
			Temp = Temp->getpNext();
		}
		os << Temp->getData() << tab;
		cout << endl;
		return os;
	}
	
	List operator+(const List& left, const List& right)
	{
		List result(left);
		for (Iterator it = right.begin(); it != right.end(); it++)
			result.push_back(*it);
		return result;
			/*
		Element* Temp = result.getHead();
		while (Temp->getpNext() != nullptr) 
			Temp = Temp->getpNext();   

		Temp = right.getHead();
		while (Temp->getpNext() != nullptr)
		{
			result.push_back(Temp->getData());
			Temp = Temp->getpNext();
		}
		result.push_back(Temp->getData());
		return result;*/
	}
