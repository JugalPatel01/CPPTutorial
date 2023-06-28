/*

     * count all the nodes in a binary tree
     * sum of all the nodes in a binary tree
 */

#include <iostream>
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

int count_node(Node *root)
{
    if (root == NULL)
        return 0;
    return count_node(root->left) + count_node(root->right) + 1;
}

int sum_node(Node *root)
{
    if (root == NULL)
        return 0;
    return sum_node(root->left) + sum_node(root->right) + root->data;
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

    cout << "total no of nodes are : " << count_node(root) << endl;
    cout << "total sum of tree is : " << sum_node(root) << endl;
    delete root;
    return 0;
}