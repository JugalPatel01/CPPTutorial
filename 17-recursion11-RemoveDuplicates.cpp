/* Remove all duplicates from the strings using recursion

    "aaaabbbeeecdddd"
--->"abecd"

 */
#include <iostream>
#include <string.h>
using namespace std;

string rmDup(string s)
{

    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = rmDup(s.substr(1));
    if (ch == ans[0])
    {
        return ans;
    }
    return (ch + ans);
}

int main()
{
    string s;
    cout << "enter your string : " << endl;
    cin >> s;

    cout << rmDup(s) << endl;

    return 0;
}