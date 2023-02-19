/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
    e.g. [1,2,3]
        ans --> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
vector<vector<int>> ans;
int main() {

    int vector_size;
    cin >> vector_size;
    vector<int> a(vector_size);
    for (auto &i : a)
    {
        cin >> i;
    }
    sort(a.begin(),a.end());
    do{
        ans.push_back(a);
    }
    while(next_permutation(a.begin(),a.end()));

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