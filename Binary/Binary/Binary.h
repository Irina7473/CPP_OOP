#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define TAB "-----------------------------------------------\n";


class Binary
{
	int Size;  // ���������� ��������� ��������� �����
	int* Binnum;  //������ ��������� ��������� �����
	
public:
	//������������
	Binary();  //�� ���������
	Binary(int size, const int binnum[]);  //�� ��������
	Binary(const Binary& other);  //�����������
	Binary(Binary&& other);  //�����������
	Binary(int decnum); //�������������� �� ����������� �����
	~ Binary();  //����������

	int getSize()const { return Size; }
	const int* getBinnum()const { return Binnum; }
	int* getBinnum() { return Binnum; }
	void setSize(int size) { Size = size; }
	
	void print() const;
	int decconversion() const;  //�������������� ��������� ����� � ����������
	void sizeadding(int size);  // �������������� � ����������� �������
	void sizereduction();  // �������������� � ����������� �������
	
	Binary& operator=(const Binary& other);  //�������� ������������ � ����������� �������
	Binary& operator=(Binary&& other);  //�������� ������������ ������������

	const int& operator[] (const int ind)const;
	int& operator[] (int ind);

};

Binary singlesize(Binary& left, Binary& right);  // ���������� � ������ �������

ostream& operator<<(ostream& os, const Binary& binnum);
istream& operator>> (istream& is, Binary& obj);    //�� ����������

Binary operator+(const Binary& left, const Binary& right);
Binary operator-(const Binary& left, const Binary& right);
Binary operator*(const Binary& left, const Binary& right);
Binary operator/(const Binary& left, const Binary& right);

bool operator>(const Binary& left, const Binary& right);

Binary operator&(const Binary& left, const Binary& right);
Binary operator|(const Binary& left, const Binary& right);
Binary operator^(const Binary& left, const Binary& right);
Binary operator~(const Binary& obj);