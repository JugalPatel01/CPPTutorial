/*

    * search element in sorted & rotated array
    Q : we are given a ascending sorted array that has been rotated from a pivot point (unkonwn to us) and an element X. search
        for x in the array with complexity less than that of linear search.

    i/p : [30, 40 , 50 , 10 , 20]   and key = 10
    o/p :  3 // index of 10 in array

 */
#include <iostream>
#include <vector>
using namespace std;

int find_key(vector<int> v, int key)
{
    int start = 0;
    int end = v.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (key == v[mid])
        {
            return mid;
        }
        if (v[start] <= v[mid])
        {
            
            if (key >= v[start] && key <= v[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (key <= v[end] && key >= v[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "enter no. of the elements in an array : ";
    cin >> n;
    vector<int> v(n);
    cout << "enter elements of an array : ";
    for (auto &i : v)
    {
        cin >> i;
    }
    int key;
    cout << "enter key for serach : ";
    cin >> key;
    cout << "key is at : " << find_key(v, key) << endl;
    return 0;
}