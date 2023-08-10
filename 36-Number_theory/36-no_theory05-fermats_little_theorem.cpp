/*


    * wilson's theorem
    - A positive intgeter n > 1 is a prime if and only if
        (n-1)! ≡ n-1(mod n)         OR
        (n-1)! ≡ -1(mod n)
    -> eg. 101 is prime number, so we can conclude that 28! = 29*k - 1 for some integer k.

    # Application of wilson's theorem
    - eg. calculate (15! % 17)
      from wilson's theorem, we know that 16! % 17 is -1.
      so we have to find [(-1) * inverse(16,17)] % 29

    NOTE : To calculate modulo multiplicative inverse we can use fermat's little theorem.

    * Fermat's little Theorem
    - Fermat's little theorem  states that if p is a prime number, then for any integer a, the number aᵖ - a is an integer
      multiple of p.

            aᵖ ≡ a (mod p)

        if a is not divisible by p then
            aᵖ⁻¹ ≡ 1 (mod p)

    # applications of fermat's little theorem
    -> To find modulo inverse of a number
            aᵖ⁻² ≡ a⁻¹ (mod p)
    -> find modulo of division operator
            (a/b) % m = ((a % m) * (b⁻¹ % m)) % m
    -> TO evaluate (ⁿCᵣ) % p
            ⁿCᵣ = n!/(n-r)!*r!

        here two cases are possible :
        case 1 : p > n
        1) pre-calculate factorials taking modulo p
        2) (ⁿCᵣ) % p = (factorial[n] * (modulo_inverse(factorial[r]) % p) * (modulo_inverse(factorial[n-r]) % p)) % p

        case 2 : p <= n
        here, ⁿCᵣ contain p in that and if we do mod operation with multiple of p then we get 0 remainder.

*/

/*
    * Q : Given a prime number P and integer N close to P. find N! modulo P. (Abs(N-P) <=1000)
     i/p : p = 23, n = 21
     o/p : 1

    approach :
        case 1) : if n >= p
        then n! % p = 0 , because n! % p = (1*2*3*...*p*...*n) % p = 0
        case 2) if n < p
        here we use wilson's theorem
        - iterate from p-1 to n+1
        and find answer, initially ans = p-1 because of wilson's theorem
         ans = (ans*modulo_inverse(i,p)) % p
         here, we use fermat's theorem to find out modulo_inverse

    NOTE : time compelxity of above approach is O((P-N)*logN)

*/
#include <iostream>
using namespace std;

int modulo_inverse(long long x, int p)
{
    // xᵖ⁻² ≡ x⁻¹ (mod p)
    int a = p - 2;
    int res = 1;
    x = x % p;
    while (a > 0)
    {
        if (a & 1)
        {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        a = a >> 1;
    }
    return res;
}

int find_modulo(int n, int p)
{
    if (n >= p)
    {
        return 0;
    }
    int ans = p - 1;
    for (int i = p - 1; i > n; i--)
    {
        ans = (ans * modulo_inverse(i, p)) % p;
    }
    return ans;
}

int main()
{
    int n, p;
    cout << "Enter value of prime number p : ";
    cin >> p;
    cout << "  and number n : ";
    cin >> n;

    /*
        sample input : 101 91
    */

    cout << n << "! % " << p << " is : " << find_modulo(n, p) << endl;
    return 0;
}