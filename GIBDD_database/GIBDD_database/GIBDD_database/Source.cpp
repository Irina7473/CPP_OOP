#include<iostream>
#include<cstring>
#include<cstdlib>
#include "DBviolators.h"

#define BASA
//#define CAR


using namespace std;

int main()
{
   // setlocale(LC_ALL, "Russian");
  
#ifdef CAR
    ListViolationsCar Car1;
    Car1.push_front(20180512, "Orel", 911);
    Car1.push_front(20180602, "Perm", 918);
    Car1.print();
    //cout << Car1 << endl; error
    cout << sec << endl;

#endif CAR

   

#ifdef BASA
    DBviolators DB;
    DB.insert(568269, 20190610, "Samara", 911);
    cout << sec;
    DB.insert(325784, 20200618, "Perm", 916);
    cout << sec;
    DB.insert(754784, 20180512, "Orel", 921);
    cout << sec;
    DB.insert(568269, 20200425, "Samara", 923);
    cout << sec;
    DB.insert(754784, 20180512, "Orel", 945);
    DB.insert(754784, 20190622, "Orel", 945);

    cout << sec << endl;
    DB.print();
    cout << sec;
    DB.print(754784);
    cout << sec;
    //DB.print(754784);
    //cout << sec << endl;

#endif BASA

    
    return 0;
}








/*
struct ListViolations
{
    char* violat;
    ListViolations* next;
};

void Push(ListViolations*& node, char* newStr)
{
    ListViolations* tmp = new ListViolations;
    tmp->violat = new char[strlen(newStr) + 1];
    strcpy(tmp->violat, newStr);
    tmp->next = NULL;

    if (node == NULL)
        node = tmp;
    else
    {
        tmp->next = node;
        node = tmp;
    }
}

void ClearList(ListViolations*& Head)
{
    ListViolations* curr = Head;
    while (curr)
    {
        ListViolations* temp = curr->next;
        delete[] curr->violat;
        delete curr;
        curr = temp;
    }
}

void PrintList(ListViolations* Head)
{
    ListViolations* curr = Head;
    while (curr)
    {
        std::cout << curr->violat << std::endl;
        curr = curr->next;
    }
}

///////////////////////////

struct TreeNode
{

    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    int number;
    ListViolations* list;
};

class database
{
private:
    int size;
    TreeNode* root;

public:
    database();
    ~database();

    void Add(int value, char*);
    void Add(TreeNode*&, TreeNode*, int, char*);
    void PrintAll(TreeNode*);
    //  void PrintNumber(int);
    //void PrintRangeNumber(TreeNode*);
    TreeNode* ReturnRoot();
    void DeleteAll(TreeNode* temp);
};

database::database()
{
    root = NULL;
    size = 0;
}
//деструктор
database::~database()
{
    DeleteAll(root);
}
//метод получения корня
TreeNode* database::ReturnRoot()
{
    return root;
}
//метод удаления всего
void database::DeleteAll(TreeNode* temp)
{
    if (temp)
    {
        DeleteAll(temp->left);
        DeleteAll(temp->right);
        ClearList(temp->list);
        delete temp;
    }
}




//метод печати полной базы данных
void database::PrintAll(TreeNode* temp)
{
    if (temp)
    {
        PrintAll(temp->left);
        cout << "Номер машины: " << temp->number << endl;
        cout << "Нарушения: " << endl;
        PrintList(temp->list);
        PrintAll(temp->right);
    }
}


}*/
