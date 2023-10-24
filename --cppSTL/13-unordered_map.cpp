/*
    # Unordered_maps
    -> It is implemented using hash tables.
    -> it doesn't contains duplicate values.
    -> we can't use all datatypes like ordered_map we can use only primitive datatypes in unordered map.
    -> Elements are not ordered so time complexity for inserting element in it is less then ordered map.

                    |    Maps    |   Unordered map  |
        insertion : |  O(log(n)) | O(1) {on average}|
        Accessing : |  O(log(n)) |      O(1)        |
        insertion : |  O(log(n)) |      O(n)        |

    To learn more about unordered_map visit : https://cplusplus.com/reference/unordered_map/unordered_map/

 */
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{

    unordered_map<int, string> u;

    u[1] = "apple";
    u[3] = "tree";
    u[2] = "5";
    u[23] = "map";
    u[8] = "world";

    /*
        loadfactor = size of unordered_map / bucket count
    */
    cout << "total number of key value pairs in unordered_map u are : " << u.size() << endl;
    cout << "total number of used bucket in unordered_map u are : " << u.bucket_count() << endl;
    cout << "load factor of u is : " << u.load_factor() << endl;

    cout << "Elements in unordered_map u are : " << endl;

    for (auto i = 0; i < u.bucket_count(); ++i)
    {
        std::cout << "bucket #" << i << " contains: ";
        for (auto it = u.begin(i); it != u.end(i); ++it)
            std::cout << "[" << it->first << ":" << it->second << "] ";
        std::cout << "\n";
    }
    return 0;
}