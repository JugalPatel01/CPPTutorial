// pointers are variables that store the address of other varibales.

#include <iostream>
using namespace std;
int main()
{
    int a = 1025;   
    int *p;         // value at address(derefrencing)
    p = &a;
    printf("%d\n", p + 1);
    printf("%d\n", p);
    cout << *p << endl;
    char *p0;
    p0 = (char *)p;         // type casting of the pointer
    printf("%s\n", p0);         // it will print 00000001
    printf("%d\n", p0 + 1);     // it will print 00000100
    printf("%d\n", *p0);
    // 1025 = 00000000 00000000 00000100 00000001

    // void pointer - genric poitner
    void *p1;
    p1 = p;
    printf("%d", p1);

    return 0;
}