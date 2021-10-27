#include <iostream>
using namespace std;
int main()
{

    char a = 'A';        // here A is assigned to character a
    char c = int(a) + 5; // here we assigned ascii value 65 + 5 = 70 to character c so it give result F
    int d = a + 5;       // here we get integer value so we get 65 + 5 = 70 as integer d
    cout << a << endl;
    cout << int(a) << endl;
    cout << c << endl;
    cout << d << endl;
    cout << a + 5 << endl; // here we add 5 to ascii value of a so according to the property of cout function we get 70
    if (a == c - 5)
    {
        cout << "equal" << endl;
    }
    if (a == int(c) - 5)
    {
        cout << "equal" << endl;
    }
    if (d == c)
        cout << "equal " << d << " " << c << endl;

    if (d == int(c))
        cout << "equal" << endl;

    if (65 == 'A') // here we can compair integer and character in if because of the implicit typecasting
        cout << "equal" << endl;
    else
        cout << "bye" << endl;

    cout << 'A' << endl;

    return 0;
}