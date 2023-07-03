/*

    * Merge k sorted arrays
    Q : given K sorted arrays we have merge them and return a whole array
    i/p : [ 1 5 8 9 ]   [ 3 4 ]   [2 6 7]
    o/p : [1 2 3 4 5 6 7 8 9]

    bruteforce appraoch : take two array and merge them and so no.
    so suppose we have n array of n elements then we have to do total
    2n + 3n + 4n + 5n + ... + n² = (n * n(n+1)/2) - n = O(n³)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> merge_arrays(vector<vector<int>> v)
{
    vector<int> ans;
    vector<int> index_track(v.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for (int i = 0; i < v.size(); i++)
    {
        min_heap.push(make_pair(v[i][0], i));
    }

    while (!min_heap.empty())
    {
        pair<int, int> temp = min_heap.top();
        min_heap.pop();

        ans.push_back(temp.first);
        if (index_track[temp.second] + 1 < v[temp.second].size())
        {
            min_heap.push({v[temp.second][index_track[temp.second] + 1], temp.second});
            index_track[temp.second] += 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter total no. of arrays : ";
    cin >> n;
    // 2d vector
    vector<vector<int>> arrays;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter total no of element of an array " << i + 1 << " is : ";
        cin >> x;
        vector<int> arr(x);
        for (auto &j : arr)
        {
            cin >> j;
        }
        arrays.push_back(arr);
    }

    // for (auto i : arrays)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> ans = merge_arrays(arrays);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}