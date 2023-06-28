/*
    2) Run time polymorphism : we achieve this kind of polymorphism by function overriding using virtual functions in cpp


    * some interesting things about pointers
    -> pointers can be used for base objects as well as objects of derived classes.
    -> The pointer of Base class pointing different objects of the derived class
    -> A derived class is a class that takes some properties from its base class and it it true that a pointer of one class can point to another class, but classes must be base and derived class, then only it is possible.
    -> TO access the variable of the base class, a base class pointer will be used.So, a pointer is a type of base class, and it can access all, public function and variables of the base class since the pointer is of the base class,this is known as binding pointer.
    -> In this pointer base class is owned by the base class but points to the derived class object.
    
 */

#include <iostream>
using namespace std;
class A
{
public:
    virtual void func()
    {
        cout << " this is func from class A ." << endl;
    }
    void funcb()
    {
        cout << " this is funcb from class A ." << endl;
    }
};
class B : public A
{
public:
    void func()
    {
        cout << " This is func from class B." << endl;
    }
    void funcb()
    {
        cout << " This is funcb from class B." << endl;
    }
};
int main()
{
    A *a;
    B b;
    a = &b;

    // (*a).func();
    a->func();
    a->funcb();
    return 0;
}