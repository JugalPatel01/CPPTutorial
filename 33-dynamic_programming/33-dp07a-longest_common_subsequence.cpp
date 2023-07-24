/*

    * Longest common subsequence
    Q : Given two strings s1 and s2. We need to output length of longest common subsequence.
    i/p : s1 = "smallworld" s2 = "helloworld"
    o/p : 7
         -> because length of "llworld" is 7.

    1) simple brute-force approach 1 :
    -> find all the subsequences of both the string.
    -> now compair all the subsequence and for matching subsequences get the maximum length's subsequence.
    -> it's time complexity is : O(n² *2ⁿ).

    2) brute-force appraoch 2 :
    -> use recursion to solve problem.
    suppose there are two strings s1 and s2 of size n and m.
    -> now traverse from starting and if both character matches then add that character and increase both string's indeices.
        if(s1[i] == s2[j]) then
            count = 1 + find_common_subsequence(s1,s2,i+1,j+1)
    -> and if both are not same then check increase indices one by one and take maximum of both possiblities.
        if(s1[i]!=s2[j]){
            count = max( find_common_subsequence(s1,s2,i,j+1) ,find_common_subsequence(s1,s2,i+1,j) )
        }
    -> so above approach's time complexity is also O(2ⁿ).
    now, here we can write recurrance relation as shown above for this problem.

        e.g.  s1="ab" , s2= "cab"

                           f(s1,s2,0,0)  max(1,2) = 2
                           /          \
    max(0,1)=1  f(s1,s2,1,0)          f(s1,s2,0,1) 1 + 1
                /          \                   \
    0 f(s1,s2,2,0)   f(s1,s2,1,1) max(0,1)   f(s1,s2,1,2) 1
                      /          \
            0 f(s1,s2,2,1)    f(s1,s2,1,2) 1

        in above example f(s1,s2,1,2) are same so we can use dynammic programming to reduce same type of function calls.

    3) memorization technique :
    -> make working recursive program.
    -> take one container data-structure and store returned value in that.
    -> use that data-structure for reducing unnecessary redundant function calls.

    4) tabulation technique :
    -> build one 2d table and fill default values (in our case it's 0). here row represent s1 and column represent s2
    -> now insert base cases.
    -> iterate for each cell of table and check for conditions
        if(s1[i]==s2[j]){
            table[i][j] = 1 + table[i-1][j-1]
        }
        else{
            table[i][j] = max(table[i-1][j],table[i][j-1])
        }
    -> at last return ans table[s1.length][s2.length]
    -> it reduces time complexity from O(2ⁿ) to O(n*m).where n and m are lengths of strings.

*/

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int find_size_recursion(string s1, string s2, int i, int j)
{
    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }
    int count = 0;
    if (s1[i] == s2[j])
    {
        count = 1 + find_size_recursion(s1, s2, i + 1, j + 1);
    }
    else
    {
        count = max(find_size_recursion(s1, s2, i + 1, j), find_size_recursion(s1, s2, i, j + 1));
    }
    return count;
}

int find_size_memorization(string s1, string s2, int i, int j, vector<vector<int>> &memo_table)
{
    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }
    if (memo_table[i][j])
    {
        return memo_table[i][j];
    }
    int count = 0;
    if (s1[i] == s2[j])
    {
        count = 1 + find_size_memorization(s1, s2, i + 1, j + 1, memo_table);
    }
    else
    {
        count = max(find_size_memorization(s1, s2, i + 1, j, memo_table), find_size_memorization(s1, s2, i, j + 1, memo_table));
    }
    memo_table[i][j] = count;
    return count;
}

int find_size_tabulation(string s1, string s2)
{
    vector<vector<int>> table(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                table[i][j] = 1 + table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[s1.size()][s2.size()];
}

int main()
{
    string s1, s2;
    cout << "enter string s1 and string s2 respectively : ";
    cin >> s1 >> s2;

    cout << s1.size() << endl;
    /*

        sample input : smallworld helloworld
    */

    vector<vector<int>> memo_table(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    cout << "size of longest common subsequence using memorization is : " << find_size_memorization(s1, s2, 0, 0, memo_table) << endl;

    cout << "size of longest common subsequence using tabulation is : " << find_size_tabulation(s1, s2) << endl;

    cout << "size of longest common subsequence using recursion is : " << find_size_recursion(s1, s2, 0, 0) << endl;

    return 0;
}