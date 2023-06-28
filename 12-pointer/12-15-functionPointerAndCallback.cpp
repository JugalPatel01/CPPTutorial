/*
    Function pointers and callbacks
*/
#include <iostream>
using namespace std;
void A()
{
    printf("Hello");
}
void B(void (*ptr)()) // function pointer as argumnet
{
    ptr(); // call-back function that "ptr" points to
}
int main()
{

    // void (*P)() = A;
    // B(P);

    B(A); // A is callback function
    return 0;
}