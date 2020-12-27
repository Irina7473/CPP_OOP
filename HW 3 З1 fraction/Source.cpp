#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Fraction.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "����� �����" << endl;

//#define constr check
#ifdef constr check

	Fraction F1;
	Fraction F2{ 1,1,2};
	Fraction F3{ 2,1,4};
	Fraction F4{3, 4};
	Fraction F5{2, 6};
	cout << F1 << F2 << F3<<F4<<F5<<endl;
	cout << endl;
	
#endif constr check

//#define arifmetic check
#ifdef arifmetic check

	cout << F2.improper() << endl;
	cout << F3.proper() << endl;
	cout << F4.reduce() << endl;
	cout << endl;
	cout << (F5 + F4) << endl;
	cout <<( F5 - F4) << endl;
	cout << (F2 * F3) << endl;
	cout << (F5 / F4) << endl;
	cout << endl;
	cout << (F1 = F4) << endl;
	cout << (F5 += F4) << endl;
	cout << (F5 -= F4) << endl;
	cout << (F5 *= F4) << endl;
	cout << (F5 /= F4) << endl;
	cout << endl;

#endif arifmetic check
	
//#define logic check
#ifdef logic check

	(F1 >= F4)? cout << true << endl : cout << false << endl;
	(F1 != F4)? cout << true << endl : cout << false << endl;
	(F5 != F4)? cout << true << endl : cout << false << endl;
	(F4 >= F5) ? cout << true << endl : cout << false << endl;
	cout << F1 << F2 << F3 << F4 << F5 << endl;

#endif logic check

#define constr string check
#ifdef constr string check

	string F;
	cout << "������� ������ ����� � �������: ����� �����, _, ���������, /, �����������, Enter" << endl;
	cin >> F;
	Fraction F7(F);
	cout << F7 <<endl;

	cout << "������� ������ ����� � �������: ����� �����, _, ���������, /, �����������, Enter" << endl;
	cin >> F;
	Fraction F8(F);
	cout << F8 << endl;

	Fraction F9;
	cout << "������� ������ ����� � �������: ����� �����, _, ���������, /, �����������, Enter" << endl;
	cin >> F9;
	//Fraction F9(F);
	cout << F9 << endl;

	Fraction C{ "-5_3/4 " };
	cout << C << endl;

#endif constr string check

//#define arifmetic negativ check
#ifdef arifmetic negativ check

	Fraction A{7,-4};
	Fraction B{-2,3};
	Fraction C{ 1,-4 };
	Fraction D{ -1,7,4 };
	cout << A << " " << B << " " << C << " " << D << endl << endl;

	cout << (A > 0) << endl;
	cout << (C > 0) << endl << endl;


	Fraction X{ "5_3/-4 " };
	cout << X << endl << endl;

	cout << A.proper() << endl;
	cout << B.proper() << endl;
	cout << C.proper() << endl;
	cout << D.proper() << endl << endl;

	cout <<A<<" "<<B << " " << C << " " << D << endl;
	cout << (A+B) << endl;
	cout << (A-B) << endl;
	cout << (A*B) << endl;
	cout << (A/B) << endl;
	cout << A /B + C << endl;


#endif arifmetic negativ check

//#define check
#ifdef  check

	Fraction A{ 1,2 };
	Fraction B{ 2,-2,3 };
	Fraction C{ 1,4,2 };
	Fraction D{ -1,7,4 };

	cout << (A > 0) << endl;
	cout << (B > -5) << endl;
	cout << (C > 2) << endl;
	cout << (D > -1) << endl;
#endif check

	return(0);
}