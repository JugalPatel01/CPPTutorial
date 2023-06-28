/*

    * Check for BST
*/
#include <iostream>
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

bool subtree_lesser(Node *root, int val)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < val && subtree_lesser(root->left, val) && subtree_lesser(root->right, val))
    {
        return true;
    }

    return false;
}

bool subtree_greater(Node *root, int val)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > val && subtree_greater(root->left, val) && subtree_greater(root->right, val))
    {
        return true;
    }
    return false;
}

bool check_for_BST(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (subtree_lesser(root->left, root->data) && subtree_greater(root->right, root->data) && check_for_BST(root->left) && check_for_BST(root->right))
    {
        return true;
    }
    return false;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(8);

    /*
                            3
                           / \
                          2    7
                         /    / \
                        1    5   8
     */

    cout << "is give tree BST? " << check_for_BST(root);
    delete root;
    return 0;
}