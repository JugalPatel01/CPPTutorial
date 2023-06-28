/*

    * Right view of a binary tree

    i/p :
                                    1   <--
                                   / \
                                  2   3   <--
                                 / \ / \
                                4  5 6  7   <--
                                  /
                                 8   <--

    o/p :
        1,3,7,8

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

void right_view(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (q.front() == NULL && node != NULL)
        {
            cout << node->data << " ";
        }

        if (node == NULL)
        {
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
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
    root->left->right->left = new Node(8);

    /*
                                    1
                                   / \
                                  2   3
                                 / \ / \
                                4  5 6  7
                                  /
                                 8

     */

    right_view(root);
    delete root;
    return 0;
}