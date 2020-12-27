#pragma once
#include<iostream>
#include<string.h>
using namespace std;

#define MOVE

class String
{
	int Size;   //������ ������
	char* Str;  //��������� �� ������ � ��� ������
public:
	int getsize()const { return Size; }
	const char* getstr()const { return Str; }
	char* getstr() { return Str; }

	void setsize(int size) { Size = size; }
	void setstr(int ind, char str) { Str[ind] = str; }
	//������������
	String() : String{ 80 } {}  //�� ���������
	String(int size);
	String(const char str[]);
	String(const String& other);  //�����������
	String(String&& S);  //�����������
	~String();
	
	void print()const;
	
	String& operator=(const String& other);  //�������� ������������ � ����������� �������
#ifdef MOVE
	String& operator= (String&& S); //�������� ����������� ��� ���������� �������  
#endif // MOVE

	String& operator+=(const String& other);
	
	const char& operator[] (const int ind)const;
	char& operator[] (int ind);

};

ostream& operator<<(ostream& os, const String& str);
istream& operator>>(istream& is, String& str);

String operator+(const String& left, const String& right);
