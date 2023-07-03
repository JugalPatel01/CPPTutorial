/*

    * Max sum subarray of size = K & sum < X
    Q : For a given array and integers K & X, find the maximum sum subarray of size K and having sum less than X.

    i/p :   [7 5 4 6 8 9]    k = 3    x = 20
    o/p :

    brute force : find all the subset and find sum of them and return required one.


 */

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

int find_subarray(vector<int> v, int k, int x)
{
    int start = 0, end = 0, sum = 0, ans = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    if (sum < x)
    {
        ans = sum;
    }
    for (int i = k; i < v.size(); i++)
    {
        sum = sum - v[i - k] + v[i];
        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "enter no. of elements in an array : ";
    cin >> n;
    cout << "enter elements of an array : ";
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int x, k;
    cout << "elements in subarray : ";
    cin >> k;

    cout << "maximum sum can be less than : ";
    cin >> x;
    if (k < n)
    {
        cout << "size of sub array with sum less than x is : " << find_subarray(v, k, x);
    }
    else
    {
        cout << "sub array's size is more :< ";
    }
    return 0;
}