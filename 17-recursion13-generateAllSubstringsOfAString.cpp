/* Generate all substrings of a string

    "ABC"
    -->     ""
            "A"
            "B"
            "C"
            "AB"
            "AC"
            "BC"
            "ABC"

 */
#include <iostream>
#include <strings.h>
using namespace std;

void subseq(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros, ans);
    subseq(ros, ans + ch);
}
int main()
{
    string s;
    cout << "enter the string: ";
    cin >> s;
    subseq(s, "");

    return 0;
}