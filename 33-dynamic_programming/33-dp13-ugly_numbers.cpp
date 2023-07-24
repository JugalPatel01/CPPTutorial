/*

    * Ugly Numbers
    -> Ugly numbers are numbers whose prime factors are 2,3 or 5 the first 10 ugly numbers are 1,2,3,4,5,6,8,9,10,12.
    NOTE : by convention, 1 is included.

    Q : given a number n, print the n'th ugly number.
    i/p : 10
    o/p : 12

    1) brute-force approach :
    -> take one counter for counting ugly numbers and start a loop from 1 to heightest number possible.
    -> check for ugly number if it's ugly number then increase the ugly number's counter.
        bool uglyNumber(int n){
            n = n % 2 % 3 % 5;
            if(n==1){
                return 1;
            }else{return 0;}
        }
    -> if counter is reached to given position return that value.
    -> it takes O((logk)*k) where k is the nth ugly number.
    -> for more about time compleixty of modular opeartion visit https://cis.temple.edu/~pwang/3223-DA/Lecture/02-Numbers.htm#:~:text=Modular%20arithmetic&text=Their%20complexity%20are%20still%20O,is%20O(n3).

    2) tabulation method :
    -> we create a table with default values 0.
    -> then fill the base case that first ugly number 1 is ugly number.
    -> if we find nth ugly number then it is either 2*u1 or 3*u2 or 5*u3. where u1,u2,u3 are previously calculated ugly numbers.
    -> so, our nth ugly number is min(2*u1 , 3*u2 , 5*u3).
    -> it reduce time complexity to O(n) and also reduce more time by avoiding modular calculation.

*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maximum_divisible_till(int dividend, int divisor)
{
    while (dividend % divisor == 0)
    {
        dividend = dividend / divisor;
    }

    return dividend;
}

bool is_ugly(int n)
{
    n = maximum_divisible_till(n, 2);
    n = maximum_divisible_till(n, 3);
    n = maximum_divisible_till(n, 5);
    if (n == 1)
    {
        return 1;
    }
    return 0;
}

int ugly_number_brute_force(int n)
{
    int counter = 1, i = 2;
    while (counter < n)
    {
        if (is_ugly(i))
        {
            counter++;
        }
        i++;
    }
    return --i;
}

int ugly_number_tabulation(int n)
{
    vector<int> table(n);
    table[0] = 1;
    int u2 = 0, u3 = 0, u5 = 0;
    for (int i = 1; i < n; i++)
    {
        table[i] = min(2 * table[u2], min(3 * table[u3], 5 * table[u5]));
        /*
            * now we increase count for same divisiors.
            for value 6 we have to increase counter of 2 and 3 both to avoid repetation.

        */
        if (2 * table[u2] == table[i])
            u2++;
        if (3 * table[u3] == table[i])
            u3++;
        if (5 * table[u5] == table[i])
            u5++;
    }
    for (auto i : table)
    {
        cout << i << " ";
    }
    return table[n - 1];
}

int main()
{
    int n;
    cout << "enter position for ugly number : ";
    cin >> n;

    cout << n << "th ugly number using brute-force approach is : " << ugly_number_brute_force(n) << endl;
    cout << n << "th ugly number using tabulation method is : " << ugly_number_tabulation(n) << endl;

    return 0;
}