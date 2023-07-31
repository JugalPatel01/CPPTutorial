/*

  *  Euclid Algo to find GCD(greatest common divisior)

    # bruteforce approach to find gcd
    24=2*2*2*3
    42=2*3*7

    # Euclid's algo for finding gcd

    gcd(A,B) = gcd(B, A-B)
    -> because if d is gcd of A and B then A/d and B/d give us an integer
    -> now if we add or subtract both number then also it is divisible by d. (A+B)/d

    gcd(42,24) = gcd(24,18)
    42-24=18
    gcd(24,18) = gcd(18,6)
     24-18=6
    gcd(18,6) = gcd(12,6)
     18-6=12
    gcd(12,6) = gcd(6,6)
     12-6=6
    now we got gcd(6,6) both numbers are same.
     6-6=0
     so gcd is 6.

 */
#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{

    cout << "enter two no. for finding gcd : ";
    int a, b;
    cin >> a >> b;

    cout << "gcd of two number is " << gcd(a, b) << endl;

    return 0;
}