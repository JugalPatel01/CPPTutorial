#include <iostream>
using namespace std;

/* 
prime factorisation using Sieve:
means all prime factor of 10 is 
2 5 
 */

void primeFactor(int n)
{
    int arr[100000] = {0};

    for (int i = 2; i <= n; i++)
    {
        
        arr[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
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
    cout << "enter number for get all prime factor ";
    cin >> n;

    primeFactor(n);
    return 0;
}