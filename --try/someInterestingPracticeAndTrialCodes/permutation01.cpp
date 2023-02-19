/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
    e.g. [1,2,3]
        ans --> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;

void permute(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a, idx + 1);
        swap(a[i], a[idx]);
    }
}
int main()
{
    int vector_size;
    cin >> vector_size;
    vector<int> a(vector_size);
    for (auto &i : a)
    {
        cin >> i;
    }

    permute(a, 0);

    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}