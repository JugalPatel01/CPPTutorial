/*
    * longest substring wihtout repeating character
    Q. Given a string s, find the length of the longest substring without repeating characters.
    i/p : abcabcbb
    o/p : 3
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int check_string(string s)
{
    vector<int> char_map(256, -1);
    int ans = 0, start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        int x = (int)s[i];
        if (char_map[x] != -1)
        {
            start = char_map[x];
        }
        char_map[x] = i;
        ans = max(ans, i - start);
    }

    return ans;
}

int main()
{
    string s;
    cout << "enter string : ";
    cin >> s;
    cout << "longest contiguous substring is : " << check_string(s) << endl;
    return 0;
}