/* move all x to the end of the string 
    "axxbdxcefxhix"
--> "abdcefhixxxxx"


 */
#include <iostream>
#include <string.h>
using namespace std;
string move(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = move(s.substr(1));

    if (ch == 'x')
    {
        return (ans + ch);
    }
    else
    {
        return (ch + ans);
    }
}
int main()
{
    string s;
    cout << "enter the string : " << endl;
    cin >> s;

    cout << move(s) << endl;

    return 0;
}