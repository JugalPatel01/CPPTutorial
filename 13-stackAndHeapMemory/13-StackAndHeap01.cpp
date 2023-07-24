/*

    * stack and heap dynamic memory allocation
*/

#include <iostream>
using namespace std;
static int x; // stored in(uninitialized data segment (BSS{block started by symbol}))
int y;        // stored in bss segment
int z = 10;   // stored in the initialized data segment
int main()
{

    int a = 10;         // stored in stack
    int *p = new int(); // allocated memory in heap
    *p = 10;
    delete p; // deallocate memory from heap
    p = new int[4];
    delete[] p;
    p = NULL;

    return 0;
}