#include <bits/stdc++.h> // add all the library of cpp but increase some compilation time
using namespace std;

#define deb(x) cout << #x << " = " << x << endl;      // Macro for x and its value
#define fo(i, n) for (i = 0; i < n; i++)              // Macro for for loop starting from 0
#define Fo(i, k, n) for (i = k; i < n; i++)           // Macro for for loop starting from k

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

int main()
{

    int x(10), y, z, wz;
    deb(x);
    read(x, y, z, wz);
    deb(x);
    write(x, y, z, wz);

    int i, n;
    read(n);
    vector<int> arr(n, 0);

    fo(i, n) cin >> arr[i];

    Fo(i, 1, n + 1) write(arr[i - 1]);

    return 0;
}