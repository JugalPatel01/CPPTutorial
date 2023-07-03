/*

    Hashing
    -> It is a process of mapping keys and values into the hash table by using a hash function.
    -> It is done for faster access to elements( so basically it is used for indexing).

    * types of hash functions :
    1) division method
    2) mid square method
    3) folding method
    4) multiplication method, etc...

    problems in hashing :
    -> storing indices of such large elements.

    solution for above problem :
    converting element into smaller elements using some functions (hash functions)

    3523523533 -> 5                                                 3 -> 5
    3523535329 -> 9         -> hash function h(x) = h % 10          9 -> 9
    3523523237 -> 20                                                7 -> 20

    now suppose for two values we get only one index (so here collision occured)
    -> so to deal with collision we can use multiple techniques
    1) seperate chaining 2) open addressing

    1) sepereate chaining (Open hashing)
    -> if collision occurs then create chain of values at same key using liked list.
    -> disadvantage : worst case time complexity : O(n)

    2) Open addressing (closed hashing)
    -> Using a second argument called probe number in the hash function.
    -> Probe number depends on key, hence given by P(k).
    -> there are different kinds of way for doing open addressing
    a) linear probing       P(k) = a*k + b
    b) quadratic probing    P(k) = a*K² + b*k + c
    c) double hashing       P(k,x) = k*h₂(x)    where h₂(x) is a secondary hash function.

    * what is load factor ?
    -> total no. of elements/ total no. of keys
    -> it is used to determine load for each keys

    * rehashing
    -> when hashmap becomes full, the load factor increases.
    -> As load factor increases, the number of collisions also increases.
    -> so we resize the hashmap. it called rehashing

    * for more about map and unordered_map visit 12-orderedMap.cpp & 13-unordered_map.cpp in --cppSTL folder

                    |    Maps    |   Unordered map  |
        insertion : |  O(log(n)) | O(1) {on average}|
        Accessing : |  O(log(n)) |      O(1)        |
        insertion : |  O(log(n)) |      O(n)        |

        Maps :
        -> it is key-value pair
        -> implemented using Red-Black trees

        Unordered Map :
        -> it is key-value pair
        -> implemented using hash tables

 */

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    map<int, int> m;
    
    m[8] = 2;
    m[3] = 5;
    m[1] = 2;
    m[6] = 8;
    cout << "size of map is : " << m.size() << endl;
    cout << "element on key 8 is : " << m[8] << endl;

    cout << "element in maps : " << endl;
    for (auto i : m)
    {
        cout << i.first << " => " << i.second << endl;
    }

    m.erase(3);
    cout << " after erasing 3 from the map remaining elements in map : " << endl;
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " => " << (*it).second << endl;
    }
    return 0;
}