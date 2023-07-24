/*

    * Dynamic Programming (DP)

    * Properties of Dynamic Programming
    -> optimal substructure
        - If we can write a recurrence relation, then a problem is said to have optimal substructure

    -> overlapping sub problem
        - If our subproblems repeat, then a problem is said to have overlapping subproblem.

    ## when can we use dynamic programming ?
    1) Minimization and maximization problems are generally solved with dp where we want exhaustive solution.
    2) "find Number of ways for do something"
    3) if we can form recurrence relation then we can solve that using DP.

    e.g. fibonacci sequence

                              fib(4)
                           /          \
                        fib(3)       fib(2)
                        /   \       /     \
                    fib(2) fib(1) fib(1) fib(0)
                    /   \
                fib(0) fib(1)

        -> in above example we can see that we have to calcuate same thing for multiple time. like, fib(2)
        -> so rather then calculating same thing for mutliple time just calculate it for one time and store it somewhere for further use.
        -> fib[n] = fib[n-1] + fib[n-2] where fib[1] = 0 and fib[2] = 1.
        -> so fibonacci has both optimal substructure and overlapping subproblem properties.

    ## ways to handle overlapping subproblems
    1) Memorization (Top-down approach)
        -> Recursion is involved.
        -> we maintain one lookup table and we refers it before any computation state.
        -> This approach uses decomposition of formulate a solution.
    2) tabulation (bottom-up approach)
        -> it is an iterative process.
        -> solution is built from base.(solve small problems for solving bigger problem).
        -> basically, the solution is built from a bottom-most case using iteration.
        -> This approach uses composition to develop a solution.

    tips for using memorization technique :
    -> 1) first make a code which works with recursion for any time complexity
    -> 2) then make that program efficient by using some data structure(for giving memory to program) to
          store return values.
    -> 3) use that stored table to reduce unwanted repeated function calls.

    tips for using tabulation technique:
    -> 1) visualize the proglem as a table.
    -> 2) size the table based on the given input.(like, table is of n, n*m, n*m*o, etc...)
    -> 3) initialize the table with default values.
    -> 4) Enter the trivial answer (seed) into the table.
    -> 5) iterate through the table and fill further position based on the current position.

    * why we need tabulation method when we have memorization method.
    -> memorization method uses stack to go from top to down. so it has to save all the recursive call in the stack.
    -> now for some condition it may possible that memory allocated for the memory stack by cpu will become full and we may
       suffer from the stack overflow problem and our program will be crash because of that condition.
    -> so to deal with kind of condition we have to use tabulation method.

*/

/*

    * fibonacci sequence using memorization technique
    Q : given a int k. we have to tell on k'th position which number will come in fibonacci series
    i/p : 7
    o/p : 8
          0 1 1 2 3 5 8

    bruthforce appraoch :
    -> find every terms and go to the next terms which has O(2ⁿ) time complexity.

    Dynamic Programming approach :
    -> we store answer somewhere rather then finding it everytime.
    -> so, with the help of some extra memory we can reduce it's time complexity.
    -> so with dp appraoch we can reduce time-compelxity to O(n) and space complexity is O(n) too.

    for visually understand dynamic programming refer : https://www.youtube.com/watch?v=oBt53YbR9Kk

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long fib_using_recursion(int n)
{
    // it is a bruteforce appraoch and we find fib[n] every time so it's time comeplexity is O(2ⁿ)
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return fib_using_recursion(n - 1) + fib_using_recursion(n - 2);
}

long long fib_using_memorization(int n, unordered_map<int, long long> &fib_store)
{
    // here we check for value in the map so, rather then finding fib[n] everytime we just store ans in one datastrucutre for reference.
    // so it's time complexity is reduced to O(n) and space complexity is also O(n).
    if (n == 0 || n == 1)
    {
        fib_store[0] = 0;
        fib_store[1] = 0;
        return 0;
    }
    if (n == 2)
    {
        fib_store[2] = 1;
        return 1;
    }
    if (fib_store[n])
    {
        return fib_store[n];
    }
    fib_store[n] = fib_using_memorization(n - 1, fib_store) + fib_using_memorization(n - 2, fib_store);
    return fib_store[n];
}

long long fib_using_tabulation(int n)
{
    vector<long long> fib_dp_table(n + 1, 0);
    fib_dp_table[0] = 0;
    fib_dp_table[1] = 0;
    fib_dp_table[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        fib_dp_table[i] = fib_dp_table[i - 1] + fib_dp_table[i - 2];
    }

    return fib_dp_table[n];
}

long long fib_using_3_variable(int n)
{
    long long one = 0, two = 1, temp;
    // generating fibonacci sequence using only O(1) space complexity and O(N) time complexity

    for (int i = 0; i <= n - 3; i++)
    {
        one += two;
        temp = two;
        two = one;
        one = temp;
    }
    if (n == 0 || n == 1)
        return one;
    return two;
}

int main()
{
    int n;
    cout << "enter number for finding that position's number in fibnacci series : ";
    cin >> n;

    /*

    sample input : 35, 45, 70, 93

        NOTE : we can give input till 93 only because if we go beyond 93 then number will become more then storage capacity of container in this case.

        (observation for input above 45) Important thing to notice while running code :
        -> here firstly we calculate fibonacci using memorization dp technique so it solves it in O(N).
        -> but when we calculate fibonacci using normal recursion then it takes much time then memorization technique
        -> and lastly we can see that using tabulation method we can find fibonacci in O(n) time again.
    */

    unordered_map<int, long long> fib_store;
    cout << "fib using memorization : " << fib_using_memorization(n, fib_store) << " \ttime complexity : O(n) & space complexity : O(n^2)" << endl;

    cout << "fib using tabulation : " << fib_using_tabulation(n) << " \ttime complexity : O(n) & space complexity : O(n)" << endl;

    cout << "fib using 3_variable : " << fib_using_3_variable(n) << " \ttime complexity : O(n) & space complexity : O(1)" << endl;

    cout << "fib using recursion : " << fib_using_recursion(n) << " \ttime complexity : O(2^n) & space complexity : O(n)" << endl;

    return 0;
}
