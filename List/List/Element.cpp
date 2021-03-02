#include "Element.h"

Element::Element(int data, Element* pPrev=nullptr, Element* pNext=nullptr):
	Data(data), pPrev(pPrev), pNext(pNext)
{cout << "EConstructor:\t" << this << endl;}

Element::Element(const Element& other):
	Data(other.Data), pPrev(other.pPrev), pNext(other.pNext)
{cout << "ECopyConstructor:\t" << this << endl;}

Element::Element(Element&& other):
	Data(other.Data), pPrev(other.pPrev), pNext(other.pNext)
{
	other.pPrev = nullptr;
	other.pNext = nullptr;
	cout << "EMoviConstructor:\t" << this << endl;
}

Element& Element::operator=(const Element& other)
{
	if (this!=&other)
	{
		Data = other.Data;
		pPrev = other.pPrev;
		pNext = other.pNext;
	}
	cout << "ECopyAssignment " << this << endl;
	return *this;
}

Element& Element::operator=(Element&& other)
{
	Data = other.Data;
	pPrev = other.pPrev;
	pNext = other.pNext;
	other.pNext=nullptr;
	cout << "EMoveAssignment " << this << endl;
	return *this;
}
