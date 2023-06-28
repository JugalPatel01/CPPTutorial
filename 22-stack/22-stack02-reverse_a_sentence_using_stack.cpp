/*
    Reverse a sentence using stack

    i/p : what is this?
    o/p : this? is what

    * here we are using stack STL for more about stl visit --cppSTL folder
    -> built in function
 */
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

string reverse_sentence(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word = word + s[i];
            i++;
        }
        st.push(word);
    }

    string ans = "";
    while (!st.empty())
    {

        ans = ans + st.top() + " ";
        st.pop();
    }

    return ans;
}

int main()
{
    string a;
    cout << "enter string to reverse : ";
    getline(cin, a);
    string reverse_a = reverse_sentence(a);
    cout << reverse_a << endl;
    return 0;
}