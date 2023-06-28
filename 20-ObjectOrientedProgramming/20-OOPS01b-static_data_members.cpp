/*
    charachteristics of static data members:
    1) Only one copy of that member is created for the entire class and is shared by all objects of that class
    2) it is initialized before any object of this class is created, even before the main function starts.
    3) It is visible only within the class, but its lifetime is the entire program.

 */

#include <iostream>
using namespace std;

class A
{
    int x;
    static int count;

public:
    A()
    {
        count++;
        cout << "A's constructor called " << count << " " << endl;
    }

    static void getCount()
    {
        // static mehtods can access static variables only they don't have access of non-static varialbes.
        cout << "value of the count varialbe is : " << count << endl;
    }
};

class B
{
    static A a;

public:
    B()
    {
        cout << "B's constructor called " << endl;
    }
    static A getA()
    {
        return a;
    }
};
// we have to initialize static varible outside the class
int A::count = 10; //(by default it's value is zero)
A B::a;

int main()
{
    cout << " static data memebers " << endl;
    A w, x, y, z; // here w,x,y,z shares count varialbe rather than making different copies of count variable.

    // accessing static methods wihtout any object
    cout << "static functions " << endl;
    A::getCount();
    A a = B::getA();
    a.getCount();
    return 0;
}