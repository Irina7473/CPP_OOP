#include "List.h"

template <typename T> List <T>::List(): Head(nullptr), Tail(nullptr), Size(0)
{//cout << "LdefaultConstructor:\t" << this << endl;
}

template <typename T> List <T>::List(int size): List()
{
	//while (size--)push_back(0);
	for (int i = 0; i < size; i++)
		push_back(0);
	//cout << "LConstructor:\t" << this << endl;
}

template <typename T> List <T>::List(const initializer_list<T> &list): List()
{
	for (T const* it = list.begin(); it != list.end(); it++)
		push_back(*it);
	//cout << "LinitConstructor:\t" << this << endl;
}

template <typename T> List <T>::List(const List& other): List()
{
	for (Iterator<T> it = other.Head; it != nullptr; it++)
		push_back(*it);
	//cout << "LcopyConstructor:\t" << this << endl;
}

template <typename T> List <T>::List(List&& other):
	Head(other.Head), Tail(other.Tail), Size(other.Size)
{
	other.Head = nullptr;
	other.Tail = nullptr;
	//cout << "LmoveConstructor:\t" << this << endl;
}

template <typename T> List <T>::~List()
{
	while (Tail) pop_back();
	//cout << "LDestructor:\t" << this << endl;
}

template <typename T> Element<T>* List<T>::getElement(int ind) const
{
	Element* Temp;
	if (ind <= Size / 2)
	{
		Temp = Head;
		for (int i = 0; i < ind - 1; i++)
			Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < (Size-ind); i++)
			Temp = Temp->pPrev;
	}
	return Temp;
}

template <typename T> void List <T>::push_front(int data)
{
	if (empty())
		Head = Tail = new Element(data, nullptr, nullptr);
	else Head = Head->pPrev = new Element(data, nullptr, Head);
	Size++;
}

template <typename T> void List <T>::push_back(int data)
{
	if(empty())
		Head=Tail= new Element(data, nullptr, nullptr);
	else Tail = Tail->pNext=new Element(data, Tail,nullptr);
	Size++;
}

template <typename T> void List <T>::insert(int ind, int data)
{
	if (ind<=0 || ind > Size+1) return;
	if (empty() || ind == 1)
	{
		push_front(data);
		return;
	}
	if (ind == Size + 1) push_back(data);
	   else
	{
		Element<T>* Temp = this->getElement(ind);
		Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp->pPrev, Temp);
		Size++;
	}
}

template <typename T> void List <T>::pop_front()
{
	if (Head)
	{
		Element<T>* Temp = Head;
		if (Temp->pNext)
		{
			Head = Head->pNext;
			Head->pPrev = nullptr;
		}
		else Head = Tail = nullptr;
		delete Temp;
		Size--;
	}
}

template <typename T> void List <T>::pop_back()
{
	if (Tail)
	{
		Element<T>* Temp = Tail;
		if (Temp->pPrev )
		{
			Tail = Tail->pPrev;
			Tail->pNext = nullptr;
		}
		else Head = Tail=nullptr;
		delete Temp;
		Size--;
	}
}

template <typename T> void List <T>::erase(int ind)
{
	if (ind == 1) pop_front();
	else if (ind == Size) pop_back();
	else
	{
		Element<T>* Temp = this->getElement(ind);
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		Size--;
	}
}

template <typename T> T & List <T>::operator[](const int ind)
{
	if (ind<0 || ind > Size) throw exception("Out of range");
	return this->getElement(ind)->Data;
}

template <typename T> List<T>& List <T>::operator=(const List& other)
{
	if (this != &other)
	{
		while (Head) pop_front();
		for (Iterator it = other.Head; it != nullptr; it++)
			push_back(*it);
	}
	//cout << "LCopyAssignment " << this << endl;
	return *this;
}

template <typename T> List<T>& List <T>::operator=(List&& other)
{
	while (Head) pop_front();
	Size = other.Size;
	Head = other.Head;
	Tail = other.Tail;
	other.Head = nullptr;
	other.Tail=nullptr;
	//cout << "LMoveAssignment " << this << endl;
	return *this;
}

template <typename T> bool List <T>::empty() const
{
	return Head == nullptr && Tail == nullptr;
}

template <typename T> void List <T>::print()const
{
	for (Element<T>* Temp = Head; Temp!=nullptr; Temp=Temp->pNext)
		cout<< Temp << tab << Temp->Data << tab << Temp->pPrev << tab << Temp->pNext << endl;
	cout << "Размер списка " << Size << endl;
	
}
template <typename T> void List <T>::print_reverse()const
{
	/*
	for (Element* Temp = Tail; Temp; Temp=Temp->pPrev)
		cout << Temp << tab << Temp->Data << tab << Temp->pPrev << tab << Temp->pNext << endl;*/
	
	for (ReverseIterator<T> it = Tail; it != nullptr; it++)
		cout << *it << tab;
	cout << "Размер списка " << Size << endl;
}

/*
 ostream& operator <<(ostream& os, const List<T>& list)
{
	for (Iterator<T> it = list.getHead(); it != nullptr; it++)
		  os << *it << tab;
	cout << "Размер списка " << list.getSize() << endl;
	return os;
}*/

template <typename T> List <T> operator +(const List<T>& left, const List<T>& right)
{
	List<T> result(left);
	for (Iterator<T> it = right.getHead(); it != nullptr; it++)
		result.push_back(*it);
	return result;
}
