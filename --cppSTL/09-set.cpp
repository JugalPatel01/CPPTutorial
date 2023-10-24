/*
    # Set
    -> it stores unique data.
    -> stores the values in sorted order.
    -> elements can only be deleted or inserted but can't be modified.
    -> it is implemented as red-black tree (one kind of self balancing binary search tree).

    begin() points to the first element
    rbegin() points to the last element

    end() points to the last element
    rend() points to the first element

    -> To learn more about set visit : https://cplusplus.com/reference/set/set/

*/

#include <iostream>
#include <set>
using namespace std;
int main()
{

    set<int> s;
    s.insert(1); // time complexity O(log(n))
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(6);

    // forward set printing
    cout << "Elements of set s : ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // reverse set printing
    cout << "Printing elements of set s in reverse order : ";
    for (auto i = s.rbegin(); i != s.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin(); // first element
    it++;                              // incrementing value of address by 1 so now it is pointing to second element.
    s.erase(s.begin());

    // erase function is works with both direct values and iterator
    s.erase(it);
    // we can also do s.earse(2);

    cout << "After removing first and second element from the set s we have : ";
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // count function is used to check presence of element in set.
    cout << "Is 5 present in the set ? " << s.count(5) << endl;

    // find function return the address of the given value and if it is not present then it will return end pointer of set.
    set<int>::iterator itr = s.find(5); // it takes O(log N ) time.

    cout << "Value present at itr pointer : " << *itr << endl;
    itr = s.find(10);
    if (itr == s.end())
    {
        cout << "itr pointer's value is end of the set because value 10 is not present in the set." << endl;
    }
    else
    {
        cout << "value is found and value is : " << *itr << endl;
    }

    return 0;
}