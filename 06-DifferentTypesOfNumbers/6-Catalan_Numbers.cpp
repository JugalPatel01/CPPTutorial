/*

    * Catalan Numbers
    -> Catalan numbers are a sequence of natural numbers that occur in various conunting problems, often involving recursively defined objects.

    Their closed form is in terms of binomial coefficients:

    Cₙ   =   (1/(n+1)) ²ⁿCₙ
        =   (2n)! / ((n+1)! * n!)
        =   ΣCᵢCₙ₋ᵢ    , i = 0 to n-1

    C₀ = 1
    C₁ = 1
    C₂ = C₀C₁ + C₁C₀ = 2
    C₃ = C₀C₂ + C₁C₁ + C₂C₀ = 5

    so, catalan Numbers are : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786

    * Uses of catalan number
    -> in counting problems like
        1) for valid bst's from given n nodes
        2) given n pairs of Paranthesis / bracket find total valid combinatations
        3) possible paths in matrix(from left-upper most position to right-lower most position path)
        4) dividing a circle using N chords
        5) Dyck words or given length
        6) find max triangles by making cuts in closed polygon of n vertices
        7) find max triangles by joining two vertices in closed polygon of n vertices
        8) how many forest possible from given tree

for learning more about catalan number visit https://en.wikipedia.org/wiki/Catalan_number

*/

#include <iostream>
using namespace std;

int catalan_number(int pos)
{
    // we can reduce it's time complexity by using dynamic programming approach(storing values in the map)
    if (pos == 0 || pos == 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < pos; i++)
    {
        ans += catalan_number(i) * catalan_number(pos - i - 1);
    }

    return ans;
}

int main()
{
    int n;
    cout << "enter position for finding catalan number : ";
    cin >> n;
    cout << n << "th catalan number is : " << catalan_number(n) << endl;
    return 0;
}