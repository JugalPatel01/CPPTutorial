/*
     Polymorphism
    -> Many Forms

    * there are two types of polymorphism
    1) compile Time 2) Run time

    1) compile time Polymorphism : it has two types
    a) function overloading b) operator overloading
    a) function overloading : when there are different function with the same name which are distinguishable by argument numbers, types, or order.
    b) operator overloading : if a single operator is used to perform more than one operation. like + is used for int addtion and float addition and complex no. addition ( we have to make our own function for that)

    2) Run time polymorphism : we achieve this kind of polymorphism by function overriding using friend function in cpp
 */
#include <iostream>
using namespace std;

class A
{
public:
    void fun()
    {
        cout << " function without arguments." << endl;
    }
    void fun(int x)
    {
        cout << " function with int arguments " << x << endl;
    }
    void fun(double x)
    {
        cout << " function with double argument " << x << endl;
    }
};
int main()
{
    A a;
    a.fun();
    a.fun(32);
    a.fun(35.53);
    return 0;
}