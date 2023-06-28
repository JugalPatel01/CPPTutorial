/*
    as we have a problem definition of diamond-problem in 20-OOPS2c-diamond-problem we can solve diamond problem using the help of virtual keyword


    explaination of solution :
    -> when we use virtual keyword, the default constructor of grandparent class is called by default even if the parent classes explicitly call parameterized constructor.

    -> so if we wan't to call parameterized constructor of the grandparent class we have to call that constructor in the initializer list of grandchild class's constructor
*/

#include <iostream>
using namespace std;
class A
{
public:
    A(int x) { cout << "A::A(int ) called" << endl; }
    A() { cout << "A::A() called" << endl; }
};

class B : virtual public A
{
public:
    B(int x) : A(x)
    {
        cout << "B::B(int ) called" << endl;
    }
};

class C : virtual public A
{
public:
    C(int x) : A(x)
    {
        cout << "C::C(int ) called" << endl;
    }
};

class D : public B, public C
{
public:
  
    D(int x) : C(x), B(x)
    {
        cout << "D::D(int ) called" << endl;
    }
  
/* 
// for calling parameterized constructor of grandparent class
    D(int x) : C(x), B(x), A(x)
    {
        cout << "D::D(int ) called" << endl;
    }
 */
};

int main()
{
    D d(30);
}