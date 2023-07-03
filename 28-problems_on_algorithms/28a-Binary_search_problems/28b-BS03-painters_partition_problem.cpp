/*

    * Painters Partition Problem
    Q. A painter paints 1 unit of board in 1 unit of time & each paitner will paint consecutive boards. Find the minimum time
       that will be required to paint all the boards.

    i/p: length of different boards = [10, 20, 30, 40 ]          no. of painters m = 2
    o/p :
            possible partitions
            [10][20, 30, 40] -> 90
            [10, 20][30, 40] -> 70
            [10, 20, 30][40] -> 60
            so ans is [10, 20, 30][40] -> 60
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool can_do(vector<int> v, int val, int painters)
{
    int time_sum = 0;
    painters--;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > val)
        {
            return false;
        }
        time_sum += v[i];
        if (time_sum > val)
        {
            painters--;
            if (painters < 0)
            {
                return false;
            }
            time_sum = v[i];
        }
    }
    return true;
}

int find_min_time(vector<int> v, int painters)
{
    int total_time = 0;
    for (auto i : v)
        total_time += i;
    int start = v[v.size() - 1], end = total_time;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (can_do(v, mid, painters))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    int n;
    cout << "enter total no. of boards : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter time taken by painter to paint each board : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    int painters;
    cout << "enter total no of painters : ";
    cin >> painters;

    if (painters <= n)
    {
        int minimum_time = find_min_time(v, painters);
        cout << "minimum time required is : " << minimum_time << endl;
        vector<vector<int>> ans;
        vector<int> x;
        int pos = v[0];
        x.push_back(v[0]);

        for (int i = 1; i < n; i++)
        {
            if (pos > minimum_time)
            {
                ans.push_back(x);
                x.clear();
                pos = v[i];
                x.push_back(v[i]);
            }
            else
            {
                pos += v[i];
                x.push_back(v[i]);
            }
        }
        ans.push_back(x);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "painters are more than boards :<";
    }

    return 0;
}