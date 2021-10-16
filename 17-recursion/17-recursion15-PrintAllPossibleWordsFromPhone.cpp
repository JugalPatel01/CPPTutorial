/* Print all possible words from phone digits */
#include <iostream>
#include <strings.h>
using namespace std;
string keypadArr[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
int main()
{
    int a;
    cout << "Enter the numbers " << endl;
    cin >> a;
    keypad(to_string(a), "");

    return 0;
}