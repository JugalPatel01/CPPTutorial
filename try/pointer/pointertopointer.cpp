#include <iostream>
using namespace std;
int main()
{

    int x = 5;
    int *p;
    p = &x;
    int **p0;
    p0 = &p;
    printf("%d\n", p);
    printf("%d\n", *p);

    printf("%d\n", p0);
    printf("%d\n", *p0);
    printf("%d\n", **p0);
    return 0;
}