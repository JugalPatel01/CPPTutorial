/*

    * Print all nodes at distance K from any given node.
    i/p : tree,target_node,distance
    o/p : nodes

*/
#include <iostream>
#include <vector>
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

void print_subtree_elements(Node *root, int k)
{
    vector<int> ans(5, 0);
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    print_subtree_elements(root->left, k - 1);
    print_subtree_elements(root->right, k - 1);
}

int print_nodes_at_k(Node *root, Node *target_node, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target_node)
    {
        print_subtree_elements(root, k);
        return 0;
    }

    int left_dis = print_nodes_at_k(root->left, target_node, k);
    if (left_dis != -1)
    {
        if (left_dis + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_subtree_elements(root->right, k - left_dis - 2);
        }
        return 1 + left_dis;
    }

    int right_dis = print_nodes_at_k(root->right, target_node, k);
    if (right_dis != -1)
    {
        if (right_dis + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_subtree_elements(root->left, k - right_dis - 2);
        }
        return 1 + right_dis;
    }

    return -1;
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

    int k;
    cout << "Enter distance : ";
    cin >> k;
    // k = 3;
    print_nodes_at_k(root, root->left->left, k);
    delete root;
    return 0;
}