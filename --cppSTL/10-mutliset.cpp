/*
    Multiset
    -> It allows to store same value multiple times unlike set.
    -> stores element in sorted order.
    -> it is also implemented as Binary search tree.
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

    cout << " our multiset is : ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // s.erase(5);      // it removes all the elements whose value is 5

    s.erase(s.find(5)); // it removes first occurance of 5

    cout << " after deleting first occurance of 5 our multiset is :  ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}