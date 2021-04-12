#pragma once
#include "ListViolationsCar.h"
//автомобиль со списком своих нарушений
class CarViolator
{
    int NamberCar;
    ListViolationsCar* List;
    CarViolator* pLeft;
    CarViolator* pRight;
public:

    CarViolator(int namberCar, CarViolator* pleft=nullptr, CarViolator* pright=nullptr) :
        NamberCar(namberCar), pLeft(pLeft), pRight(pRight) 
    { List = new ListViolationsCar; };
    
    ~CarViolator() {};
        
    bool is_leaf() { return pLeft == pRight; }
    friend class DBviolators;
};
