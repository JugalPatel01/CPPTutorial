#include <iostream>
using namespace std;

int fun()
{
    static int x = -5;
    // printf("x++ = %d   ",x++);
    // printf("++x = %d   ",++x);
    // printf("%d",x++);
    // return x;
    // return ++x;
    return x++;
}

int main()
{

    for (fun(); fun(); fun())
    {
        printf("%d", fun() * fun());
    }

    if (-1)
    { // if return true for all non zero elements
        cout << endl;
        cout << "it is working" << endl;
    }

    return 0;
}