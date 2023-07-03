/*
    * Ordered Map
    -> Maps are implemented as red-black trees (one kind of binary search trees).
    -> Map's doesn't contians duplicate values. if we try to insert duplicate values then it will rewrite that index's value.
    -> we can use complex data types for key.

    NOTE : maps are not storing values in continous way so we can't use simple iterator on map like we can't use it = map.begin() + 3.
    but we can use it++;

    * which default values are inserted in map ?
    -> for integer, float , double it's 0
    -> for string it's empty string ""

                    |    Maps                   |   Unordered map  |
        insertion : |  O(log(n)) (for numbers)  | O(1) {on average}|
        Accessing : |  O(log(n))                |      O(1)        |
        insertion : |  O(log(n))                |      O(n)        |


    * difference between map and pair
    -> pair stores two objects but map stores key and values. And keys are unique.

    * difference between multimap and map : 
    -> in multimap repeated keys are allowed.
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> m;

    m[1] = "abc";
    m[2] = "5";
    m[3] = "khb";
    m.insert({4, "kahd"});

    map<int, string>::iterator it_traverse;

    cout << "size of the map is : " << m.size() << endl;
    // here because of map is ordered it print in sorted order
    for (it_traverse = m.begin(); it_traverse != m.end(); it_traverse++)
    {
        cout << (*it_traverse).first << " " << (*it_traverse).second << endl;
    }

    cout << "finding 3 --> " << m.count(3) << endl;

    // erase takes two kind of input 1) direct key 2) iterator
    // if we use clear then whole map become empty.
    m.erase(3);

    cout << "after erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "finding 3 --> " << m.count(3) << endl;

    // if that key is not present in the map then it returns map.end()
    auto it = m.find(4);

    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    // finding number of occurance ;

    map<char, int> cnt;
    string x = "abcslakdlg akdl1 3 5 13 5 23 5 3 2";
    for (char c : x)
    {
        cnt[c]++;
    }
    for (auto i : cnt)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << cnt['1'];

    return 0;
}