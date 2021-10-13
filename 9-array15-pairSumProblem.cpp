//sum of any two array elemnt is equal to the given key sum.

#include <iostream>
using namespace std;
bool pairsum(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << "At index number " << i << " & " << j << " we get our key sum." << endl;
                return true;
            }
        }
    }
    return false;
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

    cout << "The key value where you want to get sum of two numbers from array is " << endl;
    int k;
    cin >> k;

    cout << "is sum is present in array? " << pairsum(arr, n, k) << endl;
    return 0;
}