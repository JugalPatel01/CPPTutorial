// Count the number of paths possible from start point to end point in gameboard
// suppose there is a dice to select how many maximum step can we choose so we take 6 in counth path function
// n is the ending point of the gameboard

#include <iostream>
using namespace std;
int countPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter the value of the n :";
    cin >> n;
    cout << countPath(0, n) << endl;

    return 0;
}