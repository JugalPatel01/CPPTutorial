/*
    * 3 sum problem
    Q. given an array and a value, find if there exists three numbers whose sum is equal to the given value.

    i/p : array = [12 3 7 1 6 9]          k = 24
    o/p : 1 -> (12,3,9)


    brute force : find sum of every pair of 3 element and return if it's equal to the k. it's time complexity is O(n^3)

    using two pointer appraoch :
    steps:
    1) sort an array
    2) run for loop converting three sum problem into two sum problem
    3) find two sum for rest of the element

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// brute force
vector<int> find_sum(vector<int> v, int target)
{
    int n = v.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == target)
                {
                    ans.push_back(v[i]);
                    ans.push_back(v[j]);
                    ans.push_back(v[k]);
                    return ans;
                }
            }
        }
    }
    ans.push_back(0);
    return ans;
}
*/

vector<int> find_sum(vector<int> v, int target)
{
    int n = v.size();
    vector<int> ans;
    sort(v.begin(), v.end()); // O(nlogn)

    for (int i = 0; i < n; i++) // O(n^2)
    {
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            int x = v[start] + v[end] + v[i];
            if (x == target)
            {
                ans.push_back(v[i]);
                ans.push_back(v[start]);
                ans.push_back(v[end]);
                return ans;
            }
            else if (x < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    ans.push_back(-1);
    return ans;
}

int main()
{
    // input start
    int n, k;
    cout << "enter the size of the array : ";
    cin >> n;
    cout << "enter value for array : ";
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "enter value of target : ";
    cin >> k;
    // input end

    vector<int> ans = find_sum(v, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}