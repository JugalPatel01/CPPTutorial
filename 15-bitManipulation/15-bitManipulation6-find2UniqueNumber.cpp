/*  find 2 unique numbers in an array where all numbers except two, are present twice in array*/

#include <iostream>
using namespace std;

/* here logic is first we find normal unique number at last we get xor of two unique number (xorsum)
    
    now we use property of xor if we have two distinct bit then get 1 
    
    so that we find significant bit(right most poistive bit) of xor of unique number and its position.

    and then we find numbers in array which have same bit as same position and then do xor of that all number and at last we get our first number.

    then we do xor that number with xorsum and we get our second number.
 */
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique(int arr[], int n)
{

    int xorsum = 0;

    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    int tempxorsum = xorsum;
    int getbit = 0;
    int pos = -1;

    while (getbit != 1)
    {
        getbit = (tempxorsum & 1);
        tempxorsum = (tempxorsum >> 1);
        pos++;
    }

    int ans1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos)==1)
            ans1 = ans1 ^ arr[i];
    }

    int ans2 = xorsum ^ ans1;

    cout << "two unique numbers are " << ans1 << " & " << ans2 << endl;
}

int main()
{
    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unique(arr, n);

    return 0;
}