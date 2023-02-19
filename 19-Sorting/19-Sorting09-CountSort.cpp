/*  time complexity of count sort is better than merge sort and quick sort in some cases.
    time complexity of count sort is O(max(k,n)) where k = maximum element in the array
                                                 and n = number of element in the array
*/

#include <iostream>
#include <vector>
// #include <math.h>
using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    vector<int> count(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k + 1; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    // n = 9;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    // int arr[n] = {1,3,2,3,4,1,6,4,3};
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countSort(arr, n);
    cout << "sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}