/*

    * Set

    There are total two types of sets :
    1) ordered set and 2) unordered set

    1) ordered set :
    -> Contains unique elements
    -> Implemented using balanced BST
    -> all the elements in the set are ordered in any order like, accending , descending.
    -> random access is not possible, i.e we can't get iᵗʰ element in O(1)/O(logn).

    ==> time complexity of both ordered set and multiset is :
    insertion : O(log N)
    deletion : O(log N)
    lower_bound /upper_bound : O(log N)


    2) unordered set : all the elements in the set are unordered.
    -> Contains unique elements
    -> Implemented using Hashing
    -> elements are not in sorted order.
    -> random access is not possible, i.e we can't get iᵗʰ element in O(1)/O(logn).

    ==> time complexity in unordered_set is: 
    insertion : O(1) in avg case, O(N) in worst case
    deletion : O(1) in avg case, O(N) in worst case
    lower_bound / upper_bound : NA

      * Ordered Multi Set
    -> Can contain duplicates
    -> implemented using balanced BST
    -> Elements are in sorted order
    -> random access is not possible, i.e. we can't get iᵗʰ element in O(1) / O(logn)


    for more about set & mutliset visit --cppSTL folder 09-set.cpp to 11-unordered_set.cpp

*/

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    cout << "print set : ";
    for (auto i : s)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << "print reverse set : ";

    for (auto i = s.rbegin(); i != s.rend(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    cout << endl;
    cout << "size of the set is : " << s.size() << endl;
    cout << endl;

    cout << "upper bound of 3 is : " << *s.upper_bound(3) << endl;
    cout << "lower bound of 3 is : " << *s.lower_bound(3) << endl;
    cout << "wheter upper bound of 4 is equal to s.end() ? : " << (s.upper_bound(4) == s.end()) << endl;
    cout << endl;

    s.erase(4);
    s.erase(s.begin());
    cout << "after erasing elements from the set is : ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    // custom comparator
    set<int, greater<int>> s_dec;
    s_dec.insert(1);
    s_dec.insert(2);
    s_dec.insert(3);
    s_dec.insert(4);

    cout << "------------- set with greater comparator ----------------" << endl;
    cout << "elements are : ";
    for (auto i = s_dec.begin(); i != s_dec.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << endl;
    cout << "------------- unordered set ----------------" << endl;
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(4);
    us.insert(2);
    us.insert(3);
    us.erase(us.begin());

    cout << "elements in unordered set are : ";
    for (auto i : us)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;
    cout << "------------- Multiset with greater comparator ----------------" << endl;
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(5);

    cout << "elements of multiset are : ";
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    ms.erase(2);
    ms.erase(ms.find(3));

    cout << "after erasing all occurance of 2 & one occurance of 3 : ";
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}