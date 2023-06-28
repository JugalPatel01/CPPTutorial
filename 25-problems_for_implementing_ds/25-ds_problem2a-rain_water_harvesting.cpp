/*
    * Trapping Rainwater Harvesting Problem

    Q : given an array of integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

    i/p : [0,1,0,2,1,0,1,3,2,1,2,1]

    o/p : 6

                           ____
              ____         |__|__    ____
       ____   |__|_2_ 3 _4_|  |  |_6_|__|__
    ___|  |_1_|  |  |_5_|__|__|__|_ _|__|__|


    brute force approach :
    array                    0  1  0  2  1  0  1  3  2  1  2  1
    left_max                 0  0  1  1  2  2  2  2  3  3  3  3
    right_max                3  3  3  3  3  3  3  2  2  2  1  0
    min(left_max,right_max)  0  0  1  1  2  2  2  2  2  2  1  0
    ans(min - array)>0       0  0  1  0  1  2  1  0  0  1  0  0

 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int find_water(vector<int> v)
{
    int trapped_water = 0;
    int n = v.size();
    vector<int> max_left_ele(n, 0);
    vector<int> max_right_ele(n, 0);
    int max_val = 0;

    for (int i = 1; i < n; i++)
    {
        max_val = max(max_val, v[i - 1]);
        max_left_ele[i] = max_val;
    }

    max_val = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        max_val = max(max_val, v[i + 1]);
        max_right_ele[i] = max_val;
    }

    for (int i = 0; i < n; i++)
    {
        int diff = min(max_right_ele[i], max_left_ele[i]) - v[i];
        if (diff > 0)
        {
            trapped_water = trapped_water + diff;
        }
    }

    return trapped_water;
}

int main()
{
    // input start
    int n;
    cout << "enter value of n : ";
    cin >> n;
    vector<int> blocks(n);
    cout << "enter blocks positions : ";
    for (auto &i : blocks)
    {
        cin >> i;
    }
    // input end

    cout << "total storage of water is : " << find_water(blocks) << endl;
    return 0;
}