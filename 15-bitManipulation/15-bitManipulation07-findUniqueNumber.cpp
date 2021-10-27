/* find a unique number in an array where all numbers except one, are present thrice */
#include <iostream>
using namespace std;

bool getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}
int unique(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        if ((sum % 3) != 0)
        {
            result = setBit(result, i);
        }
    }
    return result;
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

    cout << "unique number which is not present in array thrice is " << unique(arr, n) << endl;

    return 0;
}