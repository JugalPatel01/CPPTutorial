/*

    * Smallest subarray with sum > x
    Q : For a given array and an integer X, find the minimum subarray size for which sum > X.
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int find_subarray_length(vector<int> v, int x)
{
    int start = 0, sum = 0, ans = v.size() + 1;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        while (sum > x)
        {
            ans = min(ans, i - start + 1);
            sum -= v[start++];
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
    int x;

    cout << "maximum sum can be less than : ";
    cin >> x;

    int ans_size = find_subarray_length(v, x);
    if (ans_size != n + 1)
    {
        cout << "size of minimum subarray with sum greater then " << x << " is : " << ans_size;
    }
    else
    {
        cout << "No such subarray exists " << endl;
    }
    return 0;
}