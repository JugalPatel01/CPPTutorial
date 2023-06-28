/*
    * Largest rectangle in a histogram
    Q: Given an array. Each element represents the height to the histogram's bar and the width of each bar is 1, find the area of largest rectangle in the histogram.
    -> i/p : [2,1,5,6,2,3]
    -> o/p :  10

    bruteforce_appraoch 2.0

*/
#include <iostream>
#include <deque>
#include <vector>
#include <math.h>
using namespace std;

int find_max_area(vector<int> a)
{
    int n = a.size();
    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        int minh = a[i];
        for (int j = i; j < n; j++)
        {
            minh = min(minh, a[j]);
            int len = j - i + 1;
            max_area = max(max_area, len * minh);
        }
    }

    return max_area;
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of the array : ";
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << "largest area is : " << find_max_area(a) << endl;

    return 0;
}