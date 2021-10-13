// the memory that is assinged to program in architecture in 4 parts

// 1. Instructions (code)
// 2. Static / Global variables
// 3. stack (static memory assigned at compile time for program by os)
// 4. Heap (dynamic memory) (free pool of memory)
#include <iostream>
using namespace std;
int main()
{
    //for c
    //malloc // it returns void pointer
    //calloc
    //realloc
    //free

    // for c++
    //new
    //delete

    int a; // goes on stack
    int *p;
    p = new int;
    *p = 10;
    delete p;
    p = new int[20];
    *p = 10;
    delete[] p;        // if we want free an array then we use delete
    cout << p << endl; // it prints address of the heap memory
    cout << *p;        // it print any garbage value

    return 0;
}