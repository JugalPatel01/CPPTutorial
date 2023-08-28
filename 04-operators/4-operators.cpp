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
    a = 1;
    cout << "a=1 after post increment a is " << a++ << endl;
    cout << "a=2 after pre increment a is " << ++a << endl;

    // in sizeof function it takes only data type of variable so increment operator will not work in sizeof function.
    cout << "size of a++ is " << sizeof(a++) << endl;
    cout << "after incrementing a in sizeof function value of a is : " << a << endl;

    return 0;
}