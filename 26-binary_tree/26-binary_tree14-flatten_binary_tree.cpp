/*

    * Flatten a binary tree
    Q. Given a binary tree, flatten it into linked list in-place.After flattening, left of each nodes should point to NULL and
       right should contain next node in preorder sequence.(It's not allowed to use other data structures)

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

void flatten_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    flatten_tree(root->left);
    flatten_tree(root->right);

    Node *temp = root->right;
    if (root->left)
    {
        root->right = root->left;
        root->left = NULL;
    }

    Node *t = root;
    while (t->right != NULL)
    {
        t = t->right;
    }

    if (temp)
    {
        t->right = temp;
        t->left = NULL;
    }
}

void print_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    cout << root->data << " ";
    print_tree(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
                        1
                       / \
                      2   3
                     / \ / \
                     4 5 6 7
    */

    flatten_tree(root);
    print_tree(root);
    delete root;
    return 0;
}