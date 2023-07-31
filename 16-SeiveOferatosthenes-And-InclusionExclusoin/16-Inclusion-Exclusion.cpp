/*

    * how many numbers between 1 and 1000 are divisible by 5 or 7

*/

#include <iostream>
using namespace std;
int divisible(int n, int a, int b)
{

    int c1 = n / a;
    int c2 = n / b;

    int c3 = n / (a * b);

    return c1 + c2 - c3;
}

int main()
{

    int n, a, b;
    cout << "enter the number n for finding multiples : ";
    cin >> n;
    cout << "enter value of A and B for counting sum of multiple of both : ";
    cin >> a >> b;

    /*
        sample input : 1000 5 7
    */

    cout << divisible(n, a, b);

    return 0;
}
