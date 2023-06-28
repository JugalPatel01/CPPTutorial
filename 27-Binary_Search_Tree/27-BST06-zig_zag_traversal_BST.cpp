/*

    * zig zag traversal in binary search tree

    i/p :
            4                   traverse left->right
           / \
          2   6                 traverse right->left
         / \ / \
        1  3 5  7               traverse right->right

    o/p :   4
            6 2
            1 3 5 7

    approaches:
    1) we can use deque and direction variable
    2) we can use two stacks and direction variable

 */

#include <iostream>
#include <stack>
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

void zig_zag_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> curr, next;
    int dir = 0;
    curr.push(root);
    while (!curr.empty())
    {
        Node *temp_node = curr.top();
        curr.pop();
        if (temp_node)
        {
            cout << temp_node->data << " ";

            if (dir == 0)
            {
                if (temp_node->left)
                    next.push(temp_node->left);
                if (temp_node->right)
                    next.push(temp_node->right);
            }
            else if (dir == 1)
            {
                if (temp_node->right)
                    next.push(temp_node->right);
                if (temp_node->left)
                    next.push(temp_node->left);
            }
        }
        if (curr.empty())
        {
            next.swap(curr);
            (dir == 1) ? dir = 0 : dir = 1;
        }
    }
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

    zig_zag_traversal(root);
    delete root;

    return 0;
}