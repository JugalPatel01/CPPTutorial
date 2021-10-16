#include <iostream>
using namespace std;
int main()
{
    /*
            180 degree rotated pyramid
               *
              **
             ***
            ****
*/
    int n;
    cout << "enter the stage of pyramid ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}