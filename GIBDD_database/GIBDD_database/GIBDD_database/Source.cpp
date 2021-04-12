#include "DBviolators.h"
#define BASA
//#define CAR

int main()
{
  #ifdef CAR
    ListViolationsCar Car1;
    Car1.push_front(20180512, "Orel", 911);
    Car1.push_front(20180602, "Perm", 918);
    Car1.printList();
    //cout << Car1 << endl; error
    cout << sec << endl;
    #endif CAR
 
#ifdef BASA
    DBviolators DB;
    DB.insert(568269, 20190610, "Samara", 911);
    DB.insert(325784, 20200618, "Perm", 916);
    DB.insert(754784, 20180512, "Orel", 921);
    DB.insert(568269, 20200425, "Samara", 923);
    DB.insert(754784, 20180512, "Orel", 911);
    DB.insert(754784, 20190622, "Orel", 911);
    cout << sec << endl;
    DB.print();
    cout << sec;
    DB.print(754784);
    cout << sec;
    DB.printViol(911);
    cout << sec << endl;
   #endif BASA
        
    return 0;
}
