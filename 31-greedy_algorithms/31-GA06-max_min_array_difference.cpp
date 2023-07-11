/*

    * Max and Min array difference
    Q: Given an array A of n elements. we have to remove exactly n/2 elements from array A and add it to another array
       B(initially empty).find Maximum and minimum values of difference between these two arrays.
       difference = abs(A[i] - B[i])
    i/p : A[12 -3 10 0]
    o/p : 5 25
        A[-3 12] B[0 10]
        minimum = 5
        A[-3 0] B[12 10]
        maximum = 25
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int find_maximum(vector<int> &v)
{
    int sum = 0;
    for (int i = 0; i < v.size() / 2; i++)
    {
        sum += v[i + v.size() / 2] - v[i];
    }
    return sum;
}

int find_minimum(vector<int> &v)
{
    int sum = 0;
    for (int i = 0; i < v.size() / 2; i++)
    {
        sum += v[2 * i + 1] - v[2 * i];
    }
    return sum;
}

int main()
{
    int n;
    cout << "total no. of elements in an array : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter total elements in an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    cout << "maximum difference sum is : " << find_maximum(v) << endl;
    cout << "minimum difference sum is : " << find_minimum(v) << endl;

    return 0;
}