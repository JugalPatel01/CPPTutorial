#include <iostream>
#include <string.h>
using namespace std;
int main()
{

    char c[] = "JOHN"; // {'J','u','g','\0'}

    char *c2;

    c2 = c;
    cout << (c2[1]);

    int len = strlen(c);
    cout << sizeof(c);
    cout << len;
    printf("%s", c);
    return 0;
}