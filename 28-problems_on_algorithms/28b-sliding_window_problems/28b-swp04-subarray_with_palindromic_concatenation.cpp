/*

    * Subarray of size K with palindromic concatenation
    Q : For a given array and an integer K , check if any subarray of size K exists in the array such that concatenation of
        elements form a palindrome

 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_pali(string s)
{
    int start = 0, end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool check_pali(vector<int> v, int k)
{
    string str = "";
    for (int i = 0; i < k; i++)
    {
        str += to_string(v[i]);
    }
    if (is_pali(str))
    {
        for (int i = 0; i < k; i++)
        {
            cout << v[i] << " ";
        }
        return true;
    }

    for (int i = k; i < v.size(); i++)
    {
        int remove = to_string(v[i - k]).length();
        str = str.substr(remove, str.length()) + to_string(v[i]);
        if (is_pali(str))
        {
            for (int j = i - k + 1; j <= i; j++)
            {
                cout << v[j] << " ";
            }
            cout << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "enter no. of elements in an array : ";
    cin >> n;
    cout << "enter elements of an array : ";
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int k;

    cout << "size of subarray is : ";
    cin >> k;

    if (k < n)
    {
        bool check = check_pali(v, k);
        cout << "is there any subarray of size " << k << " exist in array with palindromic property ? : " << check;
    }

    return 0;
}