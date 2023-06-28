/*
   NOTE:--- must watch operator precendence on https://en.cppreference.com/w/cpp/language/operator_precedence

    relational operator ==,!=,>,<,>=,<=

    logical operator &&,||,!

    binary opertors +,-,*,/,%

    uninary operator ++,--   These have two types 1) preincrementer and 2) postincrementer

    bitwise operator & and,| or,^ xor ,~ ones ,<< left shift,>> right shift

    assignment operators =,+=,-=,*=,/=

    miscellaneous opertors sizeof() --> userdefined operator,condition?x:y --> ternary operator
 
    cast operator --> convert one data type to another e.g. char ch='a';--> gives  (int)ch=97;
   
    reference opertor(&) and pointer(*) --> giving addrees of a variable and pointer to a variable

*/

#include <iostream>
using namespace std;
int main()
{

    int a = 1;
    int b, c;
    b = a++; // Postincrementer
    a = 1;
    c = ++a; // Preincrementer
    cout << "a=1 after post increment " << b << " and a is " << a << "\n"
         << "a=1 after pre increment " << c << " and a is " << a << endl;

    return 0;
}