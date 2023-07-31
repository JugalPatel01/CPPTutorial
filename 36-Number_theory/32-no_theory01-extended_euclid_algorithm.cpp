/*

    * Extended Euclid Algorithm

    # Diophnatine Equations
    -> polynomial equations for which integral solution exists are called diophnatine equations
    eg. 5x + y = 1  or x² + y² = z²

    # solution for linear diophnatine equations :
    -> naive algorithm for finding gcd (finding all divisor and match common one) for big number is very lengthy so we use
       euclid algorithm for finding gcd for two numbers.

    suppose, we have equation
         ax + by = c        where, (a,b,c,x,y) all are integer

    "IMPORTANT NOTE" : integer solutions of x & y to these equations exist only if gcd(a,b) divides c.

    so, we can write it like
        ax + by = k * gcd(a,b)      where k is any integer. ....................(0)

        and we know that gcd(a,b) = gcd(b,a%b)          ..................(1)
                         gcd(b,a%b) = bx₁ + (a%b)y₁     ..................(2)
                         a % b = a - b * floor[a/b]     ..................(3) from division theorem

        ax + by =  k(bx₁ + (a%b)y₁) .................(4) from 0 and 2
        suppose k*x₁ = x₂  &  k*y₁ = y₂

        ax + by = bx₂ + (a%b)y₂
        ax + by = bx₂ + (a - floor[a/b] *b)y₂          ................(5) from 3
        ax + by = ay₂ + b(x₂ - floor[a/b] * y₂)

        so we get intger value of x & y for given a and b is : ,
        x = y₂  &  y = (x₂ - floor[a/b] * y₂)

    for learning more about extended_euclid_algorithm refer (chapter 31 -  Number-Theoretic Algorithm) in "INTRODUCTION TO ALGORITHMS" BY CLRS(Thomas H. Cormen,Charles E. Leiserson,Ronald L. Rivest,Clifford Stein)

*/

#include <iostream>
using namespace std;

struct d_x_y
{
    // d is gcd(x,y)
    int d, x, y;
};

d_x_y extended_euclid_algorithm(int a, int b)
{
    d_x_y ans;
    // base case 
    if (b == 0)
    {
        ans.d = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    d_x_y sub_ans = extended_euclid_algorithm(b, a % b);
    ans.d = sub_ans.d;
    ans.x = sub_ans.y;
    ans.y = sub_ans.x - (a / b) * sub_ans.y;
    return ans;
}

int main()
{
    int a, b;
    cout << "enter a's value for ax + by = c : ";
    cin >> a;
    cout << "enter b's value for ax + by = c : ";
    cin >> b;

    /*
        sample input : 6345 925
            6345x + 925y = c
    */

    d_x_y ans = extended_euclid_algorithm(a, b);

    cout << "Gcd of " << a << " & " << b << " is : " << ans.d << endl;
    cout << "interger value of x and y in " << a << "x + " << b << "y = " << ans.d << " is : " << ans.x << " & " << ans.y << " respectivly. " << endl;

    return 0;
}