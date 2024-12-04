/*

    Initialisation of variables in different way


*/

#include <iostream>
using namespace std;

int main()
{
    int i1;              // undefined value -> gives garbage value
    int i2 = 1;          // inits with 1
    int i3(3);           // inits with 3
    int i4 = int();      // inits with 0
    int i5{35};          // inits with 35
    int i6 = {35};       // inits with 35
    auto i7{35};         // auto init with 35
    int i8();            // declares a function
    auto i9 = (7, 8, 9); // inits int with 9 (comma operator) (operator precedence)

    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;
    cout << "i3 = " << i3 << endl;
    cout << "i4 = " << i4 << endl;
    cout << "i5 = " << i5 << endl;
    cout << "i6 = " << i6 << endl;
    cout << "i7 = " << i7 << endl;
    cout << "i8 = " << i8 << endl;
    cout << "i9 = " << i9 << endl;
    
    return 0;
}