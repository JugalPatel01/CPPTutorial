/*

    * coin change problem
    Q: Given a set of coins and a value 'v'.we have to find the number of way to make change of 'v'.
    i/p : s = {1,2,3}   V = 3
        possible ways to make change are : {3},{2,1},{1,1,1}
        NOTE : {1,2} and {2,1} both are same so don't count them twice.

    1) brute-force approach :
                      [{1,2,3} 3]
                 _________|_________
        taking 3 |                 |    not taking 3
             [{1,2,3},0]        [{1,2},3]
                            ________|_________
                   taking 2 |                 |    not taking 2
                        [{1,2},1]          [{1},3]
                ________|_________            |_______________________
      taking 2 |                 |not taking 2              _________|_________
           [{1,2},-1]          [{1},1]       taking 1       |                  | not taking 1
                                                         [{1},2]             [{},3]

    so on.....

    so here we get total 3 ways {3}, {2,1} , {1,1,1}
    time complexity : O(2ᵛ) where v is a given value.
    now here we can write a recurrance relation for above problem.
    count(change_set,set_size,value) = count(change_set,set_size,value-change_set[i])
                                      + count(change_set,set_size-1,value)  ,  where change_set[i] is element of the set.

    2) dynamic programming using memorizaton :
    -> here we made a working recursion problem.
    -> now we take one container data-strucutre and store returned values for further use.
    -> now using that stored values we reduce unwanted function calls and reduce time complexity.
    -> so here we reduce time complexity by O(v*elements_in_set) by using some extra memory.

    3) dynamic programming using tabulation :
    -> create one table with some initial value. in our case every cell is filled with 0.
    -> now give the base case value to the table. in our case if we want to generate 0 with 0 coin then we can do it with 1 way
       so table[0][0] = 1;
    -> now iterate table from starting and take both cases
        a) if we consider the coin then we have to add previous state's value in current state and our previous state is :
           table[element_of_set][value] += table[element_of_set][value-change_set[value-element_of_set-1]]
        b) and if we not consider that coin then we have to add previous state's value in current state and our previous state is :
            table[element_of_set][value] += talbe[element_of_set-1][value]

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int find_change_using_bruteforce(vector<int> &change_set, int set_size, int v)
{
    if (set_size <= 0)
        return 0;
    if (v == 0)
        return 1;
    if (v < 0)
        return 0;

    int ans = find_change_using_bruteforce(change_set, set_size, v - change_set[set_size - 1]) + find_change_using_bruteforce(change_set, set_size - 1, v);
    return ans;
}

int find_change_using_memorization(vector<int> change_set, int set_size, int v, vector<vector<int>> &memo_table)
{
    if (set_size <= 0)
        return 0;
    if (v == 0)
        return 1;
    if (v < 0)
        return 0;

    if (memo_table[set_size][v])
    {
        return memo_table[set_size][v];
    }

    int ans = find_change_using_memorization(change_set, set_size, v - change_set[set_size - 1], memo_table) + find_change_using_memorization(change_set, set_size - 1, v, memo_table);

    memo_table[set_size][v] = ans;

    return ans;
}

int find_change_using_tabulation(vector<int> change_set, int v)
{
    vector<vector<int>> table(change_set.size() + 1, vector<int>(v + 1, 0));
    table[0][0] = 1;

    for (int i = 1; i <= change_set.size(); i++)
    {
        for (int j = 0; j <= v; j++)
        {
            if (j - change_set[i - 1] >= 0)
            {
                table[i][j] += table[i][j - change_set[i - 1]];
            }
            table[i][j] += table[i - 1][j];
        }
    }

    return table[change_set.size()][v];
}

int main()
{
    int v, n;
    cout << "enter no. of chage availables in set : ";
    cin >> n;
    vector<int> change_set(n);
    for (auto &i : change_set)
    {
        cin >> i;
    }
    cout << "enter value for change :";
    cin >> v;

    /*
        sample input : 3 1 2 3 5
     */

    vector<vector<int>> memo_table(n + 1, vector<int>(v + 1, 0));
    cout << "total ways to give change of value v using memorization appraoch is : " << find_change_using_memorization(change_set, n, v, memo_table) << endl;

    cout << "total ways to give change of value v using tabulation appraoch is : " << find_change_using_tabulation(change_set, v) << endl;

    cout << "total ways to give change of value v using bruteforce appraoch is : " << find_change_using_bruteforce(change_set, n, v) << endl;

    return 0;
}