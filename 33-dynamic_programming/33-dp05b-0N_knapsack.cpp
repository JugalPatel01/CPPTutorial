/*

    * O-N Knapsack

    Q : Given an array of items with their weight and value. and a knapsack with weight w. find the maximum value of items that
        can be stolen and put into knapsack.
        -> we either have to pick full item(1) or no item(0) and there are infinite copies of same items.

    e.g. : value  : 60 100 150
           weight : 15 30  40
           W = 50 kg
    -----> possible combinations are :

            1) {15,15,15} = 45 kg -> value : 180
            2) {15,30}  = 45 kg -> value : 160
            3) {40}  = 40 kg -> value : 150

            so, ans is : {15,15,15} because it gives more value.

    NOTE : This question is same as previous 0-1 knapsack problem. but now if we consider the item then we don't remove that item from items

     

*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int find_value_using_recursion(vector<pair<int, int>> store, int knapsack_size, int weight)
{
    if (knapsack_size < 0)
    {
        return 0;
    }
    if (weight < 0)
    {
        return 0;
    }
    int value = 0;
    if (store[knapsack_size].second <= weight)
    {
        value = max(find_value_using_recursion(store, knapsack_size - 1, weight), store[knapsack_size].first + find_value_using_recursion(store, knapsack_size, weight - store[knapsack_size].second));
    }
    else
    {
        value = find_value_using_recursion(store, knapsack_size - 1, weight);
    }
    return value;
}

int find_value_using_memorization(vector<pair<int, int>> store, int knapsack_size, int weight, vector<vector<int>> &memo_table)
{
    if (knapsack_size < 0)
    {
        return 0;
    }
    if (weight < 0)
    {
        return 0;
    }
    if (memo_table[knapsack_size][weight])
    {
        return memo_table[knapsack_size][weight];
    }
    int value = 0;
    if (store[knapsack_size].second <= weight)
    {
        value = max(find_value_using_recursion(store, knapsack_size - 1, weight), store[knapsack_size].first + find_value_using_recursion(store, knapsack_size, weight - store[knapsack_size].second));
    }
    else
    {
        value = find_value_using_recursion(store, knapsack_size - 1, weight);
    }
    memo_table[knapsack_size][weight] = value;
    return value;
}

int find_value_using_tabulation(vector<pair<int, int>> store, int weight)
{
    vector<vector<int>> table(store.size() + 1, vector<int>(weight + 1, 0));

    for (int i = 1; i <= store.size(); i++)
    {
        for (int j = 1; j <= weight; j++)
        {
            if (j - store[i - 1].second >= 0)
            {
                table[i][j] = max(table[i - 1][j], store[i - 1].first + table[i][j - store[i - 1].second]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return table[store.size()][weight];
}

int main()
{
    int n;
    cout << "Enter total no. of items in the store : ";
    cin >> n;
    cout << "enter items with their value and weight : ";
    vector<pair<int, int>> store(n);
    for (auto &i : store)
    {
        cin >> i.first >> i.second;
    }
    int knapsack_weight;
    cout << "Enter size of knapsack : ";
    cin >> knapsack_weight;

    /*

        sample input : 3 60 15 100 30 150 40 50
                     : 5 4 3 3 2 5 4 6 5 1 1 11
    */

    cout << "maximum possible value in the knapsack is : " << find_value_using_recursion(store, n - 1, knapsack_weight) << endl;

    vector<vector<int>> memo_table(n + 1, vector<int>(knapsack_weight + 1, 0));
    cout << "maximum possible value in the knapsack is : " << find_value_using_memorization(store, n - 1, knapsack_weight, memo_table) << endl;

    cout << "maximum possible value in the knapsack is : " << find_value_using_tabulation(store, knapsack_weight);
    return 0;
}