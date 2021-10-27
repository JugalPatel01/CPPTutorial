/*
        Dangling pointer : A pointer which points to the unallocated memory or out of scope memory is called dangling pointer.

*/

#include <iostream>
using namespace std;
int *fun(void)
{
    int b = 7;
    return &b;
}
int main()
{
    int a = 5;
    int *ptr = NULL;                       // here we assign a NULL pointer
    cout << "Address of a " << &a << endl; // addresss of a
    ptr = fun();                           // calling pointer function fun which returns address of b

    /* here after calling function fun, fun is unallocated from the stack of the program so also value of b is also unallocated and
    and we get address of unallocated variable b in pointer ptr, so pointer ptr points to the unallocated memory it called a dangling pointer.*/

    cout << *ptr << endl; // here at compilation time we get warning for that dangling pointer or it gives segmentation fault error.

    return 0;
}