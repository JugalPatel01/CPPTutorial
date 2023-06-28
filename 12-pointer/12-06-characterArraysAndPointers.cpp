/*
    Character arrays and pointers

    (size of an array for storing string of n char) >= n+1
    for "world" string we need an array of size 6.
    because "world" = {'w','o','r','l','d','\0'}

    -> character arrays and pointers are different types that are used in similar manner.
    -> Arrays are always passed to function by reference
*/
#include <iostream>
#include <string.h>
using namespace std;
int main()
{

    char c[] = "Jug"; // {'J','u','g','\0'}

    char *c2;

    c2 = c;
    cout << "second element of the string is : " << (c2[1]) << endl;

    int len = strlen(c);
    cout << "size of character array is : " << sizeof(c) << endl;
    cout << "length of string is : " << len << endl;
    printf("string is : %s", c);
    return 0;
}