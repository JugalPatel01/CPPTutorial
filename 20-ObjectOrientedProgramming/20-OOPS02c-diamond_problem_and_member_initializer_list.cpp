/*
    THe diamond problem occurs when two superclasses of a class have a common base class.

                                A
                               / \
                              B   C
                               \ /
                                D
        in above diagram D class gets two copies of all attributes of A class, this causes ambiguities.

    --> The solution to this problem is 'virtual' keyword. We make the classes B and C as virtual base class es to avoid two copies of A class in D class.

    * What is Member initializer list ? what is the use of the : ?
    -> it's an initialisation list.
    we case use it for few things:
    1) calling base class memebers (including constructor)
    2) initialising member variables before the body of the constructor executes.
    3) class has a reference member
    4) when class has a non static const member
    5) class doesn't have default constructor

    for case 2) : the question may be arrived that "Why not just initialise it in the body of the constructor?" The importance of the initialisation lists is particularly evident for const members.for instance
    eg.

    class A{
        A(int& val){
            a_val = val;
        }
        private :
            const int& a_val;
    }

    above thing is illegal and we get error because we can't change the value of the const variable in the constructor, becuase it is marked as const.so we can use the initialisation list:

    class A {
        A(int& val) : m_val(val){}
        private:
        const int& m_val;
    }

    This is the only time that we can change a const memeber variable


    * What is difference between member initialization and member assignment? 
    -> cost of Member Initialization = Object Construction 
    -> cost of Memeber Assignment = Object Construction + Assignment
*/

#include <iostream>
using namespace std;
class A
{
public:
    A(int x)
    {
        cout << "A::A(int ) called" << endl;
    }
};

class B : public A
{
public:
    B(int x) : A(x)
    {
        cout << "B::B(int ) called" << endl;
    }
};

class C : public A
{
    // data members of Student
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
};

int main()
{
    D d1(30);

    return 0;
}