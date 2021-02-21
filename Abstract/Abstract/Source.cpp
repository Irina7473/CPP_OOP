#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
/*
class Animal
{
public:
	virtual void sound() =0;
};

class Cat : public Animal
{
public:
	void sound()
	{	cout << "לÿף" << endl;	}

};

class Dog : public Animal
{
public:
	void sound()
	{	cout << "דאפ" << endl;	}

};


int main()
{
	setlocale(LC_ALL, "Russian");

	//Animal animal;
	//Cat cat;
	//Dog dog;

	Animal* zoo[] =
	{
		new Cat(),
		new Cat(),
		new Cat(),
		new Dog()
	};

	for (Animal* i: zoo)
	{
		i->sound();
	}








	return 0;
}*/

class Digit
{
	int val;
public:
	Digit(int nVal) :val(nVal) {}
	int GetVal() const
	{
		return val;
	}
	static void SetVal(int nVal)
	{
		val = nVal;
	}
};
int main()
{
	Digit obj(3);
	obj.SetVal(7);
	cout << obj.GetVal();
	return 0;
}