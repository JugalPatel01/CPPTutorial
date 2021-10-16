#include <iostream>
using namespace std;
//print all prime number using Sieve of eratosthenes
void primeSeive(int n)
{
    int prime[10000] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
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
    cout << "enter number for which you want all prime number ";
    cin >> n;
    primeSeive(n);

    return 0;
}