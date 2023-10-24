/*
    # Unordered set
    -> stores only unique values.
    -> elements can be stored in any order.
    -> elements can only be deleted or inserted but can't be modified.
    -> hash-table used to store elements.
    -> elements in the unordered set are not sorted in any particular way, but organized into buckets depending on their hash
       values for fast access of elements.

    To learn more about unordered_set visit : https://cplusplus.com/reference/unordered_set/unordered_set/

    # Unordered multiset
    -> It is same as unordered set but it allow duplicates in it.

*/

#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{

    unordered_set<int> us;
    us.insert(5); // time complexity O(1)
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(8);
    us.insert(8);
    us.insert(8);

    cout << "Elements in unordered_set us are : ";
    for (auto i : us)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Total number of used buckets in the unordered_set us : " << us.bucket_count() << endl;

    cout << "Maximum number of buckets in unordered_set : " << us.max_bucket_count() << endl;

    cout << "Element 5 in bucket no. : " << us.bucket(5) << endl;
    cout << "Element 3 in bucket no. : " << us.bucket(3) << endl;
    cout << "Element 8 in bucket no. : " << us.bucket(8) << endl;

    us.erase(us.find(3)); // time complexity O(1)
    cout << "Remaining elements in us after removing 3 from set are : ";
    for (auto i : us)
    {
        cout << i << " ";
    }
    cout << endl;

    us.clear();
    cout << "Whehter unordered_set us is empty or not ? " << us.empty() << endl;

    return 0;
}