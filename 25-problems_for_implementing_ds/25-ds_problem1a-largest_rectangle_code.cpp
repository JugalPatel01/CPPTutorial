/*
    * Largest rectangle in a histogram
    Q: Given an array. Each element represents the height to the histogram's bar and the width of each bar is 1, find the area of largest rectangle in the histogram.
    -> i/p : [2,1,5,6,2,3]
    -> o/p :  10

    bruteforce_appraoch using deque

    hint:  take all the possible window size and check for sliding window algorithm

    steps :
    1) make first loop for confirming a window size
    2) for that window size traverse whole array and calculate maximum area using
        max_area = max(max_area , (window size) * (minimum size element in that window))
    3) store and upgrade max area in the max_area variable
    4) return max_area;
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

    for (int window_size = 1; window_size <= n; window_size++)
    {
        int k = window_size;
        deque<int> d;
        for (int x = 0; x < k; x++)
        {
            while (!d.empty() && a[d.back()] > a[x])
            {
                d.pop_back();
            }
            d.push_back(x);
        }
        max_area = max(window_size * a[d.front()], max_area);

        for (int j = k; j < n; j++)
        {
            if (d.front() == j - k)
            {
                d.pop_front();
            }
            while (!d.empty() && a[d.back()] > a[j])
            {
                d.pop_back();
            }
            d.push_back(j);
            max_area = max(window_size * a[d.front()], max_area);
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