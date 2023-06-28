/*

    * binar_search
    -> use binary_search to find element in the sorted data structures.

    * lower_bound
    -> if value is present in the data structure then it return that value's pointer and if it's not present then it next bigger value's  pointer.

    * upper_bound
    -> if bigger value present in that data strcutre then it returns that value's pointer otherwise it returns last pointer of
    the data structure. eg. in set it returns set.end() in case if there is no bigger element in the set.

    * max , min , swap , reverse , rotate , sort , find , count , transform , next_permutation , prev_permutation
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(51);
    v.push_back(56);

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "is 5 is present in vector?? " << binary_search(v.begin(), v.end(), 5) << endl; // binary search
    cout << "is 15 is present in vector?? " << binary_search(v.begin(), v.end(), 15) << endl;

    cout << "lower bound --> " << lower_bound(v.begin(), v.end(), 51) - v.begin() << endl; // lower bound
    cout << "upper bound --> " << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;  // upper bound

    int a = 5;
    int b = 3;
    cout << "max " << max(a, b) << endl; // max
    cout << "min " << min(a, b) << endl; // min

    cout << "a --> " << a << endl;
    cout << "b --> " << b << endl;
    swap(a, b); // swap
    cout << "a --> " << a << endl;
    cout << "b --> " << b << endl;

    string ab = "abcd";
    reverse(ab.begin(), ab.end()); // reverse
    cout << "string is " << ab;

    rotate(v.begin(), v.begin() + 1, v.end()); // rotate
    cout << "after rotate" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end()); // sort  --> based on intro sort (mixture of)( quick sort, heap sort, insertion sort)
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}