#include <iostream>
using namespace std;
int reverse(int a)
{
    int ans = 0;
    while (a > 0)
    {
        int lastdigit = a % 10;
        ans = ans * 10 + lastdigit;
        a /= 10;
    }
    return ans;
}
int addBinary(int a, int b)
{
    int ans = 0;
    int prevCarry = 0;

    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (b % 2 == 0 && a % 2 == 1))
        {
            if (prevCarry == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        else if (a % 2 == 1 && b % 2 == 1)
        {
            if (prevCarry == 1)
            {
                ans = ans * 10 + 1;
                prevCarry = 1;
            }
            else if (prevCarry == 0)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
        }
        a /= 10;
        b /= 10;
    }
    while (a > 0)
    {
        if (prevCarry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2);
            prevCarry = 0;
        }
        a /= 10;
    }
    while (b > 0)
    {
        if (prevCarry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2);
            prevCarry = 0;
        }
        b /= 10;
    }
    if (prevCarry == 1)
    {
        ans = ans * 10 + 1;
    }

    ans=reverse(ans);
    return ans;
}
int main()
{
    int a, b;
    cout << "enter first binary number ";
    cin >> a;
    cout << "enter second binary number ";
    cin >> b;
    cout << addBinary(a, b) << endl;

    return 0;
}