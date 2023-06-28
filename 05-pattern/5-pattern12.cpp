/*

        * print centre pyramid style palindromic pattern
        for value 5 :
                1
              2 1 2
            3 2 1 2 3
          4 3 2 1 2 3 4
        5 4 3 2 1 2 3 4 5
*/
#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "enter the number of rows : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        for (int j = 2; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
