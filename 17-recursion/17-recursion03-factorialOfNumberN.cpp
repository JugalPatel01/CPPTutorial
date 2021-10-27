#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int ans = fact(n - 1);
    return ans * n;
}
int main()
{

    int a;
    cout << "enter the number for factorial " << endl;
    cin >> a;
    cout << "factorial of number " << a << " is " << fact(a) << endl;

    return 0;
}