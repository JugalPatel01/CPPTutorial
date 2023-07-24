/*

    * 0-1 kanpsack
    Q : Given an array of items with their weight and value. and a knapsack with weight w. find the maximum value of items that
        can be stolen and put into knapsack.
        -> we either have to pick full item(1) or no item(0) and there is no extra copies of same items.

    e.g. : value  : 60 100 150
           weight : 15 30  40
           W = 50 kg
    -----> possible combinations are :

            1) {15,30}  = 45 kg -> value : 160
            2) {40}  = 40 kg -> value : 150

            so, ans is : {15,30} because it gives more value.

    brute-force approach :
    1) we itearte through items recursivly and either take that item or not.
    2) return maximum value returned from the both case.
    NOTE : time complexity O(2ⁿ).

    now,
    recurrance relation is f(no_of_items,weight) = max(
                                                    f(no_of_items-1,weight),
                                                    f(no_of_items-1,weight-item_weight[no_of_item-1]+value_of_item)
                                                    )

    memorization approach :
    1) complete recursion solution.
    2) store returned values in some data container and use it for further function calling
    3) using that data container reduce function calls.

    tabulation appraoch :
    1) create 2d table of size items and knapsack with default value 0.
    2) base case is if we have no thing in knapsack then it's value is 0.
    2) iterate the whole table and fill value according to below rules.
        if(j - weight[i] >= 0)
            table[i][j] = max(table[i-1][j], value[i] + table[i-1][j-weight[i]])
                            not consider item, consider item
        else
            table[i][j] = table[i-1][j]

    eg. for value   1   ,   3   ,   5
          weights   1   ,   2   ,   3
        capacity_of_knapsack = 5

            0   1   2   3   4   5
        0 | 0 | 0 | 0 | 0 | 0 | 0 |
        1 | 0 | 1 | 1 | 1 | 1 | 1 |
        2 | 0 | 1 | 3 | 4 | 4 | 4 |
        3 | 0 | 1 | 3 | 5 | 6 | 8 |


*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int find_value_using_recursion(vector<pair<int, int>> store, int store_size, int k_weight)
{
    if (store_size < 0)
    {
        return 0;
    }
    if (k_weight <= 0)
    {
        return 0;
    }
    int value = 0;
    if (store[store_size].second <= k_weight)
    {
        value = max(store[store_size].first + find_value_using_recursion(store, store_size - 1, k_weight - store[store_size].second), find_value_using_recursion(store, store_size - 1, k_weight));
    }
    else
    {
        value = find_value_using_recursion(store, store_size - 1, k_weight);
    }

    return value;
}

int find_value_using_memorization(vector<pair<int, int>> store, int store_size, int k_weight, vector<vector<int>> &memo_table)
{
    if (store_size < 0)
    {
        return 0;
    }
    if (k_weight <= 0)
    {
        return 0;
    }
    if (memo_table[store_size][k_weight])
    {
        return memo_table[store_size][k_weight];
    }

    int value = 0;
    if (store[store_size].second <= k_weight)
    {

        value = max(store[store_size].first + find_value_using_memorization(store, store_size - 1, k_weight - store[store_size].second, memo_table), find_value_using_memorization(store, store_size - 1, k_weight, memo_table));
    }
    else
    {
        value = find_value_using_memorization(store, store_size - 1, k_weight, memo_table);
    }
    memo_table[store_size][k_weight] = value;
    return value;
}

int find_value_using_tabulation(vector<pair<int, int>> store, int k_weight)
{
    vector<vector<int>> table(store.size() + 1, vector<int>(k_weight + 1, 0));

    for (int i = 1; i <= store.size(); i++)
    {
        for (int j = 1; j <= k_weight; j++)
        {
            if (j - store[i - 1].second >= 0)
            {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - store[i - 1].second] + store[i - 1].first);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return table[store.size()][k_weight];
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

     */
    cout << "maximum possible value in the knapsack is : " << find_value_using_recursion(store, n - 1, knapsack_weight) << endl;

    vector<vector<int>> memo_table(n + 1, vector<int>(knapsack_weight + 1, 0));
    cout << "maximum possible value in the knapsack is : " << find_value_using_memorization(store, n - 1, knapsack_weight, memo_table) << endl;

    cout << "maximum possible value in the knapsack is : " << find_value_using_tabulation(store, knapsack_weight);

    return 0;
}