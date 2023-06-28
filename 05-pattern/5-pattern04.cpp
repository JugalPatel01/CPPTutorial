/*
        * print 180 degree rotated left pyramid / print right pyramid

        for value of 5 :
                    *
                  * *
                * * *
              * * * *
            * * * * *
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the stage of pyramid ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    return 0;
}