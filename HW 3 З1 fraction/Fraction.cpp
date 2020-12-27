#include "Fraction.h"

bool Fraction::datavalid(int I, int N, int D)  //�������� ������
{
	if (I < 0 && N>0 && D > 0 || I >= 0 && N < 0 && D > 0 || 
		I >= 0 && N > 0 && D < 0 || I >= 0 && N >= 0 && D >= 0) 
		return true;
	else
	{
		cout << "������ ������� �����������, � ����� ����� ���� ������ ���� ������������� ��������" << endl;
		exit(1);
	}
}

Fraction::Fraction(int I, int N, int D) //����� � ����� ������
{
	datavalid(I, N, D);
	FInt = I;
	FNum = N;
	FDen = D ? D : 1;}

Fraction::Fraction(const string& str)  // ������������� �� ������
{
	int posI = str.find('_');
	int posN = str.find('/');

	if (posN == string::npos)
		// ���� ������ "/" �� ������ - �� ��� ������ �������� ������ 
	{
		FInt = stoi(str);
		FNum = 0;
		FDen = 1;
	}
	else
	{
		if (posI == string::npos) FInt = 0;  //����� ����� = 0 ��� ���������� ������� "_"
		else FInt = stoi(str.substr(0, posI));  //����� ����� - ����� ����� �� ������� "_"
		FNum = stoi(str.substr(posI + 1, posN));  // ��������� - ����� ����� �� ������� "/"
		FDen = stoi(str.substr(posN + 1));  // ����������� - ������ ����� ����� ������� "/"
		datavalid(FInt, FNum, FDen);
	}
}

Fraction::Fraction(const Fraction& other)  //�����������
{
	FInt = other.FInt;
	FNum = other.FNum;
	FDen = other.FDen;
}

Fraction Fraction::reduce()  //���������� �����
{
	int gcd = findgcd(FNum, FDen);
	FNum /= gcd;
	FDen /= gcd;
	return *this;
}

Fraction& Fraction::proper()  //�������������� ����� � ����������
{
	int i;
	(this->negativ()) ? i = -1 : i = 1;  //����������� ����� �����
	FInt = abs(FInt) + abs(FNum / FDen);
	FNum = abs(FNum % FDen);
	FDen = abs(FDen);
	(FInt != 0)? FInt *= i : FNum *= i; //����������� ����� �����
	return *this;
}

Fraction& Fraction::improper()  //�������������� ����� � ������������
{
	int i;
	(this->negativ()) ? i = -1 : i = 1;  //����������� ����� �����
	FNum = abs(FNum)+abs(FInt * FDen);
	FDen = abs(FDen);
	FNum *= i; //����������� ����� �����
	return *this;
}

bool Fraction:: negativ()  // ��������� ����� � 0
{
	if (FInt < 0 || FNum < 0 || FDen < 0) return true;
	if (FInt >= 0)
		if (FNum < 0 && FDen > 0 || FNum > 0 && FDen < 0) return true;
		else return false;
}

bool Fraction::operator>(int i)  // ��������� ����� � ����� ������
{
	Fraction I(i);
	return *this > I;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	FInt = other.FInt;
	FNum = other.FNum;
	FDen = other.FDen;
	return *this;
}

int findgcd(int x, int y)  //���������� ����� ��������, ������������ ��� ���������� ������
{
	if (y == 0) return x;
	return findgcd(y, x % y);
}
int findlcm(int x, int y)  //���������� ����� �������
{for (int i = 1; ; i++)	if (x * i % y == 0) return x * i;}

ostream& operator<<(ostream& os, const Fraction& fract)
{
	if (fract.getFInt() != 0) os << fract.getFInt() << "_";
	if (fract.getFNum() != 0) os << fract.getFNum() << "/" << fract.getFDen() << "  ";
	return os;
}

//���� �� ������� �� ��������� ����
istream& operator>>(istream& is, const Fraction& fract)
{
	is >> fract;
	return is;
}

Fraction operator+(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFDen() +
		right.getFNum() * left.getFDen(),
		left.getFDen() * right.getFDen());
	return result.reduce().proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFDen() -
		right.getFNum() * left.getFDen(),
		left.getFDen() * right.getFDen());
	return result.reduce().proper();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFNum(), left.getFDen() * right.getFDen());
	return result.reduce().proper();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFDen(), left.getFDen() * right.getFNum());
	return result.reduce().proper();
}

Fraction& Fraction:: operator+=(const Fraction& other) { return *this = *this + other; }
Fraction& Fraction:: operator-=(const Fraction& other) { return *this = *this - other; }
Fraction& Fraction:: operator*=(const Fraction& other) { return *this = *this * other; }
Fraction& Fraction:: operator/=(const Fraction& other) { return *this = *this / other; }

bool operator==(const Fraction& left, const Fraction& right)
{
	return left.getFInt() == right.getFInt() &&
		left.getFNum() == right.getFNum() &&
		left.getFDen() == right.getFDen();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return left.getFInt() != right.getFInt() ||
		left.getFNum() != right.getFNum() ||
		left.getFDen() != right.getFDen();
}

/*
bool operator>(const Fraction& left, const Fraction& right)  
//������� 1 - ������ ��� ����� ���������� � �������������, �� ������� �������
{
	Fraction templeft(left);
	Fraction tempright(right);
	templeft.improper();
	tempright.improper();
	int lcm = findlcm(templeft.getFDen(), tempright.getFDen());
	return (lcm / templeft.getFDen() * templeft.getFNum()) > 
			(lcm/ tempright.getFDen()* tempright.getFNum());
}*/

bool operator>(Fraction& left, Fraction& right)  /*������� 2 - 
	�� ������ ���� ����� ���������� �������������, ��� �������� ��� ������ �� �������(������), ��������; 
	��������� � �������� ������ � ������� ������������ ���������� � ����������� � ���������� ����� ���������, 
	�.�. ����� ������������ ������ ����� � ��� ����, ��� ��� ����.*/
{
	left.improper();
	right.improper();
	return left.getFNum()* right.getFDen() > right.getFNum() * left.getFDen();
}

bool operator<(Fraction& left, Fraction& right)  //������� 2
{if (left > right) return false; else return true;}

bool operator>=(Fraction& left, Fraction& right)  //������� 2
{
	left.improper();
	right.improper();
	return left.getFNum() * right.getFDen() >= right.getFNum() * left.getFDen();
}

bool operator<=(Fraction& left, Fraction& right)  //������� 2
{
	left.improper();
	right.improper();
	return left.getFNum() * right.getFDen() >= right.getFNum() * left.getFDen();
}