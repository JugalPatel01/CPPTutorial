/*

    * LCS in 3 strings
    Q : given 3 strings. we have to find length of longest common subsequences from all of 3 strings.
    i/p : 1) ghqwnv
          2) sjnsdgh
          3) cpgmah
    o/p : 2 (gh)

    NOTE : it is just like a previous LCS_With_2_strings problem but we have to check for one more string.

    1) basic bruteforce approach :
    -> find all the subsequences of all 3 strings.
    -> then check for the common subsequences from them.
    -> find the size of longest common subsequences from them.
    -> it take O(n³ * 2ⁿ) time complexity.

    NOTE : using dynamic programming we can reduce time complexity to O(n³) from exponential.
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int find_size_recursion(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if (i >= s1.size() || j >= s2.size() || k >= s3.size())
    {
        return 0;
    }
    int lcs = 0;
    if (s1[i] == s2[j] && s1[i] == s3[k])
    {
        lcs = 1 + find_size_recursion(s1, s2, s3, i + 1, j + 1, k + 1);
    }
    else
    {
        int first = find_size_recursion(s1, s2, s3, i, j, k + 1);
        int second = find_size_recursion(s1, s2, s3, i, j + 1, k);
        int third = find_size_recursion(s1, s2, s3, i + 1, j, k);
        lcs = max(first, max(second, third));
    }
    return lcs;
}

int find_size_memorization(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &memo_table)
{
    if (i >= s1.size() || j >= s2.size() || k >= s3.size())
    {
        return 0;
    }
    if (memo_table[i][j][k] != -1)
    {
        return memo_table[i][j][k];
    }
    int lcs = 0;
    if (s1[i] == s2[j] && s1[i] == s3[k])
    {
        lcs = 1 + find_size_memorization(s1, s2, s3, i + 1, j + 1, k + 1, memo_table);
    }
    else
    {
        int first = find_size_memorization(s1, s2, s3, i, j, k + 1, memo_table);
        int second = find_size_memorization(s1, s2, s3, i, j + 1, k, memo_table);
        int third = find_size_memorization(s1, s2, s3, i + 1, j, k, memo_table);
        lcs = max(first, max(second, third));
    }
    memo_table[i][j][k] = lcs;
    return lcs;
}

int find_size_tabulation(string &s1, string &s2, string &s3)
{
    vector<vector<vector<int>>> table(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            for (int k = 1; k <= s3.size(); k++)
            {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
                {
                    table[i][j][k] = 1 + table[i - 1][j - 1][k - 1];
                }
                else
                {
                    int first = table[i - 1][j][k];
                    int second = table[i][j - 1][k];
                    int third = table[i][j][k - 1];
                    table[i][j][k] = max(first, max(second, third));
                }
            }
        }
    }

    return table[s1.size()][s2.size()][s3.size()];
}

int main()
{
    string s1, s2, s3;
    cout << "enter string 1, string 2, string 3 respectively : ";
    cin >> s1 >> s2 >> s3;

    vector<vector<vector<int>>> memo_table(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
    cout << "size of longest common subsequence using memorization is : " << find_size_memorization(s1, s2, s3, 0, 0, 0, memo_table) << endl;

    cout << "size of longest common subsequence using tabulation is : " << find_size_tabulation(s1, s2, s3) << endl;

    cout << "size of longest common subsequence using recursion is : " << find_size_recursion(s1, s2, s3, 0, 0, 0) << endl;
    return 0;
}
