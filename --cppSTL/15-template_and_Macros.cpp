/*
    # templates in C++

    template has it's own advantages and disadvantages :
    advantages :
    1) we don't have to write a function for all different datatypes just by using template we can write a function for that.
    2) we can use only one template for building class and methods of various datatypes.
    disadvantages :
    1) we can't use pointers and references with template
    2) it's difficult to deal with two different parameters in template(we have to overload functions for that)

    To learn more about template function visit : https://cplusplus.com/doc/oldtutorial/templates/

    NOTE :  #include <bits/stdc++.h> add all the library of cpp but increase some compilation time.

*/
/*
    # preprocessor directives
        * macro definitions (#define, #undef)
        * conditional includsions (#ifdef, #ifndef, #if, #endif, #else, #elif)
        * Line control (#line)
        * Error diretive (#error)
        * source file inclusion (#include)
        * Pragma directive (#pragma)

    To learn more about preprocessor diretives visit : https://cplusplus.com/doc/tutorial/preprocessor/

*/

#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << " = " << x << endl; // Macro for x and its value
// The operator #, followed by a parameter name, is replaced by a string literal that contains the argument passed.
#define fo(i, n) for (i = 0; i < n; i++)    // Macro for for loop starting from 0
#define Fo(i, k, n) for (i = k; i < n; i++) // Macro for for loop starting from k

template <typename... T> // Using template for read multiple arguments
void read(T &...args)
{
    ((cin >> args), ...);
}

template <typename... T> // Using template for write multiple arguments
void write(T... args)
{
    ((cout << args << " "), ...);
}

template <typename T>
T sum(T a, T b)
{
    T res;
    res = a + b;
    return res;
}

int main()
{
    int x(10), y, z, wz;
    debug(x);
    cout << "Enter values of x, y, z, wz : ";
    read(x, y, z, wz);
    debug(x);
    cout << "Values of x, y, z, wz : ";
    write(x, y, z, wz);
    cout << endl;

    cout << "Sum of x, y is : " << sum<int>(x, y) << endl;

    int i, n;
    cout << "Enter value of n : ";
    read(n);
    vector<int> arr(n, 0);

    cout << "Enter elements of array : ";
    fo(i, n) cin >> arr[i];

    cout << "Elements of array are : ";
    Fo(i, 1, n + 1) write(arr[i - 1]);

    return 0;
}