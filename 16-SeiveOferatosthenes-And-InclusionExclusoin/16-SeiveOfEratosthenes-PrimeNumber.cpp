/*

    * print all prime number using Sieve of eratosthenes

    # brute force approach to print all the prime numbers :
    -> iterate through all the numbers and check for the prime number
    -> for checking prime number we take modulo with all number from 1 to sqrt(n).
    -> and if modulo is 0 then it's not prime so move to the next number

    * sieve of eratosthenes approch :
    -> make an array of size n+1.
    -> now iterate i from 2 to the n and mark the multiple of i by 1
    -> at the end print an indices of array which have 0 as their values.

*/
#include <iostream>
using namespace std;
void primeSeive(int n)
{
    int prime[10000] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            // for (int j = 2 * i; j <= n; j += i)         // if we mark all the multiple of i
            for (int j = i * i; j <= n; j += i) // but from observation we can see that all multiple before i*i are marked so.
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
}
int main()
{

    int n;
    cout << "enter number for which you want all prime number : ";
    cin >> n;
    primeSeive(n);

    return 0;
}