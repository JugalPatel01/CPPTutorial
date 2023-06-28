/*
    * Trapping Rainwater Harvesting Problem using stack appraoch

    Q : given an array of integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

    i/p : [0,1,0,2,1,0,1,3,2,1,2,1]

    o/p : 6

                           ____
              ____         |__|__    ____
       ____   |__|_2_ 3 _4_|  |  |_6_|__|__
    ___|  |_1_|  |  |_5_|__|__|__|_ _|__|__|

    steps :
    1) if size of the block is decreasing then we push that block's element in stack
    2) if size of the block will increase then it make a container so we calculate how much water that container can contain.
    3) repeat this steps till last block.
 */

#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

int find_water(vector<int> v)
{
    int trapped_water = 0, n = v.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        // if current element is smaller or equal to the previous element then simply push that index into stack
        // otherwise calcuate how much water that container can trap.
        while (!s.empty() && v[s.top()] < v[i])
        {
            int cur = s.top();
            s.pop();
            if (s.empty())
            {
                break;
            }
            int diff = i - s.top() - 1;

            trapped_water += (min(v[s.top()], v[i]) - v[cur]) * diff;
        }
        s.push(i);
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
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