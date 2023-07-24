/*

    * friends pairing problem
    Q : Given n friends, each one can remain single or can be paired up with some other friend.
        Each friend can make pair with only one friend.
        Find out the total number of ways in which friends can remain single or can be paired up.
        NOTE : pair{1,2} and pair{2,1} are same.

    i/p : n = 3
    o/p : 4
        {1}{2}{3} => all single
        {1,2}{3} => pair & single
        {1}{2,3} => pair & single
        {1,3}{2} => pair & single


    * recursion brueforce :
    -> find all the possible paires using recursion and return their count.

                                        f(3)
                               single /      \ pair
                                   f(2)    (2)*f(1)
                           single /  \ pair      \ single
                               f(1)  f(0)       f(0)

        NOTE : here leaves are not returning 2 because they both make pair with each other.

        so here recurrance relation is f(x) = f(x-1)     +       (x-1) * f(x-2)
                                            stay single   can make pair with x-1 guys

        here, we can see that there are some over lapping problems are there so we can memorize that problems.

        * memorization dynamic programming :
        -> make one working recursive program.
        -> use one container-data_structure to store returned values.
        -> use that container to reduce redundant function calls.

        * tabulation dynamic programming :
        -> make one table of size(n+1) and with default value 0.
        -> fill default case if there are if there is one person there is one way that he can be single so table[1] = 1;
           and for table[2] = 2 . either they can make pair or can be stay single.

*/

#include <iostream>
#include <vector>
using namespace std;

int find_pair_recursion(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    int count = 0;
    count = find_pair_recursion(n - 1) + (n - 1) * find_pair_recursion(n - 2);
    return count;
}

int find_pair_memorization(int n, vector<int> &memo_table)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    if (memo_table[n])
    {
        return memo_table[n];
    }
    int count = 0;
    count = find_pair_memorization(n - 1, memo_table) + (n - 1) * find_pair_memorization(n - 2, memo_table);
    memo_table[n] = count;
    return count;
}

int find_pair_tabulation(int n)
{
    vector<int> table(n + 1, 0);
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        table[i] = table[i - 1] + (i - 1) * table[i - 2];
    }
    return table[n];
}

int main()
{
    int n;
    cout << "enter total no. of friends : ";
    cin >> n;

    cout << "total pair of friends using recursion is : " << find_pair_recursion(n) << endl;
    vector<int> memo_table(n + 1, 0);
    cout << "total pair of friends using memorization is : " << find_pair_memorization(n, memo_table) << endl;
    cout << "total pair of friends using tabulation is : " << find_pair_tabulation(n) << endl;
    return 0;
}