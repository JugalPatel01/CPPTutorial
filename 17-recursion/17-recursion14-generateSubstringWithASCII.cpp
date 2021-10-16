/* Generate substrings with ASCII number

    "AB"
    --> ""
        "B"
        "66"
        "A"
        "BA"
        "66A"
        "65"
        "B65"
        "6665"
 */
#include <iostream>
#include <string.h>
using namespace std;
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ans + ch);
    subseq(ros, ans + to_string(code));
}
int main()
{
    string s;
    cout << "enter the string : " << endl;
    cin >> s;
    subseq(s, "");
    return 0;
}