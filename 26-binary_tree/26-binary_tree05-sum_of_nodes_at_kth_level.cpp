/*
     Find the sum of nodes at kth level
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

int find_sum_on_kth_level(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int ans = 0;
    int level = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
                ans += node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (node == NULL && !q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return ans;
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

    int k;
    cout << "enter value of level between 0 to 2 : ";
    cin >> k;

    /*
                        1
                       / \
                      2   3
                     / \ / \
                     4 5 6 7
    */

    cout << "sum at kth level " << find_sum_on_kth_level(root, k);
    delete root;
    return 0;
}