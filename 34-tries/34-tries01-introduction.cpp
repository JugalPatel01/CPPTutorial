/*

    Tries (prefix tree / digital tree) :
    -> It is a type of k-ary search tree used for storing and searching a specific key from a set.
    -> Trie (derived from retrieval) is a multiway tree data structure used for storing strings over an alphabet.
       we store strings just like in dictionary.

    here, we store [cat, cast ,cost,cow] using trie data structure.
        * means word is ending there.
                                                 c
                                               /   \
                                              a     o
                                             / \   / \
                                            s  t*  s  w*
                                            \      /
                                             t*    t*


*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie
{
public:
    // node for storing character at that place.
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };

    node *trie;
    Trie()
    {
        trie = new node();
    }

    void insert(string word)
    {
        int i = 0;
        node *iter = trie;
        while (i < word.size())
        {
            if (iter->next[word[i] - 'a'] == NULL)
            {
                iter->next[word[i] - 'a'] = new node();
            }
            iter = iter->next[word[i] - 'a'];
            i++;
        }
        iter->end = true;
    }

    bool search(string word)
    {
        node *temp = trie;
        int i = 0;
        while (i < word.size())
        {
            if (temp->next[word[i] - 'a'])
            {
                temp = temp->next[word[i] - 'a'];
                i++;
            }
            else
            {
                return false;
            }
        }

        return temp->end;
    }
};

int main()
{
    Trie *dict = new Trie();
    vector<string> words = {"cow", "cost", "cat", "cast"};

    for (auto i : words)
    {
        dict->insert(i);
    }

    if (dict->search("camel"))
        cout << "camel exists in the dictonary." << endl;
    else
        cout << "camel is not in the dictonary." << endl;

    if (dict->search("cow"))
        cout << "cow exists in the dictonary." << endl;
    else
        cout << "cow is not in the dictonary." << endl;

    delete dict;
    return 0;
}