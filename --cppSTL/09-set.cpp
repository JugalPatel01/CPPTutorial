/*
    Set
    -> it stores unique data
    -> stores the values in sorted order.
    -> elements can only be deleted or inserted but can't be modified.
    -> it is implemented as binary search tree.

    begin() points to the first element
    rbegin() points to the last element

    end() points to the last element
    rend() points to the first element
 */
#include <iostream>
#include <set>
using namespace std;
int main()
{

    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(6);

    // reverse set printing
    for (auto i = s.rbegin(); i != s.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // forward set printing
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(s.begin());

    s.erase(it);
    // we can also do s.earse(2);

    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "is 5 there in set? : " << s.count(5) << endl;

    set<int>::iterator itr = s.find(5);

    cout << "value present at itr " << *itr << endl;
    return 0;
}