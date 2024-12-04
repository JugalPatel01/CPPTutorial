#include <iostream>
using namespace std;

void mystery(int *ptra, int *ptrb)
{
    int *temp;
    temp = ptrb;
    ptrb = ptra;
    ptra = temp;
    // below code will swap the values of the variables
    // *temp = *ptrb;
    // *ptrb = *ptra;
    // *ptra = *temp;
}

int main()
{
    int a = 10, b = 0, c = 4, d = 43;

    mystery(&a, &b);

    if (a < c)
    {
        mystery(&c, &a);
    }

    mystery(&a, &d);
    cout << "value of a is " << a;

    return 0;
}