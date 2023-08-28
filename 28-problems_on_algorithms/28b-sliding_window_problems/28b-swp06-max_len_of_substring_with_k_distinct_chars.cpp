/*

    * maximum length of the substring contains only k distinct characters in it.
    Q : given a string s and integer k. we have to find the longest substring of string s which contains maximum k distinct
        characters in it.(string contains only small latin alphabets)
    example :  s = "abcbdbdbbdcdabd"   k = 2
    output : "bdbdbbd"

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string find_substr(string s, int k)
{
    unordered_map<char, int> char_freq_map;
    int dist_char = 0, start = 0, left = 0, right = 0, max_len = 0;
    string ans = "";

    while (right < s.length())
    {

        if (char_freq_map[s[right]] == 0)
        {
            dist_char++;
        }

        char_freq_map[s[right]]++;

        while (dist_char > k)
        {
            char_freq_map[s[left]]--;
            if (char_freq_map[s[left]] == 0)
            {
                dist_char--;
            }
            left++;
        }

        if (right - left + 1 > max_len)
        {
            max_len = right - left + 1;
            start = left;
        }
        right++;
    }

    for (int i = start; i < start + max_len; i++)
    {
        ans += s[i];
    }

    return ans;
}

int main()
{
    string s;
    cout << "enter string : ";
    cin >> s;

    int k;
    cout << "enter value of k for distinct charachters : ";
    cin >> k;

    /*

        * sample input : abcbdbdbbdcdabd 2

    */

    cout << "longest substring with " << k << " distinct charachter within it is : " << find_substr(s, k) << endl;

    return 0;
}