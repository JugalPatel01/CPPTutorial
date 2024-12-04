#include <iostream>
using namespace std;

int main()
{
    int a[2][3][4];

    printf("Array is :  a[2][3][4]\n");
    printf("a[1][0] : %d \n", a[1][0]);
    printf("a[0][2] : %d\n", a[0][2]);
    printf("a[1][0] - a[0][2] = %lld \n", a[1][0] - a[0][2]);
    printf("size of a[1][0] is : %llu\n", sizeof(a[1][0]));
    printf("size of a[0][2] is : %llu \n", sizeof(a[0][2]));

    return 0;
}