#pragma once
#include "String.h"

String:: String(int size) : Size{ size }, Str ( new char[Size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char str[]) : String ( strlen(str) + 1)  //делегирование конструктора
{
	for (int i = 0; i < strlen(str) + 1; i++)
		Str[i] = str[i];
	cout << "SignConstructor:\t" << this << endl;
}

String::String(const String& other) : String(other.Str)
{
	/*if (this != &other)
	{
		Size = other.Size;
		Str = new char[Size] {};
		for (int i = 0; i < Size; i++)
			Str[i] = other.Str[i];
	}*/
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other) : Size(other.Size), Str(other.Str)
{
	other.Str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}

String:: ~String()
{
	delete[] Str;
	cout << "Destructor:\t" << this << endl;
}

void String::print()const
{
	cout << "Size: " << Size << "\t";
	cout << "Str: " << Str << endl;
}

String& String:: operator=(const String& other)
{
	if (this != &other)
	{
		delete[] Str;
		Size = other.Size;
		Str = new char[Size] {};
		for (int i = 0; i < Size; i++)
			Str[i] = other.Str[i];
		cout << "CopyAassignment:\t" << this << endl;

	}
	return *this;
}

/* Отказалась от этого оператора,
тк с ним неправильно работало сложение,
обрезалось все после первого пробела, тк надо было скопировать размер*/

#ifdef MOVE
String& String::operator= (String&& other)
{
	delete Str;
	this->Size = other.Size;
	Str = other.Str;
	other.Str = nullptr;
	cout << "MoveAassignment:\t" << this << endl;
	return *this;
}
#endif // MOVE


String& String:: operator+=(const String& other)
{
	//String S= Str + *other.getstr();
	//Str= Str + *other.getstr();
	//cout << S << endl;
	return *this = *this + other;
}

const char& String:: operator[] (const int ind)const
//оператор индексирование возвращает значение элемента массива по индексу
{
	//return (ind >= 0 && ind <= Size)?  Str[ind] : 0;
	return Str[ind];
}

char& String:: operator[] (int ind)
{
	//if (ind >= 0 && ind < Size) 
	return Str[ind];
}



ostream& operator<<(ostream& os, const String& str)
{
	os << str.getstr();
	return os;
}

istream& operator>>(istream& is, String& str)
{
	return is >> str.getstr();

}

String operator+(const String& left, const String& right)
{
	String result(left.getsize() + right.getsize() - 1);
	for (int i = 0; i < left.getsize() - 1; i++)
	{
		//result.getstr()[i] = left.getstr()[i];    //без перегруженных []
		result[i] = left[i]; //  для перегруженных []
	}
	//result[left.getsize() - 1] = ' ';
	for (int i = left.getsize() - 1; i < (left.getsize() + right.getsize() - 1); i++)
	{
		result[i] = right[i - left.getsize() + 1];
	}
	return result;
}

