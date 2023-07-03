/*

    * Heap sort

    i/p : [5 77 29 2 52 6]
    o/p : [2 5 6 29 52 77]

    here, we make heap(normal complete binary tree) and then we heapify that heap in log(N) time complexity.
    then we remove each element one by one from max heap and put at the last of the array in N * log(N) time .
    so we get sorted array.

    here it takes total log(N) + N * log(N) = O(N*log(N)) time.
    heap sort is inplace sort but not a stable sort.

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[largest])
    {
        largest = l;
    }
    if (r < n && v[r] > v[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapsort(vector<int> &v)
{
    int n = v.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main()
{
    int n;
    cout << "enter no. of element in the array : ";
    cin >> n;
    vector<int> v(n);

    cout << "enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }

    heapsort(v);

    cout << "sorted array is : ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}