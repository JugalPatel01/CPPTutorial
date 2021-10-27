#include <iostream>
using namespace std;
int main()
{
    //largest word in a sentence.

    int n;
    cout << "enter the length of line ";
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    cout << "enter line " << endl;
    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int curr = 0;
    int max = 0;
    int startst = 0, endst = 0;
    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (curr > max)
            {
                max = curr;
                endst = startst;
            }
            curr = 0;
            startst = i + 1;
        }
        else
        {
            curr++;
            
        }
        if (arr[i] == '\0')
        {
            break;
        }

        i++;
    }

    cout << "max length " << max << endl;
    for (int i = 0; i < max; i++)
    {
        cout << arr[i + endst];
    }

    return 0;
}