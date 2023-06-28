/*

    * Check for BST optimized version
*/
#include <iostream>
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

bool check_for_BST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        if (check_for_BST(root->left, min, root->data) && check_for_BST(root->right, root->data, max))
        {
            return true;
        }
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

    cout << "is give tree BST? " << check_for_BST(root, INT_MIN, INT_MAX);
    delete root;
    return 0;
}