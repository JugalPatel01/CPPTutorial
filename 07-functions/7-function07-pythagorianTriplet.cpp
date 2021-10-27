#include <iostream>
using namespace std;


void pyth(int x, int y, int z)
{
    int a = max(x, max(y, z));
    int b, c;
    if (a == x)
    {
        b = y;
        c = z;
    }
    else if (a == y)
    {
        b = x;
        c = z;
    }
    else if(a==z)
    {
        b = x;
        c = y;
    }

    (a * a) == (b * b) + (c * c) ? cout << "These numbers are pythagorian triplets." : cout << "These numbers are not pythagorian triplets.";
}

int main()
{
    int a, b, c;
    cout << "enter two side and diagonal of the traingle ";
    cin >> a >> b >> c;
    pyth(a, b, c);

    return 0;
}