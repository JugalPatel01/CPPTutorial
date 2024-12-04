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

    /*

    NOTE : post-increment is may be not as efficient as pre-increment.
         : For trivial datatypes it will not make much difference.
         : But for user defined datatypes like class, or structure, which implements operator ++ make visible difference because in that operator++ method we have to create a temporary variable for storing actual value(we have to create a deep copy of the object) then we have to increase that value and after that we are returning that temporary variable in post increment/decrement. If temporary variable holding a large string then it cost memory and time.
            : eg.
                    int i = 0;
                    // for pre-increment we are passing without any parameter
                    int i{0};
                    i.operator++();     // equal to ++i;

                        // ++ operator overloading method in some class
                            int operator++(){
                                i = i + 1;
                                return i;
                            }
                
                
                    // for post-increment we are passing parameter which takes some cost.
                    int i{0};
                    i.operator++(0);
                        // ++ operator overloading method in some class
                            int operator++(int){
                                int temp = i;
                                i = i+1;
                                return temp;
                            }
                    // in post-increment we are creating temporary object which takes some extra cost.


    */

    // in sizeof function it takes only data type of variable so increment operator will not work in sizeof function.
    cout << "size of a++ is " << sizeof(a++) << endl;
    cout << "after incrementing a in sizeof function value of a is : " << a << endl;

    return 0;
}