/*
    Divide A number without using multiplication, division and modular operator
    and print quotient
 */

#include <iostream>
#include <math.h>
using namespace std;

long long divide_number(long long dividend, long long divisor)
{
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    long long quotient = 0, temp = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (temp + (divisor << i) <= dividend)
        {
            temp += divisor << i;       // add just like building number
            quotient += 1LL << i;       // add 2^i
        }
    }
    if (sign == -1)
        quotient = -quotient;
    return quotient;
}

int main()
{
    cout << "enter dividend and divisor : ";
    long long dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide_number(dividend, divisor);
    return 0;
}