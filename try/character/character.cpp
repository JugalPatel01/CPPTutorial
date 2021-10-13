#include <iostream>
using namespace std;
int main()
{

    char a = 'A';
    char c = int(a) + 5;
    int d = a + 5;
    cout << a << endl;
    cout << int(a) << endl;
    cout << c << endl;
    cout << d << endl;
    cout << a + 5 << endl;
    if (a == c - 5)
    {
        cout << "equal" << endl;
    }
    if (a == int(c) - 5)
    {
        cout << "equal" << endl;
    }

    return 0;
}