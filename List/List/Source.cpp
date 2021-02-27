#include<iostream>
#include "Element.h"
#include "Iterator.h"
#include "List.h"
using namespace std;
#define TAB "--------------------------------"

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка" << endl;
	cin >> n;
	//#define chek
#ifdef chek

	List list;
	for (int i = 0; i < n; i++)
	{list.push_back(rand() % 100);}
	list.print();
	cout << TAB << endl;
	list.push_front(1);
	cout << list << endl;
	list.push_back(10);
	cout << list << endl;
	cout << TAB << endl;
	list.getElement(2);
	list.getElement(4);
	list.getElement(5);
	cout << TAB << endl;

#endif chek

//#define chek1
#ifdef chek1
	List list1(n);
	for (int i = 0; i < n; i++)
	{
		list1[i] = rand() % 100;
	}
	list1.print();
	cout << TAB << endl;

	int index;
	int data;
	cout << "Введите индекс добавляемого элемента > 0  "; cin >> index;
	cout << "Введите значение добавляемого элемента  "; cin >> data;
	list1.insert(index, data);
	list1.print();
	cout << TAB << endl;

#endif chek1

#define chek2
#ifdef chek2
	List list2 = {25,46,78,24,58,92};
	list2.print();
	cout << TAB << endl;
	list2.pop_front();
	list2.print();
	list2.pop_back();
	list2.print();
	int index;
	cout << "Введите индекс удаляемого элемента > 0  "; cin >> index;
	list2.erase(index);
	list2.print();
	cout << TAB << endl;

#endif chek2


	return 0;
}