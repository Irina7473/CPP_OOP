#include<iostream>
#include<iterator>
#include "Element.h"
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
//#define chek
#ifdef chek
	int n;
	cout << "Введите размер списка" << endl;
	cin >> n;
	List list;
	
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	cout << list << endl;

	List list2;
	list2.push_back(123);
	list2.push_back(456);
	list2.push_back(789);
	list2.print();
	
#endif chek

//#define chek1
#ifdef chek1
	list.push_front(3);
	cout << list << endl;
	list.push_back(123);
	list.print();
	int index;
	int data;
	cout << "Введите индекс добавляемого элемента > 0"; cin >> index;
	cout << "Введите значение добавляемого элемента"; cin >> data;
	list.insert(index, data);
	list.print();
#endif chek1

//#define chek2
#ifdef chek2
	list.pop_front();
	cout<<list.lengthList()<<endl;
	list.print();
	list.pop_back();
	cout << list.lengthList() << endl;
	list.print();

	int index;
	cout << "Введите индекс удаляемого элемента > 0 "; cin >> index;
	list.erase(index);
	cout << list.lengthList() << endl;
	list.print();
	
#endif chek2

//#define chek3
#ifdef chek3
	List list3 = list;
	list3.print();
	List list4;
	for (int i = 0; i < n; i++)
		list4.push_back(i+5);
	list4.print();
	List list5;
	list5 = list3 + list4;
	list5.print();

#endif chek3

#define chek4
#ifdef chek4
	List list4 = { 3,5,8,13,21 };
	cout << list4 << endl;
	cout<<list4[1] << endl;
	cout << list4.getElement(2)->getData() << endl;
	cout << list4.search_data_list(8)<<" "<< list4.search_data_list(8)->getData() << endl;
	list4.print();
	for (int i : list4)
		cout << i << tab;
	cout << endl;

	List list2 = { 2,10,40 };
	for (Iterator it=list2.begin(); it!=list2.end();it++)
		cout << *it << tab;
	cout << endl;

	List list1 = {0,0,0};
	for (Iterator it = list2.begin(); it != list2.end(); it++)
		cout << *it << tab;
	cout << endl;

	List list3 = list4 + list2+list1;
	cout << list3 << endl;
	List list5;
	list5= list4 + list2 + list1;
	list5.print();

#endif chek4

//#define chek5
#ifdef chek5
	int n;
	cout << "Введите размер списка" << endl; cin >> n;
	List list (n);

	for (int i = 0; i < n; i++)
	{
		list[i]=(rand() % 100);
		cout<<list[i]<<tab;
	}
	cout << endl;

	List list2 (list);
	list2.print();
	List list3 = list;
	list3.print();
	

#endif chek5


	return 0;
}
