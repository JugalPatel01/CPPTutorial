/*

    * string hash

     string     ========hash_function=======>   Unique_hash_for_string

    * existing rolling hash function
     "111100" = 1*2⁵ + 1*2⁴ + 1*2³ + 1*2² + 0*2¹ + 0*2⁰ = 60
     "342" = 3*10² + 4*10¹ + 5*10⁰ = 342
     "ab...z" --> "12...26"= 1*30⁰ + 2*30¹ + 3*30² + ... + 3*30²⁵

    NOTE : above hash function are exponentially increasing so, to reduce it's time complexity and space complexity we have to
           use different hash functions.

    so, we can use here modulus function as a hash function to get efficient hash.
     commonly used mod = 65537(2¹⁶+1) / 1000000007(1e9 + 7)
     NOTE : here in modulus operator there is possibility of collision unlike exponential functions.
            but it reduce time and space complexity.to deal with that collision we can use chaining method, mutliple hash
            function,etc...

*/

/*
    Find number of unique strings
    i/p:  strings =6    array = [aa ab aa b cc aa]
    o/p : 4

    brueforce approch :
    method 1) compair each strings with other strings and find for uniqueness in them.
              It takes O(N²) time.
    method 2) sort the array of strings and then iterate from start to end and find for unique strings.
              It takes O(N*logN*K) time where N is no. string and K is size of string.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int find_strings_bruteforce(vector<string> &v)
{
    int count = 0;
    // TIme complexity : O(N*logN*K)         where N is no. string and K is size of string.
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0 || v[i] != v[i - 1])
        {
            count++;
        }
    }
    return count;
}

long long calculate_hash(string s, vector<long long> powers, int e)
{
    int hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash = (hash + (s[i] - 'a' + 1) * powers[i]) % e;
    }
    return hash;
}

int find_strings_hashing(vector<string> v)
{
    // Time complexity for getting unique strings using hashing is O(N*K + N*logN) where N is no. of strings, k is length of string.
    int power = 31, e = 65537;
    vector<long long> powers(v.size(), 1);
    powers[0] = 1;
    for (int i = 1; i < v.size(); i++)
    {
        powers[i] = powers[i - 1] * power % e;
    }

    // time compelxity for find hash = O(N*K) where N is no. of strings and K is length of string
    vector<long long> hashes;
    for (auto i : v)
    {
        hashes.push_back(calculate_hash(i, powers, e));
    }

    // sorting takes O(N*logN) time
    sort(hashes.begin(), hashes.end());
    int count = 0;
    for (int i = 0; i < hashes.size(); i++)
    {
        if (i == 0 || hashes[i] != hashes[i - 1])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;
    cout << "enter total no. of strings in array : ";
    cin >> n;
    vector<string> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    /*

        sample input : 6 aa ab aa b cc aa
    */
    cout << "total unique strings using brueforce is : " << find_strings_bruteforce(v) << endl;
    cout << "total unique strings using hashing is : " << find_strings_hashing(v) << endl;
    return 0;
}
