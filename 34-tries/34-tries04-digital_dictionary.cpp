/*

    * Digital dictonary
    -> There is a digital dictionary.It has an input field in which one can search any string and the dictionary displays all
       the words whose prefix is that input string in lexicographical order.
    Q: Now we have given a task to make our own digital dictionary. we will be given words that we have to store in our database
       and then we need to design the search functionality And if no such words are available for a given search word, add that
       word to our dictionary.

    i/p : words = 4       cat, cast, what, where     searches : 5 c ca w wha where
    o/p : cast cat
          cast cat
          what where
          what
          where



*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        Node *next[26];
        bool end;
        Node()
        {
            end = false;
            // 26 different nodes for 26 differnet small alphabets.
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    Node *trie_node;
    Trie()
    {
        trie_node = new Node();
    }

    void insert(string &s)
    {
        Node *temp = trie_node;
        int i = 0;
        while (i < s.length())
        {
            // here if character matches then we shift that that node otherwise we create new node and shift on that.
            if (temp && temp->next[s[i] - 'a'] == NULL)
            {
                temp->next[s[i] - 'a'] = new Node();
            }
            temp = temp->next[s[i] - 'a'];
            i++;
        }
        // after we reach to the last character of the word we mark end is true as sign of ending the string here.
        temp->end = true;
    }

    void search(string &s)
    {
        Node *temp = trie_node;
        int i = 0;
        while (i < s.length())
        {
            // if character matches then we go that node otherwise we insert new string and break the loop.
            if (temp->next[s[i] - 'a'])
            {
                temp = temp->next[s[i] - 'a'];
                i++;
            }
            else
            {
                cout << "no suggestions :<< " << endl;
                insert(s);
                break;
            }
        }
        vector<string> ans_array;
        // we do dfs traversal for storing all the next words.
        print_words(temp, s, ans_array, "");
        for (auto i : ans_array)
        {
            cout << i << "\t";
        }
        cout << endl;
    }
    void print_words(Node *iter, string s, vector<string> &ans_array, string cur)
    {
        if (iter == NULL)
        {
            return;
        }
        if (iter->end == true)
        {
            ans_array.push_back(s + cur);
        }
        for (int i = 0; i < 26; i++)
        {
            if (iter->next[i])
            {
                print_words(iter->next[i], s, ans_array, cur + char('a' + i));
            }
        }
    }
};

int main()
{
    Trie dictionary;
    int n;
    cout << "enter total no. of strings : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dictionary.insert(s);
    }

    /*
        sample input : 4 cat cast what where 5 c ca w wha where
    */

    cout << "enter total no. of search queries : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dictionary.search(s);
    }

    return 0;
}