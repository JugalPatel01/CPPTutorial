/*

    Rabin_Karp Algorithm for pattern matching

    Q : calculate the indices of the occurrences of string s in string t.
    i/p: string s = abcdeabcdef         target_string = abcde
    o/p: 0 5
           a b c d e a b c d e f
           0 1 2 3 4 5 6 7 8 9 10

    using string hashing we achive time complexity O(n*m) (where n is size of string and m is size of target string) for pattern matching. now using rabin_karp we algorithm we can further reduce it's time complexity to O(n+m).

    basic approach :
    -> we calculate string hash for target string.
    -> then we use kind of sliding window method to tarverse string and find hash for that substring of that string.
    -> now we compair substring's hash and target string's hash if both are same then there is chance that both strings are same.
    -> here we use chance because of collision. due to the collision there might be a chance to getting same hash value for two
       different strings.
    -> so, we have to use that kind of hash function which is given a less collsion.
    -> and now if both substring's hash and target string's hash are same then we compair the strings.
    -> so above algorithm reduce time complexity to O(n+m) (where n is size of string and m is size of target string)


    for more about robin_karp algorithm visit : https://www.youtube.com/watch?v=qQ8vS2btsxI&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=75

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void find_index(string str, string target)
{
    // here e is prime number, power is for no. of different characters
    int e = 65537, power = 256, str_size = str.length(), target_size = target.length();
    long long highest_power = 1;

    // calculating highest power for changing hash of substring of str
    for (int i = 0; i < target_size - 1; i++)
    {
        highest_power = (highest_power * power) % e;
    }

    // calculating hash for target string
    long long target_hash = 0, string_hash = 0;

    for (int i = 0; i < target_size; i++)
    {
        target_hash = ((target_hash * power) + (target[i] - 'a' + 1)) % e;
        string_hash = ((string_hash * power) + (str[i] - 'a' + 1)) % e;
    }

    // doing hash comparision and using sliding window to traverse whole string str.
    for (int i = 0; i <= str_size - target_size; i++)
    {
        // if both hash are same then check for pattern
        if (string_hash == target_hash)
        {
            int j = 0;
            for (j = 0; j < target_size; j++)
            {
                if (str[i + j] != target[j])
                {
                    break;
                }
            }
            // if pattern match then print value of i for starting of pattern
            if (j == target_size)
            {
                cout << i << " ";
            }
        }

        // slide window and calculate hash for next window
        /*
                |   |
                1 2 3 4 5

                hash = 1*100 + 2*10 + 3*1 = 123

            now calculate hash for next window
                  |   |
                1 2 3 4 5

                hash = (hash - 1*100)*10 + 4*1
                     = (123-100)*10 + 4
                     = 234

                now we will do simillar kind of thing here for string_hash.
        */
        if (i < str_size - target_size)
        {
            string_hash = ((string_hash - (str[i] - 'a' + 1) * highest_power) * power + (str[i + target_size] - 'a' + 1) * 1) % e;

            // to deal with negative hash we have add (e) in to current hash
            /*
                in modulus algebra we know that
                2 % 3 == 5 % 3 == 8 % 3

                so here we see pattern
                (2+0*3)%3 == (2+1*3) % 3 == (2 + 2*3) % 3 == (2 + 3*3) % 3 == ...

                so if we extend this pattern in both positive and negative direction then we get
               -4 % 3 == -1 % 3 ==  2 % 3 == 5 % 3 == 8 % 3

                so formula is :
                (x + i*e) % e == (x+((i+1)*e)) % e == (x+((i+2)*e)) % e
            */
            if (string_hash < 0)
            {
                string_hash = string_hash + e;
            }
        }
    }
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

    cout << "indices where target string matches with string are : ";
    find_index(str, target);
    return 0;
}