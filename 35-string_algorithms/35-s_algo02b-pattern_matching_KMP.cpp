/*

    * KMP(Knuth-Morris-Patt) Algorithm for pattern matching

     Q : calculate the indices of the occurrences of string s in string t.
    i/p: string s = abcdeabcdef         target_string = abcde
    o/p: 0
           a b c d e a b c d e f
           0 1 2 3 4 5 6 7 8 9 10

    approach :
    -> in bruteforce we have seen that time compelxity for pattern matching is O(n*m) where n is size of string and m is target
       string's size.
    -> and we noticed that in burteforce that in pattern matching we are doing some unnecessary computation which are not needed
       sometimes.
        eg. string s = aaaaaaab         target string : aaaab
        -> so here we are checking aaaa for every time we are not using any previous calculation.
    -> so, KMP algorithm reduces that unnecessary repetation to reduce time compelxity.

    basic idea :
    -> here we storing previous computation which can be use for further calculation.
    -> prefix function calculated for further use to reduce unnecessary repetation:
        => prefix[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this
           substring. By definition, prefix[0] = 0.

            prefix[i] = maximum K such that
            s[0...k-1] = s[i-(k-1)...i]

            eg. T = abcabcd
                               a b c a b c d
                prefix array : 0 0 0 1 2 3 0
    ->  here we get the prefix array for targeted string.
    now, iterate through the given string and maintain 2 variables one i for string and other j for target string

    {

        if(both character are same){
            then increase the count of both i & j.
        }else{
            if(j is not zero (j!=0)){
                then j = prefix[j-1];
            }else{
                i++;
            }
        }

        if(j pointer's size is equal to the target string's size){
            then return i - j ;
            break;
        }

    }

    # for more detail about KMP algo. visit : https://www.youtube.com/watch?v=V5-7GzOfADQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=74

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function_bruteforce(string str)
{
    // here it's time complexity is O(n³) where n is size of string.
    vector<int> pi(str.size(), 0);
    for (int i = 1; i < str.size(); i++)
    {
        for (int k = 0; k <= i; k++)
        {
            // cout << i << " " << k << " \t" << str.substr(0, k) << "\t" << str.substr(i - k + 1, k) << endl;
            if (str.substr(0, k) == str.substr(i - k + 1, k))
            {
                // cout << "i & K " << i << " " << k << endl;
                pi[i] = k;
            }
        }
    }
    return pi;
}

vector<int> prefix_function_improved(string str)
{
    // here it's time compelxity is O(n*k) where n is size of string where k is common string size.
    vector<int> pi(str.size(), 0);
    for (int i = 1; i < str.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            j = pi[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

int main()
{
    string str, target;
    cout << "enter string : ";
    cin >> str;
    cout << "enter targeted string : ";
    cin >> target;

    /*

        sample input : abcdeabcdef abcde

     */

    // vector<int> prefix_indices_for_str = prefix_function_bruteforce(str);
    vector<int> prefix_indices = prefix_function_improved(target);

    /* for (int i = 0; i < target.size(); i++)
    {
        cout << target[i] << " -> " << prefix_indices_for_str[i] << "\t";
    }
    */

    int pos(-1), i(0), j(0);

    while (i < str.length())
    {
        if (str[i] == target[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix_indices[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == target.size())
        {
            pos = i - j;
            break;
        }
    }

    cout << "pattern matched at : " << pos << endl;

    return 0;
}