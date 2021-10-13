#include <iostream>
#include <math.h>
using namespace std;


//functions are uses call stack for memory management. means 
//first function is on the top of stack and excute first and last function is at last of stack and excute last .
//so if we need to write functions after main block then we need to initialized or declaired function above the main function. 
//after that declairation we can write function anywhere in program.
bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
    return 0;
}