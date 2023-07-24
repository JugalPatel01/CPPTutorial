/*

    * Number of subsequences
    Q : Given a string s consisting of lower case latin letters ('a' -'z') and some '?'.
        our task is to find no. of subsequences 'abc' in all the strings '?' should be replaced by either of {'a','b','c'};
    i/p : ac?b?c
    o/p : 24
            acabac  ->    2
            acabbc  ->    4
            acabcc  ->    4
            acbbac  ->    2
            acbbbc  ->    3
            acbbcc  ->    4
            accbac  ->    1
            accbbc  ->    2
            accbcc  ->    2
            total ==      24

    * bruteforce approach :
    -> find all the possible subsequences and then find the subsequences of abc and sum up that.
       it takes time complexity O(2ⁿ * 3ˣ) where n is length of string and x is no. of question marks.

    * tabulation approach :
    -> there are two method in this approch 1) using table 2) using simple variables.


        we will fill table using below rules :
        -> our base case is if string string is empty then empty is 1.
        -> now if 'a' comes then count of 'a' become (previous count of a) + (total empty strings). so we get total number of
           a's occurance in all strings.
        -> now if 'b' comes then count of 'ab' become (previous count of ab) + (total count of 'a'). so we get total number of
           ab's occurance in all strings.
        -> now if 'c' comes then count of 'abc' become (previous count of abc) + (total count of 'ab'). so we get total number of abc's occurance in all strings.
        -> now if ? comes then we multipy 'abc' string's value with 3 and add count of 'ab' in that because then we get 3
           different kind of strings.
           then ab's count also multiply by 3 and add count of 'a' because of same reasons.
           then a's count also multipy by 3 and add count of 'empty' because of same reasons.
           and atlast we have to multiply count of 'empty' by 3.


         element|   empty   |  a          |    ab     |     abc     |
         ------------------------------------------------------------
            a   |   empty   | a+empty     |    ab     |     abc     |
            b   |   empty   |  a          |   ab+a    |     abc     |
            c   |   empty   |  a          |    ab     |  abc + ab   |
           d-z  |   empty   |  a          |    ab     |      abc    |
            ?   |  3*empty  | 3*a + empty | 3*ab + a  |  3*abc + ab |


    # now we fill the table (by default value of table's element is zero and our base case is 1 at empty string)

            | empty |   a   |   c   |   ?   |   b   |   ?   |   c   |
     empty  |   1   |   1   |   1   |   3   |   3   |   9   |   9   |
        a   |   0   |   1   |   1   |   4   |   4   |  15   |  15   |
        ab  |   0   |   0   |   0   |   1   |   5   |  19   |  19   |
        abc |   0   |   0   |   0   |   0   |   0   |   5   |  24   |

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int find_subseq_using_tabulation(string str)
{
    // rows of table is 4 because we have 4 counters 1) empty 2) 'a' 3) 'ab' 4) 'abc'
    vector<vector<int>> table(4, vector<int>(str.size() + 1, 0));

    table[0][0] = 1;

    /*
        0 -> empty
        1 -> 'a'
        2 -> 'ab'
        3 -> 'abc'
     */
    for (int i = 1; i <= str.size(); i++)
    {
        if (str[i - 1] == 'a')
        {
            table[0][i] = table[0][i - 1];                   // empty = prev_empty
            table[1][i] = table[1][i - 1] + table[0][i - 1]; // a = prev_a + prev_empty
            table[2][i] = table[2][i - 1];                   // ab = prev_ab
            table[3][i] = table[3][i - 1];                   // abc = prev_abc
        }
        else if (str[i - 1] == 'b')
        {
            table[0][i] = table[0][i - 1];                   // empty = prev_empty
            table[1][i] = table[1][i - 1];                   // a = prev_a
            table[2][i] = table[2][i - 1] + table[1][i - 1]; // ab = prev_ab + prev_a
            table[3][i] = table[3][i - 1];                   // abc = prev_abc
        }
        else if (str[i - 1] == 'c')
        {
            table[0][i] = table[0][i - 1];                   // empty = prev_empty
            table[1][i] = table[1][i - 1];                   // a = prev_a
            table[2][i] = table[2][i - 1];                   // ab = prev_ab
            table[3][i] = table[3][i - 1] + table[2][i - 1]; // abc = prev_abc + prev_ab
        }
        else if (str[i - 1] == '?')
        {
            table[0][i] = 3 * table[0][i - 1];                   // empty = 3 * prev_empty
            table[1][i] = 3 * table[1][i - 1] + table[0][i - 1]; // a = 3 * prev_a
            table[2][i] = 3 * table[2][i - 1] + table[1][i - 1]; // ab = prev_ab
            table[3][i] = 3 * table[3][i - 1] + table[2][i - 1]; // abc = prev_abc + prev_ab
        }
    }

    return table[3][str.size()];
}

int find_subseq_using_easy_method(string str)
{
    // it is a simpler form of above table
    int empty = 1, a = 0, ab = 0, abc = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            a += empty;
        }
        else if (str[i] == 'b')
        {
            ab += a;
        }
        else if (str[i] == 'c')
        {
            abc += ab;
        }
        else if (str[i] == '?')
        {
            abc = 3 * abc + ab;
            ab = 3 * ab + a;
            a = 3 * a + empty;
            empty = 3 * empty;
        }
    }
    return abc;
}

int main()
{
    string str;
    cout << "enter string : ";
    cin >> str;
    /*
        sample input : ac?b?c

        NOTE : here find_subseq_using_tabulation is method for understanding concept easily.
                and find_subseq_using_easy_method is easy to reduced version of find_subseq_using_tabulation.
    */

    cout << "total abc subsequences using recursion are : " << find_subseq_using_tabulation(str);
    cout << "total abc subsequences using recursion are : " << find_subseq_using_easy_method(str);
    return 0;
}