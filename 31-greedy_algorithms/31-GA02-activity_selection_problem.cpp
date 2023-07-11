/*

    * Activity selection problem
    Q : given n activities with their start and finish times. select the maximum number of activities that can be
        performed by a single person, assuming that a person can only work on a single activity at a time.
    i/p : n = 3
        [[10 20][12 15][20 30]]
    o/p : 2
        [10 20][20 30]

    theoratically we make a gantt chart for all the activities's starting time and ending time and according to that
    we decide that which activities will be performed.

    like ,

                    0 ------------------ 10 ---- 12 ----- 15 --------- 20 ------------------------ 30

    activity 1 :                         _______________________________
    activity 2 :                                 ___________
    activity 3 :                                                        __________________________

    so from above diagram we can say that we can do (1 & 3) or (2 & 3) activity because their time interval's are
    not colloiding with each other.

    practically , we find a time interval and sort in increasing manner. and then take one by one activity and check whether their time intervals are colloiding with each other or not.

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_activities(vector<pair<int, int>> v)
{
    sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });
    int count = 1;
    int end = v[0].second;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= end)
        {
            count++;
            end = v[i].second;
        }
    }

    return count;
}

int main()
{
    int n;
    cout << "Enter total no. of activities : ";
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "starting time of activity " << i + 1 << " : ";
        cin >> v[i].first;
        cout << "finishing time of activity " << i + 1 << " : ";
        cin >> v[i].second;
    }

    cout << "we can max complete " << find_activities(v) << " activities ";

    return 0;
}