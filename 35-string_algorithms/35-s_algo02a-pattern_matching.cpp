/*
    {

        # substr function :
        syntax : string substr(starting_pos, length)
        working : it returns the string that starts at character position starting_pos and spans len charachters(or until the
                  end of the string, which ever comes first.)
        time complexity : O(n) where n is size of string.

    }

    Q :   calculate the indices of the occurrences of string s in string t.
    i/p: string s = abcdeabcdef         target_string = abcde
    o/p: 0 5
           a b c d e a b c d e f
           0 1 2 3 4 5 6 7 8 9 10

    * brute-force approach :
    -> compare (substrings of given string of (size of target string)) and (given target string)
    -> if both strings are same then print it's index.
    -> it's time complexity is O(n*m) where n is size of given string and m is size of target string.

 */

#include <iostream>
#include <string.h>
using namespace std;

void find_index_bruteforce(string s, string target)
{
    for (int i = 0; i < s.length() - target.length() + 1; i++)
    {
        if (s.substr(i, target.length()) == target)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    string s, target;
    cout << "enter string : ";
    cin >> s;
    cout << "enter target string : ";
    cin >> target;

    /*
        sample input :  abcdeabcdef abcde
    */

    cout << "indeices for target string in given string are : ";
    find_index_bruteforce(s, target);
    cout << endl;

    return 0;
}