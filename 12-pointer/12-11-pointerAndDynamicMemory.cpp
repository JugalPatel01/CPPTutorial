/*

    *  the memory that is assinged to program in architecture in 4 parts
    ___________
    |  heap   |     -> (dynamic memory) (free pool of memory)
    |_________|
    |  stack  |     -> stack for function calls & scope level variable (static memory assigned at compile time for program by os)
    |_________|
    |  static |     -> static variables
    |  global |     -> global variables of the program : live for whole program life cycle.
    |_________|
    |  code   |     -> Instructions (code) : store code part of the program
    |_________|

 */

#include <iostream>
using namespace std;
int main()
{
    /*
        allocating and deallocating heap memory
        c function for allocating and deallocating memory in heap :
        malloc -> it returns void pointer so we have to do typecase everytime while using malloc
        calloc
        realloc
        free -> to free occupied heap memory

        c++ opeartor for allocating and deallocating memory in heap :
        new -> for new memory in heap. it is type safe
        delete -> for deleting memory from heap
     */

    int a; // it will go in the memory stack

    int *p;
    p = new int;
    *p = 10;
    delete p;
    p = new int[20];
    *p = 10;
    delete[] p; // if we want free an array then we use delete
    cout << "address of free p in heap memory : " << p << endl;
    cout << "value of free p variable : " << *p; // it print any garbage value

    return 0;
}