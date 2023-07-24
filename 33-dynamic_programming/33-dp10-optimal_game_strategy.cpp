/*

    * Optimal Game Strategy
    Q : Two players are playing a coin game. They are given n coins with values X₁,X₂,....,Xₙ where 'n' is always even.
        They take alternate terns. In each turn, a player picks either the first coin or the last coin from the row and removes
        it from the row. The value of coin is received by that player.
        Determine the maximum value that player 1 can win if he moves first.
        NOTE : Both the players play optimally.

    i/p : coins : 4     values [ 1 2 3 4 ]
    o/p : 6
            player 1 : 4
            player 2 : 3
            player 1 : 2
            player 2 : 1
            so player 1 has coins of value 6  and player 2 has coins of value 4.

    1) brute force approach :
    -> check for every distribution and then find the maximum value out of that.

     NOTE 1 : if coins are in sorted manner then value of coins is sum of even position's coin.
     NOTE 2 : if we have to find to take choise which will give us win then we can use greedy approach.
              we find sum of both even and odd positions coins value.
              and then make choises according to max sum.

    2) recursion approach :
    ->
                            [1 2 3 4]               => our turn
                          1 /       \ 4
                    [2 3 4]         [1 2 3]         => opponent's turn
                 2 /      \ 4     1 /      \ 3
                [3 4]   [2 3]      [2 3]  [1 2]     => our turn
              4 /  3\  3/   \2    3/  2\  2/   \1
              [3]  [4] [2]  [3]   [2] [3] [1] [2]   => opponent's turn

    so here we can see recurrance relation for
          f_max(i,j) = max( a[i] + min(f_max(i+2,j) , f_max(i+1,j-1)),
                            a[j] + min(f_max(i+1,j-1) , f_max(i,j-2))   )

    from above recursion tree we can see that some function like f_max(2,3) are repeating. so we can use dynamic programming.

    3) memorization technique :
    -> make working recursive approach
    -> take one container data structure to store return value from the function
    -> use that stored value to reduce redundant function calls.

    4) tabulation technique :
    ->


*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int find_max_recursion(vector<int> v, int choise1, int choise2)
{
    if (choise1 == choise2)
    {
        return v[choise1];
    }
    if (choise1 > choise2)
    {
        return 0;
    }
    /*
         Basic concept is : choose best when we have choise , and
                            choose worst for us when some one else has choise because he make sure that we get worst.
         so, here if we choose choise 1 then another player choose best possible value of him. so,
         we have to take worst condition for us.


                                i...j       (our turn so we have to choose)
                            i /       \ j
                      i+1...j           i...j-1         (opponent's term: so he choose best for him and give us worst condition)
                  i+1 /   \ j         i/       \j-1
                i+2...j  i+1...j-1  i+1...j-1   i...j-2     (we have to choose our best from worst condition)


    */
    int left = v[choise1] +
               min(find_max_recursion(v, choise1 + 2, choise2), find_max_recursion(v, choise1 + 1, choise2 - 1)); // opponent give us choise which is worst for us so, think that we will get the lowest value
    int right = v[choise2] + min(find_max_recursion(v, choise1 + 1, choise2 - 1), find_max_recursion(v, choise1, choise2 - 2));

    // we are doing our best
    return max(left, right);
}

int find_max_memorization(vector<int> v, int choise1, int choise2, vector<vector<int>> &memo_table)
{
    if (choise1 == choise2)
    {
        return v[choise1];
    }
    if (choise1 > choise2)
    {
        return 0;
    }
    if (memo_table[choise1][choise2])
    {
        return memo_table[choise1][choise2];
    }

    int left = v[choise1] + min(find_max_memorization(v, choise1 + 2, choise2, memo_table), find_max_memorization(v, choise1 + 1, choise2 - 1, memo_table));
    int right = v[choise2] + min(find_max_memorization(v, choise1 + 1, choise2 - 1, memo_table), find_max_memorization(v, choise1, choise2 - 2, memo_table));

    int ans = max(left, right);
    memo_table[choise1][choise2] = ans;
    return ans;
}

int find_max_tabulation(vector<int> v)
{
    vector<vector<int>> table(v.size() + 1, vector<int>(v.size(), 0));

    // here we traverse in diagonal way to fill the table
    for (int gap = 0; gap < v.size(); gap++)
    {
        for (int i = 0, j = gap; j < v.size(); i++, j++)
        {
            if (gap == 0)
            {
                table[i][j] = v[i];
            }
            else if (gap == 1)
            {
                table[i][j] = max(table[i][j - 1], table[i + 1][j]);
            }
            else
            {
                table[i][j] = max(
                    v[i] + min(table[i + 2][j], table[i + 1][j - 1]),
                    v[j] + min(table[i + 1][j - 1], table[i][j - 2]));
            }
        }

        /* 
        // to see how we filling table uncomment below code :
        cout << endl;
        cout << "gap is : " << gap << endl;
        for (auto i : table)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        */
    }
    return table[0][v.size() - 1];
}

int main()
{
    int n;
    cout << "enter total no. of coins : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter coins value : ";
    for (auto &i : v)
    {
        cin >> i;
    }

    /*
        sample input : 6 20 30 2 2 2 10
    */
    vector<vector<int>> memo_table(n + 1, vector<int>(n + 1, 0));
    cout << "maximum value player 1 can get using memorization is : " << find_max_memorization(v, 0, n - 1, memo_table) << endl;

    cout << "maximum value player 1 can get using tabulation is : " << find_max_tabulation(v) << endl;

    cout << "maximum value player 1 can get using recursion is : " << find_max_recursion(v, 0, n - 1) << endl;

    return 0;
}