#include <iostream>
#include<limits.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int max = INT_MIN;
    int minno = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)//maxno=max(maxno,array[i]);
        {
            max = array[i];
        }
        minno=min(minno,array[i]);
    }
    cout<<"max is "<<max<<endl;
    cout<<"min is "<<minno<<endl;

    return 0;
}