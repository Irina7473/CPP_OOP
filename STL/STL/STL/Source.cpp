#include<iostream>
#include <array>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

using namespace std;

//#define ARRAY
#define VECTOR

template <typename T, size_t> void Print();


int main()
{
	setlocale(LC_ALL, "Russian");

#ifdef ARRAY
	const int n = 5;
	array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{	cout << arr[i] << "  ";	}
	cout << endl;
	
#endif ARRAY

#ifdef VECTOR
	int n ;
	cout << "¬ведите размер вектора"; cin >> n;
	vector<int> vec(n);
	try
	{
		//vec.push_back(123);
		for (int i = 0; i < vec.size(); i++)
		{
			vec[i] = rand() % 100;
			//cout << vec[i] << "  ";
			cout << vec.at(i) << "  ";
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	cout << "Size  "<<vec.size() << endl;
	cout << "Capacity  "<<vec.capacity() << endl;
	cout << "Max_size  " << vec.max_size() << endl;

	//int size;
	//cout << " аким размером нужно сделать вектор   "; cin >> size;
	//vec.resize(size);

	int value, index, number;
	cout << "в¬¬≈ƒ»“≈ ƒќЅј¬Ћя≈ћќ≈ «Ќј„≈Ќ»≈   "; cin >> value;
	cout << "в¬¬≈ƒ»“≈ индекс ƒќЅј¬Ћя≈ћќ≈ «Ќј„≈Ќ»≈   "; cin >> index;
	cout << "кол-во вставок   "; cin >> number;
		vec.insert(vec.begin()+index, number, value);

	for (vector<int>::iterator it=vec.begin(); it!=vec.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	vec.insert(vec.begin() + 2, { 3,5,8,13,21 });
	for (int i : vec)
	{	cout<<i << "  ";	}
	cout << endl;

	cout << "Size  " << vec.size() << endl;
	cout << "Capacity  " << vec.capacity() << endl;
	cout << "Max_size  " << vec.max_size() << endl;
	

#endif VECTOR




	return 0;
}

/*
Ѕаза данных √ј», где хран€тс€ 
номер авто и список правонарушений.
ќбеспечить добавление новых авто, 
новых правонарушений к существующим в базе,
поиск авто и его нарушений по номеру,
вывод авто с правонарушением определенного типа.


*/