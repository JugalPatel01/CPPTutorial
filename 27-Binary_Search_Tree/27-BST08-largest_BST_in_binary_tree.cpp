/*

    * Largest BST in a binary tree
    Q : Return the size of the largest BST in a binary tree.

*/

#include <iostream>
#include <math.h>
#include <climits>
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

struct info_about_tree
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

info_about_tree find_BST(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, 1};
    }
    if (!root->left && !root->right)
    {
        return {1, root->data, root->data, 1, 1};
    }

    info_about_tree left = find_BST(root->left);
    info_about_tree right = find_BST(root->right);

    info_about_tree curr;
    curr.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && root->data > left.max && root->data < right.min)
    {
        curr.isBST = 1;
        curr.min = min(root->data, left.min);
        curr.max = max(root->data, right.max);
        curr.ans = curr.size;
        return curr;
    }
    curr.min = min(right.min, min(root->data, left.min));
    curr.max = max(left.max, max(root->data, right.max));
    curr.ans = max(left.ans, right.ans);
    curr.isBST = 0;
    return curr;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    /*
                    4
                   / \
                  2   6
                 / \ / \
                1  3 5  7
    */
    cout << "size of the bst is : " << find_BST(root).ans;
    delete root;

    return 0;
}