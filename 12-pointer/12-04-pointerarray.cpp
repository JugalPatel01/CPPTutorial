/*
    Pointers and array

    -> array is a contigous block of memory and first element is start point of that array
    -> so we store first element's address in the pointer to access whole array using pointer.

*/

#include <iostream>
#include <queue>
using namespace std;
int main()
{

    int arr[5];
    cout << arr << endl;
    cout << &arr[0] << endl;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    int *k;
    k = arr;
    for (int i = 0; i < 5; i++)
    {
        cout << "address : " << k << " / " << (arr + i) << endl;
        cout << "value : " << *k << " / " << *(arr + i) << endl;
        k = k + 1; // we can increase the address p = p + 1(size of type of pointer).
    }

    return 0;
}