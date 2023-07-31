/*

    * sum of first n fibonacci numbers
    Q : Given a number N, we have to find the sum of first n fibonacci numbers.
    i/p : 6
    o/p : 12
            0 + 1 + 1 + 2 + 3 + 5  = 12

    approach :

        fibo(n) = fibo(n-1) + fibo(n-2)
        sum(n) = sum(n-1) + fibo(n)

        [sum(n)           [ [a b c]           [sum(n-1)
         fibo(n)        =   [d e f]       *    fibo(n-1)
         fibo(n-1)]₃ₓ₁      [g h i] ]₃ₓ₃       fibo(n-2)]₃ₓ₁

         from above equation we get
        sum(n) = a * sum(n-1) + b*fibo(n-1) + c*fibo(n-2)
        and we know that sum(n) = sum(n-1) + fibo(n)
        so a = 1, b = 1, c = 1

        fibo(n) = d * sum(n-1) + e * fibo(n-1) + f * fibo(n-2)
        and we know that fibo(n) = fibo(n-1) + fibo(n-2)
        so d = 0, e = 1, f = 1

        fibo(n-1) = g * sum(n-1) + h * fibo(n-1) + i * fibo(n-2)
        so g = 0, h = 1, i = 0

        so, finally we get

        [sum(n)           [ [1 1 1]           [sum(n-1)
         fibo(n)        =   [0 1 1]       *    fibo(n-1)
         fibo(n-1)]₃ₓ₁      [0 1 0] ]₃ₓ₃       fibo(n-2)]₃ₓ₁

        [sum(n)           [ [1 1 1]          [ [1 1 1]           [sum(n-2)
         fibo(n)        =   [0 1 1]       *    [0 1 1]       *    fibo(n-2)
         fibo(n-1)]₃ₓ₁      [0 1 0] ]₃ₓ₃       [0 1 0] ]₃ₓ₃       fibo(n-3)]₃ₓ₁

        [sum(n)           [ [1 1 1]          [ [1 1 1]                  [sum(2)
         fibo(n)        =   [0 1 1]       *    [0 1 1]       * ... *     fibo(2)
         fibo(n-1)]₃ₓ₁      [0 1 0] ]₃ₓ₃       [0 1 0] ]₃ₓ₃              fibo(1)]₃ₓ₁

         so here we do matrix multiplication for ((n-1) - (2) + 1) = (n-2) times

        [sum(n)           [ [1 1 1]          [ [1 1 1]                  [1
         fibo(n)        =   [0 1 1]       *    [0 1 1]       * ... *     1
         fibo(n-1)]₃ₓ₁      [0 1 0] ]₃ₓ₃       [0 1 0] ]₃ₓ₃              0]₃ₓ₁

        [sum(n)           [ [1 1 1]  ⁿ⁻²        [1
         fibo(n)        =   [0 1 1]       *      1
         fibo(n-1)]₃ₓ₁      [0 1 0] ]₃ₓ₃         0]₃ₓ₁



*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> ans(a.size(), vector<int>(a.size(), 0));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return ans;
}

vector<vector<int>> find_sum(vector<vector<int>> &base_matrix, int n)
{
    if (n <= 0)
    {
        return {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    }
    if (n == 1)
    {
        return base_matrix;
    }
    vector<vector<int>> sub_ans = find_sum(base_matrix, n / 2);
    vector<vector<int>> ans = multiply(sub_ans, sub_ans);
    if (n & 1)
    {
        ans = multiply(ans, base_matrix);
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter position of fibonacci series for finding sum till that position : ";

    cin >> n;

    if (n <= 1)
    {
        cout << "sum till " << n << "th position is : " << 0 << endl;
    }
    else
    {

        vector<vector<int>> base_matrix = {{1, 1, 1},
                                           {0, 1, 1},
                                           {0, 1, 0}};

        vector<vector<int>> ans = find_sum(base_matrix, n - 2);

        /*
            [sum(n)           [ [1 1 1]  ⁿ⁻²        [1
             fibo(n)        =   [0 1 1]       *      1
             fibo(n-1)]₃ₓ₁      [0 1 0] ]₃ₓ₃         0]₃ₓ₁

            [sum(n)           [ [a b c]             [1
             fibo(n)        =   [d e f]       *      1
             fibo(n-1)]₃ₓ₁      [g h i] ]₃ₓ₃         0]₃ₓ₁

             so sum = a*1 + b*1 + c*0 =  a + b;

        */

        cout << "sum till " << n << "th position is : " << ans[0][0] + ans[0][1] << endl;
    }
    return 0;
}