#include<iostream>
#include "Tree.h"
using namespace std;
#define TAB cout<<"------------------------------------"<<endl

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int n;
	cout << "������� ���������� ��������� ������" << endl; cin >> n;
	Tree<double> t;
	for (int i = 0; t.size() < n; i++)
		t.insert(rand()%100);
	t.print();
	cout<<"min  "<<t.minValue()<<endl;
	cout <<"max  "<<t.maxValue() << endl;
	cout <<"���������� ���������  "<< t.size() << endl;
	cout <<"�����  "<<t.sum() << endl;
	cout <<"������� ��������������  "<<t.avg() << endl;
	TAB;
	/*
	Tree<double> t2=t;
	t2.print();
	TAB;
	Tree<int> t3 = {11,6,33,3,15,8,5,2,9,40,36};
	t3.print();
	cout << "min  " << t3.minValue() << endl;
	cout << "max  " << t3.maxValue() << endl;
	cout << "������� 15  " << t3.search(15) << endl;
	cout<< "������� 40  " << t3.search(40)<<endl;
	TAB;
	t3.erase(5);
	t3.erase(6);
	t3.erase(11);
	t3.print();
	TAB;*/
	/////////////////////////////
	
	/*
	for (Iterator<double> it=t.begin(); it !=t.end(); ++it)
		{
		cout << *it << tab;
	}
	
	for (int:t)
	{
		cout < i << tab;
	}*/


	return 0;
}