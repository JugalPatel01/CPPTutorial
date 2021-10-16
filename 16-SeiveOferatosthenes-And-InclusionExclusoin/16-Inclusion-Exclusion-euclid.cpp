//Euclid Algo to find GCD(greatest common divisior)
/* here we find normal gcd  
    24=2*2*2*3
    42=2*3*7

     here we find gcd using Euclid algo

     42-24=18
     24-18=6
     18-6=12
     12-6=6
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

    cout << "enter two no. for finding gcd ";
    int a, b;
    cin >> a >> b;

    cout << "gcd of two number is " << gcd(a, b) << endl;

    return 0;
}