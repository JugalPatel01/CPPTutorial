/*

    * Trie Bash
    Q : Given an array arr of size N. we have to find the maximum value of
        (arr[a] ^ arr[a+1] ^ arr[a+2] ... ^ arr[b]) + (arr[c] ^ arr[c+1] ... ^ arr[d]) where 1 <= a <= b < c <= d <= N.
    NOTE : ^ denotes xor operation.

    i/p : N = 4     array = [1 2 3 4]
    o/p : 10
         a = 1, b = 2, c = 3, d = 4
         (1^2) + (3^4) = 3 + 7 = 10


*/

#include <iostream>
#include <vector>
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

void insert(TrieNode *root, int val)
{
    TrieNode *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (val >> i) & 1;
        if (temp->next[bit] == NULL)
        {
            temp->next[bit] = new TrieNode();
        }
        temp = temp->next[bit];
    }
}

int xor_till_i(TrieNode *root, int ele)
{
    TrieNode *iter = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = ((ele >> i) & 1) ? 0 : 1;
        if (iter && iter->next[bit])
        {
            iter = iter->next[bit];
            ans |= 1 << i;
        }
        else
        {
            if (iter)
                iter = iter->next[bit ^ 1];
        }
    }
    return ans;
}

int find_sum(vector<int> v)
{
    int ans = 0;
    vector<int> rev(v.size() + 1, 0);
    TrieNode *trie = new TrieNode();
    insert(trie, 0);
    int right_side = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        right_side = right_side ^ v[i];
        if (i != v.size() - 1)
        {
            rev[i] = max(rev[i + 1], xor_till_i(trie, right_side));
        }
        else
        {
            rev[i] = xor_till_i(trie, right_side);
        }
        insert(trie, v[i]);
    }

    trie = new TrieNode();
    insert(trie, 0);
    int left_side = 0;
    for (int i = 0; i < v.size(); i++)
    {
        left_side = left_side ^ v[i];
        ans = max(ans, rev[i + 1] + xor_till_i(trie, left_side));
        insert(trie, left_side);
    }
    delete trie;
    return ans;
}

int main()
{
    int n;
    cout << "Enter total number of element in an array : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    cout << "maximum sum of xor of two disjoint subarray is : " << find_sum(v);
    return 0;
}