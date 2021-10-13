#include <iostream>
using namespace std;
int main()
{
    int a = 1025;
    int *p;
    p = &a;
    printf("%d\n", p + 1);
    printf("%d\n", p);
    cout << *p << endl;
    char *p0;
    p0 = (char *)p;
    printf("%d\n", p0);
    printf("%d\n", p0 + 1);
    printf("%d\n", *p0);

    //void pointer - genric poitner
    void *p1;
    p1 = p;
    printf("%d", p1);

    return 0;
}