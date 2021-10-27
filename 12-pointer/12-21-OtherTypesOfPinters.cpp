/*
    Types of pointer
    1) wild pointer
    2) Null pointer
    3) dangling pointer
*/

#include <iostream>
using namespace std;
int main() {
    int a = 500;
    int *ptr;       // wild pointer
    cout<< "address of a = " << &a <<endl;
    cout<< "address of ptr before memory allocation= " << ptr << endl;  // giving us garbage address 
    cout<< "value at ptr before memory allocation= " << *ptr << endl;   // giving us garbage value
    cout<<endl;
    ptr = &a ;
    cout<< "address of ptr after allocation = " << ptr << endl;
    cout<< "value at ptr after allocation = " << *ptr << endl;

    int *ptr1 = NULL;
    cout<< "address of null pointer ptr1= " << ptr1 << endl;  // giving us address 0
    // cout<< "value at  null pointer ptr1 = " << *ptr1 << endl;   // it gives segmentation falut or termination of program
    
    
    

return 0;
}