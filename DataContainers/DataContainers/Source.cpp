#include<iostream>
using namespace std;


int push_back(int* arr, int &n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i];
	delete[] arr;
	buffer[n] = value;
	n++;
	return *buffer;
}

void main()
{
	setlocale(LC_ALL, "");
	const int n =5;
	int* arr =new int[n] { 3,5,8,13,21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
		cout << *(arr+i) << "\t";
	cout << endl;

	delete[]arr;

}