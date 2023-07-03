/*

    * Top K most frequent element in the stream
    i/p : [ 1 2 2 2 3 4]         k = 2
    o/p : 1 2
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void find_elements(vector<int> v, int k, unordered_map<int, int> &freq_map)
{
    for (int i = 0; i < v.size(); i++)
    {
        freq_map[v[i]]++;
        k--;
        if (k == 0)
        {
            return;
        }
    }
}

int main()
{
    int n, k;
    cout << "enter total elements in array : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << "Enter total no. of distinct elements : ";
    cin >> k;

    unordered_map<int, int> freq_map;
    find_elements(v, k, freq_map);

    for (auto i : freq_map)
    {
        cout << i.first << endl;
    }

    return 0;
}