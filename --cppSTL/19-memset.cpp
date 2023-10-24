/*

    # memset
    -> It copies a single character for a specified number of times to an object.
    -> It is useful for filling a number of bytes with a given value starting from a specific memory location.
    NOTE : for integral datatypes we can set values as 0 or -1.

    To learn more about memset visit : https://cplusplus.com/reference/cstring/memset/
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "hello world";
    cout << "Original string is : " << str << endl;
    memset(str, 'x', sizeof(str)-1);
    cout << "Modified stirng is : " << str << endl;

    int arr[3];
    memset(arr, 0, sizeof(arr));
    cout << "Modified array is : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}