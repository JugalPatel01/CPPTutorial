/*

    * Count inversions
    Q. Given an array we have to count total no. of inversions.
       Two elements a[i] & a[j] form an inversion if a[i] > a[j] and i < j
    i/p : total no of elements : 8  elements : 5 7 8 11 3 4 9 10
    o/p : inversions : 10
          (5,3), (5,4), (7,3), (7,4), (8,3), (8,4),(11,3),(11,4),(11,9),(11,10)


    brute force approach :
    -> use two for loops and check for the given condition it will take O(N²).

    merge sort approach :
    -> while doing merging in merge sort we count total inversions.
    -> it takes O(NlogN) time complexity.

    using binary search tree :
    -> Traverse through the array and for every index find the number of smaller elements on its right side of the array.
       Sum up the counts for all indexes in the array and print the sum.
    -> to work with negative value and large values we will give them a equivalent ordering.
    -> using this approach it takes O(NlogN) time complexity .

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getInv(vector<int> &binary_index_tree, int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += binary_index_tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update_bit(vector<int> &binary_index_tree, int total_ele, int idx)
{
    while (idx <= total_ele)
    {
        binary_index_tree[idx]++;
        idx += idx & (-idx);
    }
}

int main()
{
    int n;
    cout << "enter total no. of element in array : ";
    cin >> n;
    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    /*

        sample input : 8 5 7 8 11 3 4 9 10
    */

    vector<int> temp = v;

    sort(temp.begin(), temp.end()); // nlogn time complexity

    for (int i = 0; i < n; i++) // nlogn time complexity
    {
        v[i] = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin() + 1; // logn time complexity
    }

    vector<int> binary_index_tree(n + 1);

    /*
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
     */

    int inv = 0;

    for (int i = n - 1; i >= 0; i--) // nlogn time complexity
    {
        inv += getInv(binary_index_tree, v[i] - 1);
        // cout << v[i] << " " << inv << endl;
        update_bit(binary_index_tree, n, v[i]);
        /*
            for (auto j : binary_index_tree)
            {
                cout << j << " ";
            }
            cout << endl;
        */
    }

    cout << "total number of inversion in the given array are : " << inv << endl;

    return 0;
}