/*

    * Count Number of subarrays with sum zero
    Q: given an array we have to find out how many subarray of that array has sum zero with it's elements.
    i/p : [1 -1  1 -1]
    o/p :
           [1 -1]
           [1 -1 1 -1]
           [-1 1]
           [1 -1]
           so, total 4

    bruteforce appraoch : find all the subarrays and then find their sum and return that count of subarrays which have sum zero
                          with it's elements.

    optimized appraoch : rather then calculating sum every time just store sum in array. then check for the repeated elements.
                         as we know that if element is repeated then sum of between elements is 0.so we store the element's place in map and for every new element we check whether that element is present in the map ? if present then we increase the count of the sum zeros.


 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_sum_zero(vector<int> &v)
{
    unordered_map<int, int> store_index;
    int sum = 0;
    // because before doing sum it's value is zero.so value at -1 index is 0.
    store_index[0]++;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        // count return 1 if element is present in the map otherwise return zero.
        store_index[sum]++;
    }

    for (auto i : store_index)
    {
        count += i.second * (i.second - 1) / 2;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter total no. of elements in an array : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "total subarrays with sum 0 are : " << count_sum_zero(v);
    return 0;
}