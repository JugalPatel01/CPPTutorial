/*

    * Print vertical order of a binary tree
    Q : given an binary tree in array representation print that tree in vertical order.
    array representation of tree :
        parent = i ; left child = 2i + 1; right child = 2i + 2;

    i/p : tree

                 9
                /  \
               8    7
              / \  / \
             4   3/  23
            /    12
           5
   o/p :
        5 4 8 9 3 12 7 23

 */

#include <iostream>
#include <vector>
#include <map>
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

void vertical_order(Node *root, map<int, vector<int>> &ans, int distance)
{
    if (root == NULL)
        return;
    ans[distance].push_back(root->data);
    vertical_order(root->left, ans, distance - 1);
    vertical_order(root->right, ans, distance + 1);
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->left->left->left = new Node(5);
    root->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(23);

    map<int, vector<int>> ans;
    int distance = 0;
    vertical_order(root, ans, distance);

    for (auto i : ans)
    {
        for (auto j : i.second)
        {
            cout << j << " ";
        }
    }
    return 0;
}