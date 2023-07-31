/*

    * prime factorisation using Sieve of eratosthenes :
    Q : print all prime factor of n is
    i/p : 10
    o/p : 2 5

 */
#include <iostream>
using namespace std;

void primeFactor(int n)
{
    int arr[100000] = {0};

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == i)
        {
            // for (int j = 2 * i; j <= n; j += i)          // if we mark all the multiple of i then
            for (int j = i * i; j <= n; j += i) // but from observation we can see that all multiple before i*i are marked so.
            {
                if (arr[j] == j)
                {
                    arr[j] = i;
                }
            }
        }
    }

    while (n != 1)
    {
        cout << arr[n] << " ";
        n /= arr[n];
    }
}
int main()
{

    int n;
    cout << "enter number for get all prime factor : ";
    cin >> n;

    primeFactor(n);
    return 0;
}