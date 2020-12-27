#pragma once
#include<iostream>
#include<string.h>
using namespace std;

#define MOVE

class String
{
	int Size;   //размер строки
	char* Str;  //указатель на строку в дин памяти
public:
	int getsize()const { return Size; }
	const char* getstr()const { return Str; }
	char* getstr() { return Str; }

	void setsize(int size) { Size = size; }
	void setstr(int ind, char str) { Str[ind] = str; }
	//Конструкторы
	String() : String{ 80 } {}  //по умолчанию
	String(int size);
	String(const char str[]);
	String(const String& other);  //копирования
	String(String&& S);  //перемещения
	~String();
	
	void print()const;
	
	String& operator=(const String& other);  //оператор присваивания с сохранением объекта
#ifdef MOVE
	String& operator= (String&& S); //оператор перемещения без сохранения объекта  
#endif // MOVE

	String& operator+=(const String& other);
	
	const char& operator[] (const int ind)const;
	char& operator[] (int ind);

};

ostream& operator<<(ostream& os, const String& str);
istream& operator>>(istream& is, String& str);

String operator+(const String& left, const String& right);
