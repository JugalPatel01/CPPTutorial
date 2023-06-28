/*
    Inheritance

    - with the help of the inheritance we can inherit attributes and methods from one class to another.
    - so there is derived class(child class) and base class(parent class).
    - Derived Class(child) - the class that inherits from another class
    - Base Class (parent) - the class being inherited from
    - we inherit data from base class to derived class

    * types of inheritance
    1) Single Inheritance
    - when one class inherits another class
    2) Multiple Inheritance ( it is not possible in java )
    - It is the process of deriving a new class that inherits the attributes from two or more classes.
    3) Multi level Inheritance
    - It is a process of deriving a class from another derived class.
    4) Hierarchical Inheritance
    - It is defiend as the process of deriving more than onclass from a base class.
    5) Hybrid Inheritance
    - It is a combination of simple, multiple inheritance and hierarchical inheritance.


 */

#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "constructor base class A" << endl;
    }
    void func()
    {
        cout << "call from class A" << endl;
    }
    void funca()
    {
        cout << " call from funca from class A" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "constructor derived class B" << endl;
    }
    // if we mention func() function in  B then it call newer func() from B and if we don't mention func() in class B then it inherit func() from class A
    void func()
    {
        cout << "call from Class B" << endl;
    }
    void funcb()
    {
        cout << "call of funcb from class B" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "constructor call from class C" << endl;
    }
    void func()
    {
        cout << "call from class C" << endl;
    }
};

// so now class d has access of public and protected attributes of class A, C.
class D : public C, public A
{
public:
    D()
    {
        cout << "constructor call from class D" << endl;
    }
    using C::func;
};

class E : public B
{
public:
};

class F : public C, public B
{
public:
    using A::func;
};

int main()
{

    cout << " Single Inherticance -----------------------------------------" << endl;
    // single inheritance
    /*
            A
            |
            B
    */
    B b;
    b.func();

    cout << endl
         << " Multiple Inherticance -----------------------------------------" << endl;
    // multiple inheritance
    /*
          A   C
           \ /
            D

    */
    D d;
    d.func();

    cout << endl
         << " Multi level Inherticance -----------------------------------------" << endl;
    // multi level inheritance
    /*
            A
            |
            B
            |
            E
    */
    E e;
    e.funca();
    e.funcb();

    cout << endl
         << " Hybrid Inherticance -----------------------------------------" << endl;
    // Hybrid inheritance
    /*
          A
          |
          B   C
           \ /
            F

    */
    F f;
    f.funcb();
    f.func();

    // cout << endl << "Hierarchical Inherticance -----------------------------------------" << endl;
    // multi level inheritance
    /*
             A
            / \
           B   C
          / \ / \
          D E F G
    */

    return 0;
}