#include<iostream>
#include "Tree.h"
using namespace std;
#define TAB cout<<"------------------------------------"<<endl

int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	int n;
	cout << "Введите количество элементов дерева" << endl; cin >> n;
	Tree t;
	for (int i = 0; t.size() < n; i++)
		t.insert(rand()%100);
	t.print();
	cout<<"min  "<<t.minValue()<<endl;
	cout <<"max  "<<t.maxValue() << endl;
	cout <<"количество элементов  "<< t.size() << endl;
	cout <<"сумма  "<<t.sum() << endl;
	cout <<"среднее арифметическое  "<<t.avg() << endl;
	TAB;
	Tree t2=t;
	t2.print();*/
	TAB;
	Tree t3 = {11,6,33,3,15,8,5,2,9};
	t3.print();
	cout << t3.search(15) << endl;
	cout<< t3.search(40)<<endl;
	TAB;
	t3.erase(6);
	t3.print();
	TAB;

	return 0;
}