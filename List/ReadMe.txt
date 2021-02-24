https://www.youtube.com/watch?v=keX4ivr9Ytc&list=PLeqyOOqxeiINBBW5KUmcf-M4_wfb4yqKp&index=1&t=205s
https://github.com/okovtun/VBU_022_CPP

TODO:
Реализовать класс List, описывающий двусвязный список.

DONE:
В класс List добавить методы:
void pop_front();	//Удаляет начальный элемент списка	DONE
void pop_back();	//Удаляет последний элемент списка	DONE
void erase(int index);	//Удаляет значение из списка по указанному индексу
void Sort();		//Сортировка списка;

CopyMethods: CopyConstructor; CopyAssignment (=);
MoveMethods: MoveConstructor; MoveAssignment;
operator+ - выполняет конкатенацию двух списков;
Конструктор на заданное число элементов; 	DONE
operator[];					DONE

//Этот проверочный код должен заработать
List list = {3,5,8,13,21};			DONE
for(int i:list)			DONE
	cout << i << tab;
cout << endl;


