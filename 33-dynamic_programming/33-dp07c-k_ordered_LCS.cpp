/*

    * K_ordered LCS
    Q : print the LCS of two sequences.given that we are allowed to change atmost k elements in the first sequence to any value
        we wish to.

    i/p : array_1 : [1 2 3 4 5]  , array_2 : [5 3 1 4 2] , k = 1
    o/p : 3
            array 1 : [1 2 3 4 5] => [1 2 3 4 2]
            array 2 : [5 3 1 4 2]
            largest common subsequence is : [1 4 2]

    NOTE : it is same as finding LCS but we have to add one case for k's value.

    before :
                if(v1[i] == v2[j])
                    case_1 = LCS(v1,v2,i+1,j+1);  // if both element are same

                c2 = max(LCS(v1,v2,i+1,j),LCS(v1,v2,i,j+1));

                return max(c1,c2);
    after :
                if(v1[i] == v2[j])
                    case_1 = LCS(v1,v2,i+1,j+1,k);  // if both element are same

                if(k > 0)
                    c2 = LCS(v1,v2,i+1,j+1,k-1);      // consider k's value here

                c3 = max(LCS(v1,v2,i+1,j,k),LCS(v1,v2,i,j+1,k));

                return max(c1,max(c2,c3));

*/
#include <iostream>
#include <vector>
using namespace std;

int find_lcs_recursion(vector<int> &v1, vector<int> &v2, int i, int j, int k)
{
    if (i >= v1.size() || j >= v2.size())
    {
        return 0;
    }
    int lcs = 0;
    if (v1[i] == v2[j])
    {
        lcs = 1 + find_lcs_recursion(v1, v2, i + 1, j + 1, k);
    }
    if (k > 0)
    {
        lcs = max(lcs, 1 + find_lcs_recursion(v1, v2, i + 1, j + 1, k - 1));
    }
    lcs = max(lcs, max(find_lcs_recursion(v1, v2, i + 1, j, k), find_lcs_recursion(v1, v2, i, j + 1, k)));
    return lcs;
}

int find_lcs_memorization(vector<int> &v1, vector<int> &v2, int i, int j, int k, vector<vector<vector<int>>> &memo_table)
{
    if (i >= v1.size() || j >= v2.size())
    {
        return 0;
    }
    if (memo_table[i][j][k] != -1)
    {
        return memo_table[i][j][k];
    }
    int lcs = 0;
    if (v1[i] == v2[j])
    {
        lcs = 1 + find_lcs_memorization(v1, v2, i + 1, j + 1, k, memo_table);
    }
    if (k > 0)
    {
        lcs = max(lcs, 1 + find_lcs_memorization(v1, v2, i + 1, j + 1, k - 1, memo_table));
    }
    lcs = max(lcs, max(find_lcs_memorization(v1, v2, i + 1, j, k, memo_table), find_lcs_memorization(v1, v2, i, j + 1, k, memo_table)));

    memo_table[i][j][k] = lcs;
    return lcs;
}

int find_lcs_tabulation(vector<int> v1, vector<int> v2, int k_value)
{
    vector<vector<vector<int>>> table(v1.size() + 1, vector<vector<int>>(v2.size() + 1, vector<int>(k_value + 1, 0)));

    for (int k = 0; k <= k_value; k++)
        for (int i = 1; i <= v1.size(); i++)
        {
            for (int j = 1; j <= v2.size(); j++)
            {
                {
                    if (v1[i - 1] == v2[j - 1])
                    {
                        table[i][j][k] = 1 + table[i - 1][j - 1][k];
                    }
                    if (k - 1 >= 0)
                    {
                        table[i][j][k] = max(table[i][j][k], 1 + table[i - 1][j - 1][k - 1]);
                    }
                    table[i][j][k] = max(table[i][j][k], max(table[i - 1][j][k], table[i][j - 1][k]));
                }
            }
        }
    return table[v1.size()][v2.size()][k_value];
}

int main()
{
    int n1, n2, k;
    cout << "enter size of first array : ";
    cin >> n1;
    cout << "enter size of second array : ";
    cin >> n2;

    vector<int> v1(n1), v2(n2);
    for (auto &i : v1)
    {
        cin >> i;
    }
    for (auto &i : v2)
    {
        cin >> i;
    }

    cout << "enter size of k : ";
    cin >> k;

    /*

        sample input : 5 5 1 2 3 4 5 5 3 1 4 2 1
    */
    vector<vector<vector<int>>> memo_table(v1.size() + 1, vector<vector<int>>(v2.size() + 1, vector<int>(k + 1, -1)));
    cout << "find longest common subsequences using memorization : " << find_lcs_memorization(v1, v2, 0, 0, k, memo_table) << endl;
    cout << "find longest common subsequences using recursion : " << find_lcs_recursion(v1, v2, 0, 0, k) << endl;
    cout << "find longest common subsequences using tabulation : " << find_lcs_tabulation(v1, v2, k) << endl;

    return 0;
}