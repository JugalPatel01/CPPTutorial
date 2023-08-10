/*

    * Eular Totient Function : [Φ(n)]
    -> It counts the positive integers up to a given integer n that are relatively prime to n.
    -> means it is the number of integers k in the range 1 ≤ k ≤ n for which the greatest common divisor gcd(n, k) is equal to 1.


    Φ(n) = n*(1 - 1/p₁)*(1 - 1/p₂) ... (1 - 1/pₖ) where p₁,p₂,...,pₖ are distinct prime factors of n.   ..........(a)

    # property of Eular Totient function:
    -> If A and B are coprime or gcd(A,B) = 1 then, Φ(A*B) = Φ(A)*Φ(B)

    # proof of equation a,
    so,
        n = p₁ᵃ*p₂ᵇ*...*pₖᶜ
       Φ(n) = Φ(p₁ᵃ*p₂ᵇ*...*pₖᶜ)    ...........................(1)

    we know that gcd(p₁ᵃ,p₂ᵇ) = 1

    so, we can write equation (1) as:
       Φ(n) = Φ(p₁ᵃ)*Φ(p₂ᵇ)* ... * Φ(pₖᶜ)    ...........................(2)

    now,
     Φ(pᵃ) = pᵃ - (total no of multiple of p)                   .....................(z)
           = Numbers from 1 to pᵃ which are not coprime with pᵃ are p,2p,3p,...pᵃ.

    above series is an arithmatic serires with common difference of p

    so,  pᵃ term in AP is
            pᵃ = p + (x-1)*p
            (pᵃ - p) / p = x -1
            pᵃ⁻¹ - 1 + 1 = x
            x = pᵃ⁻¹

    now we put x's value in equation (z) then we get
    Φ(pᵃ) = pᵃ - (total no of multiple of p)
          = pᵃ - pᵃ⁻¹
          = pᵃ(1-(1/p)) ...............................(y)

    now if we use equation (y) in equation (2) then
       Φ(n) = Φ(p₁ᵃ)*Φ(p₂ᵇ)* ... * Φ(pₖᶜ)    ...........................(2)
            = p₁ᵃ*(1-1/p₁)*p₂ᵇ*(1-1/p₂)* ... * pₖᶜ*(1-1/pₖ)
            = n * (1-1/p₁)*(1-1/p₂)* ... *(1-1/pₖ)                      because (n = p₁ᵃ*p₂ᵇ*...*pₖᶜ)

    # implementation of Eular-Totient-Function :
    -> it is just like 16-SeiveOfEratostheness-primeFactorisation
    -> declare an array of size n+1
    -> initialize the array with arr[i] = i
    -> iterate from 2 to sqrt(n) and check if(arr[i] == i), if yes, thta means it is a prime number because it is not touched by
       previous numbers during their iteration. change it to arr[i] - 1 and multiply all its multiple with(1-1/arr[i]).
    -> at the end we have our array with totient values.

*/
#include <iostream>
#include <vector>
using namespace std;

int find_coprimes(int n)
{
    vector<int> totient(n + 1, 0);
    for (int i = 0; i < totient.size(); i++)
    {
        totient[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (totient[i] == i)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                totient[j] = totient[j] * (i - 1) / i;
            }
            totient[i] = i - 1; // for prime number all small numbers are coprime of that prime number.
        }
    }

    return totient[n];
}

int main()
{
    int n;
    cout << "enter number for getting all it's coprime number less than it : ";
    cin >> n;
    /*
        sample input : 127
                    o/p : 126
    */
    cout << " total coprime less then " << n << " is : " << find_coprimes(n) << endl;

    return 0;
}