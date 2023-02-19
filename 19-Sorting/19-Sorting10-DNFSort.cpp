/*
    DNF stands for Dutch national flag.[sort 0,1,2]

    region for 0s + region for 1s + region for unkonwn + region for 2s

    in every step we are decreasing the unkown region and place that element in to the respective regions

    time complexity of the dnf sort is of O(n) where n is no. of elements in the array.

*/

#include <iostream>
using namespace std;

void DNFSort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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
        int x;
        cin >> x;
        if (x == 0 || x == 1 || x == 2)
        {
            arr[i] = x;
        }
        else
        {
            cout << "enter element again ";
            i--;
        }
    }
    DNFSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}