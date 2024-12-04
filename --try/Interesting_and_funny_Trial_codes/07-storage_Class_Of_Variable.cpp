/*
    There are 4 storage Class for variable in C
    1)auto          life time : at the time of function termination   scope : within the function
    2)static        life time : at the time of program termination    scope : within the function
    3)extern        life time : at the time of program termination    scope : Entire the file and other files where the variable is decalred as extern
    4)register      life time : at the time of function termination   scope : within the function

*/

#include <iostream>
#define deb(x) cout << #x << " = " << x << " -> " << &x << endl;
using namespace std;

void function()
{
    int a = 15;         // it is default and it terminate at the time of function termination
    static int b = 10;  // static like a global variable but scope is not global, it will terminate at the time of the program termination
    register int c = 4; // for faster access of c because it store on the register instead of RAM.
    ++a;
    ++b;
    ++c;
    cout << "auto a = " << a << endl;
    cout << "static b = " << b << endl;
    cout << "register c = " << c << endl;
    cout << endl;
}

int main()
{
    function();
    function();
    function();

    return 0;
}