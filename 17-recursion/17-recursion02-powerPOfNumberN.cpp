//calculate n raised to power of p
#include <iostream>
using namespace std;
int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int ans = power(n, p - 1);

    return ans * n;
}

int main()
{
    int n, p;
    cout << "enter number and its power" << endl;
    cin >> n >> p;
    cout << "answer is " << power(n, p) << endl;

    return 0;
}