/*

    * find all possible valid combination of parenthesis
    Q : we have given a number n. we have to find all the valid parenthesis combination for that n parentheses.
    i/p : 3
    o/p :
          ((()))
          (())()
          (()())
          ()(())
          ()()()
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void find_combinations(int open, int close, string str, vector<string> &ans, int &count)
{
    if (open == 0 && close == 0)
    {
        count++;
        ans.push_back(str);
        return;
    }

    if (open != 0)
    {
        str += '(';
        find_combinations(open - 1, close, str, ans, count);
        str.pop_back();
    }

    if (close > open)
    {
        str += ')';
        find_combinations(open, close - 1, str, ans, count);
        str.pop_back();
    }
}

int main()
{
    int n;
    cout << "enter total pair of parenthesis : ";
    cin >> n;

    vector<string> ans;
    int count = 0;

    // here we pass number of remaining '(', number of remaining ')',ans vector
    find_combinations(n, n, "", ans, count);

    cout << "total combinations are  : " << count << endl;

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}