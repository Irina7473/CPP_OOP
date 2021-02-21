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
	Student vasia("Тупенко", "Василий", 18, "РПО", 1, 70, 80);
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
		new Student("Гулюкин", "Олег", 35, "Разработка сетевых приложений", 1, 100, 100),
		new Student("Сиренко", "Ирина", 35, "AI &BigData", 1, 100, 100),
		new Student("Шниткин", "Денис", 25, "Разработка Android приложений", 1, 95, 90),
		new Teacher("Ковтун", "Олег", 36, "Разработка Android приложений", 5),

	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{	group[i]->print(); }

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{	delete group[i]; }


	return 0;
}