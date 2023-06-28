/* 
    * Unordered set
    -> elements can be stored in any order.
    -> stores only unique values.
    -> hash-table used to store elements.

    * unordered multiset
    -> same as unordered set but it allow duplicates in it.
*/
#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{

    unordered_set<int> us;
    us.insert(5);
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(8);
    us.insert(8);
    us.insert(8);

    for (auto i : us)
    {
        cout << i << " ";
    }
    cout << endl;

    us.erase(us.find(3));
    for (auto i : us)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}