/*
    Pointers as function arguments - call by reference

    Application's memory
    ___________
    |  heap   |     -> free pool of memory
    |_________|
    |  stack  |     -> stack for function calls & scope level variable
    |_________|
    |  global |     -> store global variables of the program
    |_________|
    |  code   |     -> store code part of the program
    |_________|

    -> here if we don't use call by reference and use call by value then that value's local variable will take place in stack
       and after function execution that function and variable both will discarded from the memory stack.so changes which are
       made by that variable will also be discard.
    -> To remove such kind of issue we pass values as a reference. in these case copy of address will take place in the stack
       and if we dereference that address then we get the actual value. so if we change that dereferenced memory address then it will directly affact that varialbe.
    -> after function execution that copy of address variable will discard from the stack memory. but that change which we was made through that address varialbe will remain as it is.

    in below code we can see that :>

*/

#include <iostream>
using namespace std;
void Increment_by_reference(int *a) // call by reference
{
    *a = *a + 1; // here a is address and *a is dereferenced memory location of a.
}

void Increment_by_value(int a)
{
    a = a + 1; // here local copy of will change
}

int main()
{

    int a = 10;
    Increment_by_value(a);
    cout << "value of a after increasing it by call by value function : " << a << endl;
    Increment_by_reference(&a); // here we pass address of the variable a so that while we assign the value to the function it dereferenced it to a and then all the action are perfomed on the a not the assigned value like call by value.
    cout << "value of a after increasing it by call by reference function : " << a << endl;
    return 0;
}