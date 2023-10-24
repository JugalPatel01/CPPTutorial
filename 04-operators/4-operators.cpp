/*
   NOTE:--- must watch operator precendence on https://en.cppreference.com/w/cpp/language/operator_precedence

    P - postfix/parenthesis () , [] , ++ , --   (post increment, post decrement)

    U - uninary operator + , - , typeof(), sizeof(), *(pointer) , &(reference opeartor) , ++,-- (preincrement, predecrement)

    M - multiplicative operator(binary operator) *, / , %

    A - additive operator(binary operator) + , -

    S -shift operator <<(left shift),>>(right shift)

    R - relational operator >,<,>=,<=

    E - equality operator ==,!=

    B - bitwise opertors & (bitwise and), ^(bitwise xor) , |(bitwise or)

    L - logical operator && , ||

    T - Ternary opeartor ? : (eg. condition?x:y)

    A - assignment operators =,+=,-=,*=,/=

    comma opeartor ,

    operator precedence 
    (pumas)    (reb) (lee) (tactical)
    P U M A S  R E B   L     T A C      => left to right precedence

    T(ternary) A(assignment) U(uninary) ^/ **(exponential) => right to left precedence

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