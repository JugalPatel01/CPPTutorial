#include <iostream>
using namespace std;
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos)
{
    return ((n | (1 << pos)));
}

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return n & mask;
}

int main()
{

    cout << getBit(6, 0) << endl; //0
    cout << getBit(6, 1) << endl; //1
    cout << getBit(6, 2) << endl; //1

    cout << setBit(6, 0) << endl; //110--> 111 === ans is 7

    cout << clearBit(6, 2) << endl; // here 6 is 110 and after clearing bit we get 010 is 2.

    return 0;
}