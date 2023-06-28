/*
    * Information about Basic Datatypes in C++

    we can classify datatypes in 2 categories
    1) primary (primitive)
    - Void
    - Character
    - Integer
    - Floating Point
    - Double Floating Point

    2) Derived
    - Function
    - Array
    - Pointer
    - Reference

    3) User Defined
    - Class
    - Structure
    - Union
    - Enum
    - Typedef

 */

#include <iostream>
using namespace std;
int main()
{

    cout << "---------This is datatypes's information--------------" << endl;
    int a;
    char b;
    float c;
    bool d;
    double e;
    unsigned int f;
    long int g;
    short int h;
    long long i;
    long double j;

    // size of the datatypes vary from Operating system to Operating system this is for 64 bit operating system.

    cout << "The size of the integer is " << sizeof(a) << endl;           // size = 4 bytes
    cout << "The size of the char is " << sizeof(b) << endl;              // size = 1 bytes
    cout << "The size of the float is " << sizeof(c) << endl;             // size = 4 bytes
    cout << "The size of the bool is " << sizeof(d) << endl;              // size = 1 bytes
    cout << "The size of the double is " << sizeof(e) << endl;            // size = 8 bytes
    cout << "The size of the unsigned integer is " << sizeof(f) << endl;  // size = 4 bytes
    cout << "The size of the long integer is " << sizeof(g) << endl;      // size = 4 bytes
    cout << "The size of the short integer is " << sizeof(h) << endl;     // size = 2 bytes
    cout << "The size of the long long integer is " << sizeof(i) << endl; // size = 8 bytes
    cout << "The size of the long double is " << sizeof(j) << endl;       // size = 12 bytes
    return 0;
}