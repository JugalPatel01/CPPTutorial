/*
    * Maximum consecutive ones problem
    Q. Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
       so our task is we have to return the length of the longest(contiguous) subarray that contains only 1s.

    i/p : array = [1 1 1 0 0 0 1 1 1 1 0]       k = 2
    o/p : 6

    bruteforce :
    make all the possible subarray and check for consecutive ones

    two pointers / sliding window algo


*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int con_ones(vector<int> v, int k)
{
    int ans = 0;
    int n = v.size();
    int i = 0, j = 0, count = 0;

    for (int j = 0; j < n; j++)
    {
        if (v[j] == 0)
        {
            count++;
        }
        while (count > k)
        {

            if (v[i] == 0)
            {
                count--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }

    return ans;
}

int main()
{

    // input start
    int n, k;
    cout << "enter size of an array : ";
    cin >> n;
    cout << "enter values of elements : ";
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "enter value of k for changing 0s into 1s : ";
    cin >> k;
    // input end

    int ans = con_ones(v, k);
    cout << "maximum consecutive ones are : " << ans << endl;

    return 0;
}