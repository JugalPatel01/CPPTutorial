/*

    * Find the peak element
    Q : For a given array, find the any peak element in the array.
        Peak element is one which is greater than both, left and right neighbours of itself.
        -> important points about question :
        1) Ascending array : last element is peak element
        2) Decending array : first element is peak element
        3) for all same elements : each element are peak elements
    i/p : [0, 6, 8, 5, 7, 9]
    o/p : 8 on index 2      // 9 is also peak but we have to return only one peak value's index
*/
#include <iostream>
#include <vector>
using namespace std;

int find_peak(vector<int> v)
{
    int start = 0, end = v.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if ((mid == 0 || v[mid - 1] <= v[mid]) && (mid == v.size() - 1 || v[mid + 1] <= v[mid]))
        {
            return mid;
        }
        else if (mid > 0 && v[mid - 1] > v[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter total No. of elements : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "peak is on index : " << find_peak(v) << endl;

    return 0;
}