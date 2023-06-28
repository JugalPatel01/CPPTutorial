/*
        * sum replacemen in a binary tree
        -> replace the value of each node with the sum of all subtree nodes and itself

        i/p:
                        1
                       / \
                      2   3
                     / \ / \
                     4 5 6 7
        o/p:

                       28
                       / \
                     11  16
                     / \ / \
                    4  5 6  7
 */

#include <iostream>
#include <math.h>
#include <queue>
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

void cal_sum(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cal_sum(root->left);
    cal_sum(root->right);
    if (root->left)
        root->data += root->left->data;
    if (root->right)
        root->data += root->right->data;
}

void print_tree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print_tree(root->left);
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

    cout << "main tree : ";
    print_tree(root);
    cout << endl;
    cal_sum(root);
    cout << "sum tree : ";
    print_tree(root);
    delete root;
    return 0;
}
