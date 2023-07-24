/*

    * variables

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
        int y = 20;
        cout << "value of x & y is : " << x << "  &  " << y << endl;
    }

    // cout << "value of x & y is : " << x << "   " << y << endl;
    /*
        if we uncomment above line then it gives us error because the scope of variable y is inside that block not outside that block.
    */

    Types_Of_Variables check;
    cout << "value of a & binside object check is a => " << check.a << " & b =>" << check.b << endl;
    return 0;
}