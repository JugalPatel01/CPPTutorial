/*
    Here dangling pointer is pointing to out of scope variable which is not directly accessible but through this dangling pointer we can
    still access that variable
*/

#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int *ptr = NULL;
    cout << "Address of a " << &a << endl;
    {
        // inner scope
        int b = 700; // assinging value to b
        cout << "Address of b " << &b << endl;
        ptr = &b;
        cout << "value of ptr at inner scope = " << ptr << endl;              // print address of b in ptr
        cout << " value at ptr address at inner scope is = " << *ptr << endl; // print value of b at address which is assinged to ptr
    }
    cout << " value of ptr at outer scope = " << ptr << endl;             // scope of b is over still pointing to b
    cout << " value at ptr address at outer scope is = " << *ptr << endl; // directly b is not accessible but it accessed by this pointer.

    return 0;
}