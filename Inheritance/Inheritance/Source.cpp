#include <iostream>
#include<string.h>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	/*
	Student vasia("�������", "�������", 18, "���", 1, 70, 80);
	vasia.print();
	Teacher walter("White", "Walter", 50, "Chemestry", 25);
	walter.print();
	cout << "-------------------------" << endl;

	Human* pstedent = &vasia;
	Human* pteacher = &walter;
	pstedent->print();
	pteacher->print();*/

	Human* group[] =
	{
		new Student("�������", "����", 35, "���������� ������� ����������", 1, 100, 100),
		new Student("�������", "�����", 35, "AI &BigData", 1, 100, 100),
		new Student("�������", "�����", 25, "���������� Android ����������", 1, 95, 90),
		new Teacher("������", "����", 36, "���������� Android ����������", 5),

	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{	group[i]->print(); }

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{	delete group[i]; }


	return 0;
}