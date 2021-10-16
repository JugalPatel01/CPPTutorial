/* 
    manoj is give the number of visitors at his local theme park on N consecutive ays. The number of visitor son the i-th day is Vi. 
    A day is record breaking if it satisfies both of the following conditions: 
    -->The number of visitors on the day is strictly larger than the number of visitors on each of the previous days. 
    -->Either it is the last day, or the number of visitors on the day is strickly larger than the number of visitors on the following day.
    Note: The very first day could be a record breaking day!
    Please help manoj find out the number of record breaking days.



 */

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the days ";
    cin >> n;
    int arr[n + 1];
    arr[n] = -1;
    cout << "enter the number of the visitors from first day to last day \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mx = -1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] > mx) && (arr[i + 1] < arr[i]))
        {
            mx = arr[i];
            count++;
        }
    }
    cout << "total record breaking days are " << count << endl;

    return 0;
}