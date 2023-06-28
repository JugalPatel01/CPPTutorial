#include <iostream>
using namespace std;
int main()
{

    int x = 5;
    int *p;
    p = &x;
    int **p0;
    p0 = &p;
    printf("%d\n", p);  // address of pointed value(address of x)
    printf("%d\n", *p); // value stored in p pointer (here it is x)

    printf("%d\n", p0);     // address of pointed pointer (address of p)
    printf("%d\n", *p0);    // address of pointed pointers' stored value ( address of x)
    printf("%d\n", *(*p0)); // value stored in pointed pointer (here it is x)

    **p0 = 15;
    cout << x;
    return 0;
}