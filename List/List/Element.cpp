#include "Element.h"

template <typename T> Element <T>::Element(T data) :
	Data(data), pPrev(nullptr), pNext(nullptr)
{//cout << "EConstructor:\t" << this << endl;
}
template <typename T> Element <T>::Element(T data, Element* pPrev, Element* pNext):
	Data(data), pPrev(pPrev), pNext(pNext)
{//cout << "EConstructor:\t" << this << endl;
}

template <typename T> Element <T>::Element(const Element& other):
	Data(other.Data), pPrev(other.pPrev), pNext(other.pNext)
{//cout << "ECopyConstructor:\t" << this << endl;
}

template <typename T> Element <T>::Element(Element&& other):
	Data(other.Data), pPrev(other.pPrev), pNext(other.pNext)
{
	other.pPrev = nullptr;
	other.pNext = nullptr;
	cout << "EMoviConstructor:\t" << this << endl;
}

template <typename T> Element<T>& Element<T>::operator=(const Element& other)
{
	if (this!=&other)
	{
		Data = other.Data;
		pPrev = other.pPrev;
		pNext = other.pNext;
	}
	//cout << "ECopyAssignment " << this << endl;
	return *this;
}

template <typename T> Element<T>& Element<T>::operator=(Element&& other)
{
	Data = other.Data;
	pPrev = other.pPrev;
	pNext = other.pNext;
	other.pNext=nullptr;
	//cout << "EMoveAssignment " << this << endl;
	return *this;
}
