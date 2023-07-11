/*

    * Greedy algorithms

    -> This algorithms is based on markov process
    -> marcov process : process which depends only on the previous state.
    -> In this techniuqe we build solution piece by piece
    -> we choose next piece on behalf on max condition
    -> so through this technique we get locally optimal answers which leads us to global answer.


    * Indian Coin change Problem :
    Q: Given an array of denominations and a value x.we have to find the minimum number of coins require to make
       value x.
    NOTE : We have infinite supply of each coin.
    i/p : 234
    o/p : total 5 coins
          200 -> 1
          20 -> 1
          10 -> 1
          2 -> 2

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int n, k;
    vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    // cout << "enter total no. of elements in an array : ";
    // cin >> n;
    // vector<int> v(n);
    // cout << "Enter elements of an array : ";
    // for (auto &i : v)
    // {
    //     cin >> i;
    // }
    cout << "enter total amount : ";
    cin >> k;

    sort(v.begin(), v.end(), greater<int>());

    unordered_map<int, int> mp;

    for (int i = 0; i < v.size(); i++)
    {
        while (k - v[i] >= 0)
        {
            k = k - v[i];
            mp[v[i]]++;
        }
    }

    for (auto i : mp)
    {
        cout << i.first << " -> " << i.second << endl;
    }
    return 0;
}