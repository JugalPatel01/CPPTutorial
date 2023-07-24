/*

    * Staircase problem
    -> A person can climb one, two or three stairs at a time. find the number of ways in which he can climb to nᵗʰ stair.
    i/p : 3
    o/p : 4
        {1,1,1}
        {2,1}
        {1,2}
        {3}

    1) brute-force recursion approach :
                 3
              1/2| \3
              2  1  0
          1/2|3\ |________
          1  0  -1        |
          |            1/2| \3
          |            0 -1 -2
       1/2| \3
       0 -1 -2
       so, when we get 0 so we get a proper solution so we have to count total no. of 0s.
       -> it takes O(3ⁿ) time complexity.

    here, we can see there are some repetation. so we can use dynammic appraoch .

    recurrance relation :
        f(0) = 1;
        f(n) = f(n-1) + f(n-2) + f(n-3)
               1 stair  2 stair  3 stair

    2) memorization technique
    -> first we have to make working recursion program
    -> then take storage container and store return values for further uses.
    -> use stored value to avoid redundant calls.


*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long find_way_recursion(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    long long count = 0;
    for (int i = 1; i <= 3; i++)
    {
        count += find_way_recursion(n - i);
    }
    return count;
}

long long find_way_memorization(int n, unordered_map<int, long long> &memo_table)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (memo_table[n])
    {
        return memo_table[n];
    }
    long long count = 0;
    for (int i = 1; i <= 3; i++)
    {
        count += find_way_memorization(n - i, memo_table);
    }
    memo_table[n] = count;
    return count;
}

long long find_way_tabulation(int n)
{
    vector<long long> table(n + 1, 0);
    table[0] = 1;
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2] + table[i - 3];
    }
    return table[n];
}

int main()
{
    int n;
    cout << "enter nth step to reach : ";
    cin >> n;
    /*
        sample input : 45

    */
    unordered_map<int, long long> memo_table;
    cout << "ways to reach at " << n << "th stair using memorization are : " << find_way_memorization(n, memo_table) << endl;

    cout << "ways to reach at " << n << "th stair using tabulation are : " << find_way_tabulation(n) << endl;

    cout << "ways to reach at " << n << "th stair using recursion are : " << find_way_recursion(n) << endl;
    return 0;
}