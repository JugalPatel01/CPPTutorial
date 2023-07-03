/*
    * unordered_maps
    -> implemented using hash tables
    -> doesn't contains duplicate values
    -> we can't use all the datatyeps unlike ordered_map we can use only primitive data types.
    -> they are not ordered so time complexity for inserting element in it is less then ordered map

                    |    Maps    |   Unordered map  |
        insertion : |  O(log(n)) | O(1) {on average}|
        Accessing : |  O(log(n)) |      O(1)        |
        insertion : |  O(log(n)) |      O(n)        |


 */
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{

    unordered_map<int, string> u;

    u[1] = "abc";
    u[3] = "khb";
    u[2] = "5";

    for (auto i : u)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}