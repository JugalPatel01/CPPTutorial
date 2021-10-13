#include <iostream>
using namespace std;
int main()
{

    /*
        1
        01
        101
        0101
        10101
    */
    int n;
    cout << "enter the number of rows ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}