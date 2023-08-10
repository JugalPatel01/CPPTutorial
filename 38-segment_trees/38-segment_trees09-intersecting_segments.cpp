/*

    * Intersecting Segments
    Q : Given an array of 2n numbers, each number from 1 to n in it occurs exactly twice.
        we say that the segment y intersects the segment x if exactly one occurrence of the number y is between the occurences
        of the number x.
        Find for each segment i, how many segment are there that intersect with ith segment.

    i/p : distinct element of an array = 3 , elements [1 2 3 3 1 2]
    o/p : 1{2} 1{1} 0

    approach :
    -> from given array we will make array of interval.
    -> 1 - [0,4]
       2 - [1,5]
       3 - [2,3]
    -> now sort according to interval's ending index.
       3 - [2,3]
       1 - [0,4]
       2 - [1,5]
    -> now we have to find out the number of segments lying partially inside another segment.
    -> to find out that we have to find
        = (ending_of_segment - 1) - (starting_of_segment + 1) - (2 * (no_of_elements_whose_both_occurance_are_in_between))
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ifs
{
    int index, first, second;
};

bool cmp(ifs s1, ifs s2)
{
    return s1.second < s2.second;
}

int query(vector<int> &segment_tree, int node, int start, int end, int query_start, int query_end)
{
    if (start > query_end || end < query_start)
    {
        return 0;
    }
    if (start >= query_start && end <= query_end)
    {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    int ans1 = query(segment_tree, 2 * node, start, mid, query_start, query_end);
    int ans2 = query(segment_tree, 2 * node + 1, mid + 1, end, query_start, query_end);
    return ans1 + ans2;
}

void update_ele(vector<int> &segment_tree, int node, int start, int end, int update_idx, int update_value)
{
    if (start == end)
    {
        segment_tree[node] = update_value;
        return;
    }

    int mid = (start + end) / 2;

    if (update_idx <= mid)
    {
        update_ele(segment_tree, 2 * node, start, mid, update_idx, update_value);
    }
    else
    {
        update_ele(segment_tree, 2 * node + 1, mid + 1, end, update_idx, update_value);
    }

    segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
    return;
}

int main()
{
    int n;
    cout << "enter total no. of element in array : ";
    cin >> n;
    vector<int> v(2 * n);
    vector<ifs> track(n, {-1, -1, -1});

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        track[v[i] - 1].index = v[i];

        if (track[v[i] - 1].first == -1)
            track[v[i] - 1].first = i;
        else
            track[v[i] - 1].second = i;
    }

    sort(track.begin(), track.end(), cmp);
    /*
        sample input : 3 1 2 3 3 1 2
    */

    vector<int> segment_tree(4 * (2 * n) - 1);
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        ans[(track[i].index) - 1] = (track[i].second - track[i].first - 1) - 2 * query(segment_tree, 1, 0, 2 * n - 1, track[i].first, track[i].second);
        update_ele(segment_tree, 1, 0, 2 * n - 1, track[i].first, 1);
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}