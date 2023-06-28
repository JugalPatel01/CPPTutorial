/*
    Types of pointer
    1) wild pointer -> A pointer that has not been initialized to anything
    2) Null pointer ->  A pointer pointing to NULL
    3) dangling pointer ->  A pointer pointing to a memory location that has been deleted (or freed)
*/

#include <iostream>
using namespace std;
int main()
{
    int a = 500;
    int *ptr; // wild pointer
    cout << "address of a = " << &a << endl;
    cout << "address of ptr before memory allocation= " << ptr << endl; // giving us garbage address
    cout << "value at ptr before memory allocation= " << *ptr << endl;  // giving us garbage value
    cout << endl;

    ptr = &a;
    cout << "address of ptr after allocation = " << ptr << endl;
    cout << "value at ptr after allocation = " << *ptr << endl;

    free(ptr);  // after this free call ptr becomes a dangling pointer
    ptr = NULL; // to remove dangling pointer point that pointer to NULL

    int *ptr1 = NULL;                                         // NULL pointer
    cout << "address of null pointer ptr1= " << ptr1 << endl; // giving us address 0
    // cout<< "value at  null pointer ptr1 = " << *ptr1 << endl;   // it gives segmentation falut or termination of program

    return 0;
}