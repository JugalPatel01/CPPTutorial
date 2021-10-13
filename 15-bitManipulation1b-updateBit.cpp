/* WARNING :  This code is not run in vs code we need to manually execute this code in windows */
#include <iostream>
using namespace std;
int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

int main()
{

    cout << updateBit(5, 1, 1); // here 5 is 101 and after updating 0 with 1 and we get 111 = 7 as a ans

    return 0;
}