/*

    * Matrix Exponentiation
    -> for given a square matrix A, we have to find Aⁿ.
    NOTE : Matrix Exponentiation is only possible for square matrices.

                                          Matrix Exponentiation
                     ____________________________|_________________________
                    |                                                      |
         Matrix multiplication                                  Binary Exponentiation

    NOTE : matrix multiplication takes O(N³) time complexity and binary exponentiation takes O(logP) time compleixty
            so Matrix exponentiation takes O(N³*logP) time compleixty.

*/

/*
    * fibonacci series using matrix exponentiation.
    i/p : 6
    o/p : 5
          position    :  1 2 3 4 5 6 7
          fibo series :  0 1 1 2 3 5 8

    fibo(n) = fibo(n-1) + fibo(n-2) where fibo(1) = 0 , fibo(2) = 1

    [fibo(n)       =  [[a b]    *   [fibo(n-1)
    fibo(n-1)]₂ₓ₁      [c d]]₂ₓ₂     fibo(n-2)]₂ₓ₁

    [fibo(n)       = [ a*fibo(n-1) + b*fibo(n-2)
    fibo(n-1)]₂ₓ₁      c*fibo(n-1) + d*fibo(n-2) ]

    so we get a = 1 , b = 1, c = 1, d = 0.

    [fibo(n)       =  [[1 1]    *   [fibo(n-1)
    fibo(n-1)]₂ₓ₁      [1 0]]₂ₓ₂     fibo(n-2)]₂ₓ₁

    [fibo(n)       =  [[1 1]    *   [[1 1]    *  [fibo(n-2)
    fibo(n-1)]₂ₓ₁      [1 0]]₂ₓ₂     [1 0]]₂ₓ₂     fibo(n-3)]₂ₓ₁

    [fibo(n)       =  [[1 1]    *   [[1 1]    *  ....      *   [fibo(2)
    fibo(n-1)]₂ₓ₁      [1 0]]₂ₓ₂     [1 0]]₂ₓ₂                   fibo(1)]₂ₓ₁

    here we started from n-1 and we have reached to 2 so total we have done ((n-1) - (2) + 1) = n-2 multiplication.

    [fibo(n)       = [ [[1 1]      ⁿ⁻²      *   [fibo(2)
    fibo(n-1)]₂ₓ₁       [1 0]]₂ₓ₂ ]              fibo(1)]₂ₓ₁

    [fibo(n)       = [ [[1 1]      ⁿ⁻²      *   [1
    fibo(n-1)]₂ₓ₁       [1 0]]₂ₓ₂ ]              0]₂ₓ₁

    -> it's time compleixty is O(K³*logN)where K³ is constant so, it's O(logN).

*/
#include <iostream>
#include <vector>
using namespace std;

// matrix multiplication
vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = 2;
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

// Binary and Matrix exponentiation
vector<vector<int>> matrix_expo(vector<vector<int>> &base_matrix, int n)
{
    if (n <= 0)
    {
        return {{1, 0}, {0, 1}};
    }
    if (n == 1)
    {
        return base_matrix;
    }
    vector<vector<int>> sub_ans = matrix_expo(base_matrix, n / 2);
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
    cout << "enter fibonacci series's position number : ";
    cin >> n;

    /*

        sample input : 8
                o/p : 13

     */

    if (n <= 1)
    {
        cout << n << "th positioned number in fibonacci serires is : " << 0 << endl;
        return 0;
    }
    vector<vector<int>> base_matrix = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = matrix_expo(base_matrix, n - 2);
    /*
        [fibo(n)       = [ [[1 1]      ⁿ⁻²      *   [1
        fibo(n-1)]₂ₓ₁       [1 0]]₂ₓ₂ ]              0]₂ₓ₁

        [fibo(n)       = [[x y]      *   [1
        fibo(n-1)]₂ₓ₁     [w z]]₂ₓ₂       0]₂ₓ₁

        fibo(n) = x*1 + y*0 = x
    */
    cout << n << "th positioned number in fibonacci serires is : " << ans[0][0] << endl;

    return 0;
}