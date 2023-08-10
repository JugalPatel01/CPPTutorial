/*

    * Multiplicative Modulo Inverse in modular ar arithmetic

     (A * B) % m = 1
     and A and B are multiplicative modulo inverse of each other for value m.

     eg. :
            (3 * 5) % 14  = 1
            15 % 14
            so 3 and 5 are multiplicative modulo inverse of each other w.r.t. 14.

            (7 * 19) % 15 = 1
            91 * 15
            so 7 and 19 are multiplicative modulo inverse of each other w.r.t. 15.

    "IMPORTANT NOTE" : Multiplicative Modulo inverse exists only if A and m are coprime, so GCD(A,m) = 1.

    so now our task is : we have given an equation ( A % B ) % M = 1 where value of A & M are given
                         and we have to find value of B.

            e.g (3 * B ) % 14 = 1
            now we have to calculate value of B.
            o/p : B = 5

    approach :
            A*B ≡ 1 (mod m)
            A*B - 1 ≡ 0 (mod m)
            A*B - 1 ≡ m*k       where k is any integer.
            A*B - m*k = 1
            now take (-k) = Q
            A*B + m*Q = 1   ........................(1)

            now we know that extended euclidian algorithm is used for solving below equation
            A*x + B*y = GCD(A,B) .........................(2)

            now we know that Multiplicative Modulo inverse exists only if A and m are coprime, so GCD(A,m) = 1.
            so,
            we know A, m , GCD(A,m) = 1
            so
            A*B + m*Q = 1



*/
#include <iostream>
using namespace std;

struct dxy
{
    int d;
    int x;
    int y;
};

dxy extended_euclid_algo(int a, int b)
{
    dxy ans;
    if (b == 0)
    {
        ans.d = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    dxy sub_ans = extended_euclid_algo(b, a % b);

    ans.d = sub_ans.d;
    ans.x = sub_ans.y;
    ans.y = sub_ans.x - (a / b) * sub_ans.y;
    return ans;
}

int find_inverse(int A, int m)
{
    dxy ans = extended_euclid_algo(A, m);
    if (ans.x > 0)
    {
        return ans.x;
    }
    else
    {
        return ans.x + m;
    }
}

int main()
{
    int A, int_for_mod;
    cout << "value of A and value for modulus : ";
    cin >> A >> int_for_mod;

    /*

        sample input : 3 14
    */

    cout << "Multiplicative inverse of A with respect to m is : " << find_inverse(A, int_for_mod) << endl;
    return 0;
}