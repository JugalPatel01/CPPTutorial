/*

    * policy based ordered set

    # features of policy based ordered set
    -> normal set operations + 2 extra opeartions
        1) find_by_order(k)  => it returns that kth position element     ==> time complexity is : O(log N)
        2) order_of_key(k) => it returns count of strictly less number then k ==> time complexity is : O(log N)

*/

#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    oset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    // find_by_order() return that position's element
    cout << "2nd element is : " << *s.find_by_order(2) << endl;

    // order_of_key() return count of strictly less number then given number
    cout << "total number less then 3 is : " << s.order_of_key(3) << endl;

    return 0;
}