/*

    * Find maximum valid BSTs from given no. of nodes
    i/p : n = 3
    o/p :
         1)1        1)2      2)1         3)1         3)2
         3          3        1                       1
        /          /          \                       \
       2          1            3          2            2
      /            \          /          / \            \
     1              2        2          1   3            3
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node *> construct_BSTs(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> left_subtrees = construct_BSTs(start, i - 1);
        vector<Node *> right_subtrees = construct_BSTs(i + 1, end);

        for (int j = 0; j < left_subtrees.size(); j++)
        {
            Node *left = left_subtrees[j];
            for (int k = 0; k < right_subtrees.size(); k++)
            {
                Node *right = right_subtrees[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }

    return trees;
}

void print_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main()
{
    int n;
    cout << "enter no. of nodes : ";
    cin >> n;
    vector<Node *> ans = construct_BSTs(1, n);

    /*

        for value 3 it generates:
        for i = 1 means 1 is root node
        it generates two sub trees for right side of 1
        2          3
         \        /
          3      2

        so we get

        1              1
         \              \
          2              3
           \            /
            3          2

        for i = 2 means 2 is root node
        it generates 1 as a left subtree and 3 as right subtree
        so we get

            2
           / \
          1   3

        for i = 3 means 3 is root node
        1          2
         \        /
          2      1

        so we get

            3        3
           /        /
          2        1
         /          \
        1            2

     */

    for (auto i : ans)
    {
        print_tree(i);
        cout << endl;
    }
    return 0;
}