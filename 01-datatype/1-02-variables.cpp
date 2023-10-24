/*

    # variables

    -> variables are name given to the memory locations.
    -> variable are case sensitive and contains letters, digits and underscores.
    -> variable names started with either letters or underscore.
    NOTE : we can't use keywords name(keywords like : auto, int, float, const,etc...) to variable.

    -> there are several types of variables.
    1) global variable  : live for whole process life cycle.
    2) local variable   : live for defined block or scope.
    3) instance variable : declared in the class and outside any method, or block.
                          for every object/instance there are different instance variables.
    4) static variable  : it is just like instance variable but we can use them without instance name and there is only one copy
                          of variable for all the instances.
                          They are created at the start of the program execution and distroy with program execution ends.

    To learn more about variables visit : https://cplusplus.com/doc/tutorial/variables/

    # storage classes

    -> The storage class specifiers are a part of the declaration syntax. Together with the scope of the name, they control two
       properties of the name : 1) its storage duration 2) it's linkage.
    -> There are totoal 6 types of storage classes.
            1) auto/ no specifiers : automatic storage duration.
                    scope : local
                    default value : garbage value
                    Memory location : RAM
                    lifetime : Till the end of its scope

            2) register : automatic storage duration. Also hints to the compiler to place the object in the processor's register 
                          for faster access.
                    scope : local
                    default value : garbage value
                    Memory location : register in CPU or RAM
                    lifetime : Till the end of its scope

            3) static : static or thread storage duration and internal linkage (or external linkage for static class members not 
                        in an anonymous namespace.)
                    scope : local
                    default value : 0
                    Memory location : RAM
                    lifetime : Till the end of the program

            4) extern : static or thread storage duration and external linkage.
                    scope : Global
                    default value : 0
                    Memory location : RAM
                    lifetime : Till the end of the program

            5) thread_local : thread stoage duration.
                    Memory location : RAM
                    lifetime : Till the end of its thread

            6) mutable : make variable constant volatile. (doesn't affact storage duration or linkage)

    NOTE : global or namespace scope is allocated for the entire duration of the program and stored as static storage.

    To learn more about storage classes visit
                                              : https://www.geeksforgeeks.org/storage-classes-in-c-with-examples/
                                              : https://en.cppreference.com/w/cpp/language/storage_duration

*/

#include <iostream>
using namespace std;

int x = 0; // global variable

class Types_Of_Variables
{
public:
    static int a; // static variable -> it's default value is 0.
    int b;        // instance variable  -> it doesn't have any default value so initially it has garbage value.
                  // created with instance and destroyed when instance is distroyed and can be used by object name only.
    Types_Of_Variables()
    {
        int x = 99; // local or scope variable.
        b = x;
    }
};

int Types_Of_Variables::a = x;

int main()
{
    int x = 10; // local or scope variable and it's scope is only for main variable
    // we can't use above variable outside main function.
    {
        // here we can't change y because it has mutable storage class
        const int y = 20;
        cout << "value of x & y is : " << x << "  &  " << y << endl;
    }

    // cout << "value of x & y is : " << x << "   " << y << endl;
    /*
        if we uncomment above line then it gives us error because the scope of variable y is inside that block not outside that block.
    */

    Types_Of_Variables check;
    cout << "value of a & binside object check is a => " << check.a << " & b =>" << check.b << endl;

    int m = (10, 20, 30, 40, 60), n;
    n = 10, 20, 30, 40, 50, 60;

    cout << "after assigning multiple values using brackets m's value is : " << m << endl;
    cout << "after assigning multiple values without using brackets n's value is : " << n << endl;

    return 0;
}