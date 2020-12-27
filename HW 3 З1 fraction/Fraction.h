#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Fraction  //�������� ������ ��� ������
{
	int FInt;  //����� �����
	int FNum;  //���������
	int FDen;  //�����������
	bool datavalid(int I, int N, int D);   //�������� ������ 
public:
	//������������
	Fraction() : Fraction{ 0, 0, 1 } {} //�� ���������
	Fraction(int I, int N, int D); //����� � ����� ������
	Fraction(int N, int D) : FInt{ 0 }, FNum{ N } {FDen = D ? D : 1;} //����� ��� ����� �����
	Fraction(int I) : FInt{ I }, FNum{ 0 }, FDen{ 1 } {}  //����� �����
	Fraction(const string& str);  // ������������� �� ������
	Fraction(const Fraction& other);  //�����������

	//�������, �������
	int getFInt()const { return FInt; }
	int getFNum()const { return FNum; }
	int getFDen()const { return FDen; }
	void setFInt(int I) { FInt = I; }
	void setFNum(int N) { FNum = N; }
	void setFDen(int D) { FDen = D ? D : 1; } //� ��������� �� ������� �����������

	Fraction reduce(); //���������� �����
	Fraction& proper(); //�������������� ����� � ����������
	Fraction& improper(); //�������������� ����� � ������������

	bool negativ();  // ��������� ����� � 0
	bool operator>(int X);  // ��������� ����� � ����� ������

	//���������� ���������� ������������
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);// { return *this = *this + other; }
	Fraction& operator-=(const Fraction& other);// { return *this = *this - other;	}
	Fraction& operator*=(const Fraction& other);// { return *this = *this * other; }
	Fraction& operator/=(const Fraction& other);// { return *this = *this / other; }

};

int findgcd(int x, int y); //���������� ����� ��������, ������������ ��� ���������� ������
int findlcm(int x, int y); /*���������� ����� �������, 
						   ������������ ��� ���������� � ������ �����������, 
						   �� �� ����� ����� ����������� �������� ������������� ������������, 
						   �� ��� ����� ����� ��������� ����� */
ostream& operator<<(ostream& os, const Fraction& fract);  //����� � �������
istream& operator>>(istream& is, const Fraction& fract);  //���� �� ������� �� ��������� ����

//���������� ����������
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

//���������� ���������� ���������
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
//bool operator>(const Fraction& left, const Fraction& right);  //������� 1
bool operator>(Fraction& left, Fraction& right);   //������� 2
bool operator<(Fraction& left, Fraction& right);   //������� 2
bool operator>=(Fraction& left, Fraction& right);   //������� 2
bool operator<=(Fraction& left, Fraction& right);   //������� 2