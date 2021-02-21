#include<iostream>
#include<string.h>
#include <stdio.h>
#include "String.h"

using namespace std;
#define delimiter "\n-----------\n"

int main()
{
	setlocale(LC_ALL,"");

//#define check 1
#ifdef check 1
	String str0 = "Hello";
	cout << delimiter << endl;
	String str1 = str0;
	cout << delimiter << endl;
	String str2{ "world!" };
	cout << delimiter << endl;
	String str3 ( "Ura" );
	cout << delimiter << endl;
	String str4 = String("life and world!");
	cout << delimiter << endl;
	cout << str0 << endl << str1 << endl << str2 << endl << str3 << endl << str4 << endl;
	cout << delimiter << endl;
	cout << str1+" "+str2 << endl << endl;  // "Hello world!"  
	//здесь не€вное преобразование типов, тк есть конструктор с 1 параметром
	//здесь работает MoveConstructor
	cout << delimiter << endl;

	
	str1 += str2;  // "Hello world!"
	str1.print();
	cout << delimiter << endl;

	str3 = str3 + " " + str4;  // "Ura life and world!"
	str3.print();
	cout << endl;
	cout << delimiter << endl;


	String str5 = str1 + " " + str3;  // "Hello world! Ura life and world!"
	str5 += "That's okay ;-)";
	str5 = str5;
	cout << str5 << endl << endl;
	/*
	str2.setstr(0, 'r');
	cout << str2.getstr() << endl;  //"rorld!"
	str2[0] = 'w';
	cout << str2[0] << endl;  //"w"
	*/

#endif check 1

//#define check 2
#ifdef check 2
	String str7, str8, str9;
	str7 = str8 = str9 = "Ura";
	cout << str7 << endl;
	cout << str8 << endl;
	cout << str9 << endl;
	str7 = str7;
	cout << str7 << endl;
#endif check 2

#define check 3
#ifdef check 3
	String name;
	cout << "¬ведите ¬аше им€ : ";
	cin >> name;
	cout << name<<endl;

#endif check 3
	

	return 0;
}
