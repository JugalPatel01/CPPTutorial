/*
    * function pointers
    -> pointers can point to variables and functions
    -> we use function pointers for callbacks and passing function as an argument
 */
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}
void printHello(char *name)
{
    cout << "Hello " << name << endl;
}

int main()
{

    int (*p)(int, int);
    p = add; // same as p = &add
    int c;
    c = p(2, 3); // same as c = (*p)(2,3);
    cout << c;

    void (*ptr)(char *);
    ptr = printHello;
    ptr("Jugal");

    return 0;
}