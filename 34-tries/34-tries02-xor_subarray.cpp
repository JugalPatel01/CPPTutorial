/*

    * Maximum XOR of two numbers in an array
    i/p : [3, 10, 5, 15, 2]
    o/p : 15
        3 xor 10 = 9         5 xor 15 = 10
        3 xor 5 = 6          5 xor 2 = 7
        3 xor 15 = 12        15 xor 2 = 13
        3 xor 2 = 1
        10 xor 5 = 15
        10 xor 15 = 5
        10 xor 2 = 8


    * bruteforce approach :
    -> run two loops and check for each pair and get the maximum.
    -> we can get ans in O(n²) time.

    * trie approach :
    [3 10 5 15 2] == [00011 01010 00101 01111 00010]

                     root
                     /
                    0
                  /   \
                 0     1
                / \   / \
               0  1  0   1
               \  /  \   \
               1  0   1   1
              / \ \   /    \
             0* 1* 1* 0*    1*

        Procedure :
        -> first we make trie node root.
        -> then we insert element's bits one by one in the trie.
        -> after building trie tree we have to find maximum xor between two elements.
        -> now we know that xor is odd function so it if element's bit is 0 then we have to check for 1 and we will go on that node.
        -> we repeat above process for all the elements of an array.
        -> at last we get maximum_xor between two element in O(n*l) time complexity (where n is number of elements in array and l
           is longest length of element).

*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *next[2];
    TrieNode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

int find_xor_bruteforce(vector<int> &v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            ans = max(ans, v[i] ^ v[j]);
        }
    }
    return ans;
}

TrieNode *build_trie(vector<int> &v)
{
    TrieNode *root = new TrieNode();
    for (int i = 0; i < v.size(); i++)
    {
        int ele = v[i];
        TrieNode *iter = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (ele >> j) & 1;
            if (!iter->next[bit])
            {
                iter->next[bit] = new TrieNode();
            }
            iter = iter->next[bit];
        }
    }
    return root;
}

int max_xor(TrieNode *root, vector<int> v)
{
    int max_ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int ele = v[i];
        int curr_xor_ans = 0;
        TrieNode *iter = root;
        for (int j = 31; j >= 0; j--)
        {
            // here we take opposite bit of given element
            int bit = ((ele >> j) & 1) ? 0 : 1;

            // if that bit is present in the trie then we go on that bit otherwise go on another side.
            if (iter && iter->next[bit])
            {
                // here we have do or operation because element's bit and trie bit both are opposite so we it gives xor result 1.
                curr_xor_ans = curr_xor_ans << 1; // 1<<1  ==> 10
                curr_xor_ans |= 1;                // 10 | 01 = 11
                iter = iter->next[bit];
            }
            else
            {
                curr_xor_ans = curr_xor_ans << 1;
                if (iter)
                {
                    iter = iter->next[bit ^ 1];
                }
            }
        }
        max_ans = max(max_ans, curr_xor_ans);
    }
    return max_ans;
}

int find_xor_trie(vector<int> &v)
{
    // here we build the trie for given array elements.
    TrieNode *root = build_trie(v);

    // now we find maximum possible xor of two numbers.
    int ans = max_xor(root, v);

    delete root;
    return ans;
}

int main()
{
    int n;
    cout << "enter total element in array : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    /*
        sample input : 5 5 25 22 8 19           ans : 30
    */

    cout << "maximum xor using bruteforce is : " << find_xor_bruteforce(v) << endl;
    cout << "maximum xor using trie is : " << find_xor_trie(v) << endl;
    return 0;
}