/*

    * Fractional Knapsack
    Q : Given 'n' items with {weight,value} of each item and the capacity of knapsack is 'W'. we need to put these items in
        knapsack such that final value of items in knapsack is maximum.

    i/p : values(rs.)    | 21 | 24 | 12 | 40 | 30 |
          weight(kg.)    | 7  | 4  | 6  | 5  | 6  |
          W = 20 kg.
    o/p : 109
    approach : find value/weight ratio and sort it in decreasing order and take things from starting of the list.

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if ((double)(a.first / a.second) > (double)(b.first / b.second))
    {
        return true;
    }
    return false;

    // return ((double)(a.first / a.second) > (double)(b.first / b.second));
}

void find_items_in_sack(vector<pair<int, int>> v, int max_weight, int &ans)
{
    for (auto i : v)
    {
        if (max_weight - i.second > 0)
        {
            ans += i.first;
            max_weight -= i.second;
        }
        else
        {

            int x = (double)i.first / i.second;

            ans += x * max_weight;
            break;
        }
    }
}

int main()
{
    int n;
    cout << "enter total no. of items : ";
    cin >> n;
    vector<pair<int, int>> v(n);

    for (auto &i : v)
    {
        cout << "enter value of item : ";
        cin >> i.first;
        cout << "enter weight of item : ";
        cin >> i.second;
    }

    int k;
    cout << "enter size of knapsack : ";
    cin >> k;

    sort(v.begin(), v.end(), cmp);

    for (auto i : v)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    int ans = 0;

    find_items_in_sack(v, k, ans);

    cout << "maximum possible value in sack is : " << ans << endl;

    return 0;
}