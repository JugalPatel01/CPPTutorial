/* Merge sort

    input : 5 3 4 2 1
    output : 1 2 3 4 5

    Time complexity : Best Case, Worst Case , Average Case -> O(nlogn)
 */
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        b[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}
int main()
{
    // int n;
    // cout << "enter number of elements" << endl;
    // cin >> n;
    // int arr[n];
    // cout << "Enter Elements " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // mergeSort(arr, 0, n - 1);

    int arr[5] = {5,3,4,2,1};
    mergeSort(arr, 0, 4);

    cout<<"Sorted array is " <<endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}