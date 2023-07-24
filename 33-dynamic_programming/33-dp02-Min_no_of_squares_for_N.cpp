/*

    Q: Minimum number of squares whose sum equals to give number 'N'.
    i/p : N = 26
    o/p : 2
        26 = 4² + 3² + 1²   {total 3 numbers}
           = 5² + 1²    {total 2 numbers}

    1) brute-froce approach :
    -> first take 1 to sqrt(n) different numbers.
    -> now consider all the posibilities for all the numbers
    -> e.g
                    4           sqrt(4) = 2
                1²/   \ 2²
                 3     0
              1²/ \2²
               2  -1
            1²/ \2²
             1   -2
          1²/ \2²
           0  -3

    -> NOTE : time complexity for above code is O(N^sqrt(N)).

    now, we can write a recurrance relation for above question
    base case : f(0) = 0
                f(1) = 1²
                f(2) = 1² + 1²
                f(X) = min(f(x-(i²)) + 1)   here we take i from 1 to sqrt(n) because we know that we can't add bigger number
                                            then square of(sqrt(n)) in sum.
    and it has some repeatation problems so now we can solve it with dynamic programming too.

    2) memorization appraoch :
    -> take one map/ vector any type of container and store returned value by given function.
    -> and utilize that container to reduce unwanted function calls to reduce time complexity.
    -> using memorization technique we can achive time complexity of O(N*sqrt(N)).

    3) tabulation appraoch :
    -> initialize table of size one more then given input and fill it with INT_MAX(Because we wan't minimum number).
    -> enter base cases in the table.
    -> traverse a vector and for each value explore all the posibilites from 1 to sqrt(N) and get minimum value for reaching to that number.
    -> at the end return array index of given number.suppose for N return arr[N].

*/

#include <iostream>
#include <math.h>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

int find_min_square_bruteforce(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + find_min_square_bruteforce(n - i * i));
    }
    return ans;
}

int find_min_square_memorization(int n, unordered_map<int, int> &memo_table)
{

    if (memo_table[n])
        return memo_table[n];

    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + find_min_square_memorization(n - i * i, memo_table));
    }
    memo_table[n] = ans;
    return ans;
}

int find_min_square_tabulation(int n)
{
    // init table of bigger then size n
    vector<int> table(n + 1, INT_MAX);

    // define base conditions value.
    table[0] = 0;
    table[1] = 1;
    table[2] = 2;
    table[3] = 3;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            if (i + j * j <= n)
            {
                table[i + j * j] = min(table[i + j * j], table[i] + 1);
            }
        }
    }
    /*
        visulization for 4

        initially :
              0   1   2   3     4
            | 0 | 1 | 2 | 3 | INT_MAX |

        after first loop we get :
              0       1      2   3     4
            | 0 | min(1,1) | 2 | 3 | INT_MAX |

        after second loop we get :
              0   1   2   3     4
            | 0 | 1 | 2 | 3 | min(INT_MAX,1 + 0) |

        after all loop we get :
              0   1   2   3   4
            | 0 | 1 | 2 | 3 | 1 |

        NOTE : do dry run using n = 4 for more understanding.

     */
    return table[n];
}

int main()
{
    int n;
    cout << "enter number for getting least number of square to make that number : ";
    cin >> n;

    unordered_map<int, int> memo_table;
    cout << "total no. of minimum squares number required to generate given number " << n << " using memorization is : " << find_min_square_memorization(n, memo_table) << endl;

    cout << "total no. of minimum squares number required to generate given number " << n << " using tabulation is : " << find_min_square_tabulation(n) << endl;

    /*

        sample input : 50, 60 , 100, 1000
        NOTE : here we can see that for large input like 100 or 1000
            -> we get answer in memorization & tabulation technique very easily because it has time complexity of N*sqrt(N).
            -> but using bruteforce approach it takes N^(sqrt(N)) time complexity, so it gives result after long time.
    */
    cout << "total no. of minimum squares number required to generate given number " << n << " using recursion is : " << find_min_square_bruteforce(n) << endl;

    return 0;
}