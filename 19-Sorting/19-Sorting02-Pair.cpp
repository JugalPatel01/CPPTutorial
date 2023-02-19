#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool newCompare(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first < p2.first);
}

int main()
{
    // pair allows to store pair of objects
    pair<int, string> p1;

    p1.first = 3;
    p1.second = "hello";

    cout << "first item of pair P1 is " << p1.first << endl;
    cout << "Second item of pair P1 is " << p1.second << endl;

    /* reduce given array

        input : 10 15 2 42 23 5 23
        output : 2 3 0 6 4 1 5

     */

    int arr[] = {10, 15, 2, 42, 23, 5, 23};
    vector<pair<int, int>> v;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {

        /*
            pair<int, int> p;
            p.first = arr[i];
            p.second = i;
            v.push_back(p);
        */

        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end(), newCompare);

    for (int i = 0; i < v.size(); i++)
        {
            arr[v[i].second] = i;
        }

    cout<<"reduced array is "<<endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}