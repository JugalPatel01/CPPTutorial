/*

    # Pair
    -> Pair couples together two values, which may be of different data types.

    To learn more about pair visit : https://cplusplus.com/reference/utility/pair/

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// comparison function for sorting
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    // defining a pair
    pair<int, int> p;

    // we can access pair's element using first and second
    p.first = 2;
    p.second = 3;
    // p = {2,3};
    // p = make_pair(2,3);

    cout << "First element of pair p is : " << p.first << " and second element is : " << p.second << endl;

    // using pair into vector
    vector<pair<int, int>> v;

    /* we can also defining pair into 2d vector like this  */
    // vector <vector<pair<int,int>>> v;

    /*
        Q : given an array. we have to print the correct position of the array elements after sorting it in ascending order.
        eg. :
            i/p : arr = { 1 , 2 , 3 , 4}
            o/p : { 0 , 1 , 2 , 3}

        eg. :
            i/p : arr = {4 , 3 , 1 , 2}
            o/p : { 3, 2, 0 , 1 }
     */
    int arr[] = {1, 5, 3, 3, 6, 3, 4, 32, 6, 3, 443, 63, 23};

    cout << "Elements of an array : " << endl;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        /* we can push pair into vector like this manually */

        // pair<int,int> p;
        // p.first = arr[i];
        // p.second = i ;
        // v.push_back(p);

        /* or like this using make_pair function or using {} */

        v.push_back(make_pair(arr[i], i));
        // v.push_back({arr[i], i});

        cout << arr[i] << " ";
    }
    cout << endl;

    // here cmp is comparison function. sorting will be based on that function.
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }

    cout << "Correct positions after sorting : " << endl;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}