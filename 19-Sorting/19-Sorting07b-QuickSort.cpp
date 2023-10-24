/*

    # Quick Sort (Method 2)


    * Time complexity :
        Best case & average case : O(nlog(n))
        worst case : O(n*n) or O(n²)

    * space complexity :
        O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    // it can be any element in the array. Here we are taking first element.
    int pivot = arr[l];
    int i = l;
    int j = r;
    while (i < j)
    {
        // move right till we get bigger element then pivot element
        while (arr[i] <= pivot && i <= r - 1)
        {
            i++;
        }
        // move left till we get bigger element then pivot element
        while (arr[j] > pivot && j >= l + 1)
        {
            j--;
        }

        // if we are not on the correct position of pivot element then swap both element which are on i and j index.
        // so that we get smaller element on left side of pivot element and greater elements on right side of pivot element.
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, j, l);
    return j;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
int main()
{
    int arr[5] = {1, 5, 3, 4, 2};
    quickSort(arr, 0, 4);
    cout << "sorted array is : ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}