/*
    # Multiset
    -> It allows to store same value multiple times unlike set.
    -> stores element in sorted order.
    -> elements can only be deleted or inserted but can't be modified.
    -> it has all the function which set have and have some more like, equal_range() which return range of equal elements, etc...
    -> it is also implemented as red-black tree (Binary search tree).

    To learn more about multiset visit : https://cplusplus.com/reference/set/multiset/

*/

#include <iostream>
#include <set>
using namespace std;
int main()
{

    multiset<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(10);

    cout << "Elements of multiset s : ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    pair<multiset<int>::iterator, multiset<int>::iterator> range = s.equal_range(5);
    cout << "Value before 5 in set is : " << *(--range.first) << " & value after 5 is : " << *(range.second++) << endl;

    // s.erase(5);      // it removes all the elements whose value is 5

    s.erase(s.find(5)); // it removes first occurance of 5

    cout << "After deleting first occurance of 5 remaining elements in mutliset s :  ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}