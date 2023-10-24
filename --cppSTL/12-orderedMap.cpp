/*
    * Ordered Map
    -> Maps are implemented as red-black trees (one kind of binary search trees).
    -> Maps are always sorted by its key.
    -> Map's doesn't contians duplicate values. if we try to insert duplicate values then it will rewrite that index's value.
    -> we can use complex data types for key.

    NOTE : maps are not storing values in continous way so we can't use simple iterator on map like we can't use
           it = (map.begin() + 3) but we can use it++;

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

    To learn more about map visit : https://cplusplus.com/reference/map/map/

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

    cout << "Size of map m is : " << m.size() << endl;

    // here because of map is ordered it print in sorted order
    cout << "Elements in map m are : " << endl;
    for (it_traverse = m.begin(); it_traverse != m.end(); it_traverse++)
    {
        cout << (*it_traverse).first << " " << (*it_traverse).second << endl;
    }

    cout << "Is 3 present in map m ? " << m.count(3) << endl;

    // erase takes two kind of input 1) direct key 2) iterator
    // if we use clear then whole map become empty.
    m.erase(3);

    cout << "Remaining elements after erasing 3 from map m are : " << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "Is 3 present in map m ? " << m.count(3) << endl;

    // if that key is not present in the map then it returns map.end()
    cout << "elements in map from key 4 : " << endl;
    auto it = m.find(4);

    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    /*
         Q : find total number of occurance of each element in given string.
         i/p : aabbccdde
         o/p : a 2
               b 2
               c 2
               d 2
               e 1
    */

    map<char, int> cnt;
    string x = "abcslakdlg akdl1 3 5 13 5 23 5 3 2";
    for (char c : x)
    {
        cnt[c]++;
    }
    cout << "Occurance of each element in string s are given below : " << endl;
    for (auto i : cnt)
    {
        cout << i.first << " " << i.second << endl;
    }
    // cout << cnt['1'];

    return 0;
}