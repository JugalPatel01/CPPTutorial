/*

    * Count frequency of elements
    Q. given an array find the frequency for each element.
    i/p : [ 5 6 2 6 3 5 3 7 3 6 ]
    o/p : 2 -> 1
          3 -> 3
          5 -> 2
          6 -> 3
          7 -> 1
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Enter elements in an array : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    unordered_map<int, int> freq_count;

    for (auto i : v)
    {
        freq_count[i]++;
    }

    cout << "frequency count of all elements : " << endl;
    for (auto i : freq_count)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}