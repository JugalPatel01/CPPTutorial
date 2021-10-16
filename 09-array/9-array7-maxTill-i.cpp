#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the ith element where you want max number ";
    int ith;
    cin >> ith;
    int mx = INT8_MIN;
    for (int i = 0; i < ith; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx << endl;
    }

    return 0;
}