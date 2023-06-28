/*

    * Right view of a binary tree

    i/p :
                         -->        1
                                   / \
                       -->        2   3
                                 / \ / \
                     -->        4  5 6  7
                                  /
                      -->        8

    o/p :
        1,2,4,8

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

void left_view(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    // it's another way of implementing left & right view of tree
    while (!q.empty())
    {
        int x = q.size();
        for (int i = 0; i < x; i++)
        {
            Node *node = q.front();
            q.pop();
            /*
                here two ways are possible first one is like shown here and another one is
                if(i == 1) cout<<node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

             */
            if (i == x - 1)
            {
                cout << node->data << " ";
            }
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
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

    left_view(root);
    delete root;
    return 0;
}