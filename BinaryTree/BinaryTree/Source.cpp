#include<iostream>
#include "Tree.h"
using namespace std;
#define TAB cout<<"------------------------------------"<<endl

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ���������� ��������� ������" << endl; cin >> n;
	Tree t;
	for (int i = 0; t.size() < n; i++)
		t.insert(rand()%100);
	t.print();
	cout<<"min  "<<t.minValue()<<endl;
	cout <<"max  "<<t.maxValue() << endl;
	cout <<"���������� ���������  "<< t.size() << endl;
	cout <<"�����  "<<t.sum() << endl;
	cout <<"������� ��������������  "<<t.avg() << endl;
	TAB;
	Tree t2=t;
	t2.print();
	TAB;
	Tree t3 = {1,2,3,4,5};
	t3.print();

	return 0;
}