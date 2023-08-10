/*

    * binary Exponentiation

    Q : calculate aⁿ

    -> recursive approch :
        case 1) : n is odd
                aⁿ = a^(n/2) * a^(n/2) * a
        case 2) : n is even
                aⁿ = a^(n/2) * a^(n/2)

    -> iterative approch :
      - start with variable x = 1. keep multiplying a with itself.
      - whenever there is 1 in binary representation of power, mulitply it with answer.
      eg. 2¹⁰
          we can write 10 as b"1010" in binary.
          1  0  1  0
          2³ 2² 2¹ 2⁰
          ans = 1,x = a;
          ans = 1, x= 2;
          1)
            x *= x
             x = 4
          2)
            ans = 1 * 4 = 4
             x *= 4
             x = 16
          3)
             x *= 16
             x = 256
          4)
             ans = 256 * 4 = 1024
             x *= 256
             x = 65536

    -> when we do multiplication for getting modulo like pᵃ % m so some time they are giving answer which are out of bound of
       data types. so to solve this kind of probelm we do some modulo arithmatic.
    # Properties of modulo express are :
    1) (a+b)%m = (a%m) + (b%m)
    2) (a-b)%m = (a%m) - (b%m)
    3) (a*b)%m = (a%m) * (b%m)
    4) (a/b)%m = (a%m) * (b⁻¹%m)


*/

#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long find_exponent_recursive(long long a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    long long sub_ans = (find_exponent_recursive(a, n / 2) % MOD);
    if (n % 2 == 0)
    {
        return (sub_ans * sub_ans) % MOD;
    }
    else
    {
        return (((sub_ans * sub_ans) % MOD) * a) % MOD;
    }
}

long long find_exponent_iterative(long long a, int n)
{
    long long ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    long long a, n;
    cout << "enter value of a into a^n : ";
    cin >> a;
    cout << "enter value of n into a^n : ";
    cin >> n;

    a = a % MOD;
    n = n % MOD;
    cout << "ans of " << a << "^" << n << " using recursive is : " << find_exponent_recursive(a, n) << endl;
    cout << "ans of " << a << "^" << n << " using iterative is : " << find_exponent_iterative(a, n) << endl;

    return 0;
}