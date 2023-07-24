/*

    * Minimum jumps to reach end
    Q : Given an array of integers where each element represents the max number of steps that can be made forward from that
        element. we have to find the minimum number of jumps to reach the end of the array ( starting from the first element).
        If an element is 0, they cannot move through that element.

    i/p : [1,2,8,5,9,2,5,2,6]
    o/p : 3
           1->2->8->6

    * brute-force approach
    ->
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

int find_jump_recursion(vector<int> v, int start)
{
    if (start >= v.size())
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= v[start]; i++)
    {
        ans = min(ans, 1 + find_jump_recursion(v, start + i));
    }
    if (ans == INT_MAX)
    {
        return INT_MIN;
    }
    if (ans < 0)
    {
        return 0;
    }
    return ans;
}

int find_jump_memorization(vector<int> &v, int start, vector<int> &memo_table)
{
    if (start >= v.size())
    {
        return 0;
    }
    if (memo_table[start] != INT_MAX)
    {
        return memo_table[start];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= v[start]; i++)
    {
        ans = min(ans, 1 + find_jump_memorization(v, start + i, memo_table));
    }
    if (ans == INT_MAX)
    {
        return INT_MIN;
    }
    if (ans < 0)
    {
        return 0;
    }
    memo_table[start] = ans;
    return ans;
}

int find_jump_tabulaiton(vector<int> v)
{
    if (v[0] == 0)
    {
        return 0;
    }
    vector<int> table(v.size() + 1, INT_MAX);
    table[0] = 0;

    for (int i = 0; i <= v.size(); i++)
    {
        for (int j = 1; j <= v[i]; j++)
        {
            if (i + j <= v.size())
            {
                if (table[i] != INT_MAX)
                {
                    table[i + j] = min(table[i + j], 1 + table[i]);
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return table[v.size()];
}

int find_jump_greedy(vector<int> v)
{
    int posible_step = 0;
    int steps_to_go = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!steps_to_go)
        {
            if (posible_step)
            {
                steps_to_go = posible_step;
            }
            else
            {
                steps_to_go = v[i];
            }
            steps_to_go--;
            if (steps_to_go < 0)
            {
                return 0;
            }
            ans++;
        }
        else
        {
            steps_to_go--;
            posible_step = max(posible_step - 1, v[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter total no. of element of an array : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    /*

        sample input : 9 1 2 8 5 9 2 5 2 6
        NOTE : here recursion takes  O(max_number_in_array^size_of_array) = O(Kⁿ)
               memorization and tabulation takes O(max-number_in_array*size_of_array) = O(K*n)
               greedy technique takes O(size_of_array) = O(n)
    */
    vector<int> memo_table(n + 1, INT_MAX);
    cout << "minimum jumps to reach at " << n << "th position using memorization is : " << find_jump_memorization(v, 0, memo_table) << endl;

    cout << "minimum jumps to reach at " << n << "th position using tabulation is : " << find_jump_tabulaiton(v) << endl;

    cout << "minimum jumps to reach at " << n << "th position using recursion is : " << find_jump_recursion(v, 0) << endl;

    cout << "minimum jumps to reach at " << n << "th position using greedy is : " << find_jump_greedy(v) << endl;

    return 0;
}