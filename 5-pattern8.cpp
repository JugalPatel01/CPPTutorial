#include <iostream>
using namespace std;
int main()
{

    /*
    12345
    1234
    123
    12
    1   
    */
    int n;
    cout << "enter the no. of rows";
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
