#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a = 2.5;
	cout << a << (int)a << int(a);
	cout << typeid(2 + 3.5).name();

	int a = 2;    //��� ��������������
	double b = 3;  //���� ��������������
	Fraction A = 5;  //���� ��������������� �� ����� ����������� � 1 ����������


}

/*���������� ��� �������� ����������� � ����������� ���� ������ � ����������
����� ������������ =
��������� ������ ����������� �������� ������ � ���� ����� 
���������� �� ������� ������ ���� ��� ��� ���� ������������

� ��� ��������� �������������� �� ������� ���� � ��� � �� ������ � ����� ����

�������������� ������ ����� � ��� ���
��� ����� � ������ �� ����������� � 1 ���������� 
���� ��������� �������� ������������


*/