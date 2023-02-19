/*
    Given a collection of numbers, nums, that might contain duplicates,return all possible unique permutation in any order.
*/
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


void helper(vector<int> a, vector<vector<int>> &ans , int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }

    for(int i=idx;i<a.size();i++){
         if(i!=idx && a[i]==a[idx])
         continue;
         swap(a[i],a[idx]);
         helper(a,ans,idx+1);
    }

}
vector<vector<int>> permute(vector<int> nums)
{
    sort(nums.begin(),nums.end());

    vector<vector<int>> ans ;
    helper(nums,ans,0);
    return ans;
}
int main()
{
    int vector_size;
    cin >> vector_size;
    // vector_size=3;
    vector<int> a(vector_size);
    // a = {1,2,2};
    for (auto &i : a)
    {
        cin >> i;
    }
    vector<vector<int>> res = permute(a);

    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}