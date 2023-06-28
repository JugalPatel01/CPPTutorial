/*

    * Binary Search Tree

    -> BST are used for retrieving/searching node data in reduced time (O(logn)) then normal binary tree(O(n)). but in worst case for skew binary tree it's O(n).
    -> self balancing BST call AVL tree.

    rules for making normal binary trees to binary search trees
    1) the left subtree of a node contains only nodes with keys lesser than the node's key.
    2) the right subtree of a node contains only nodes with keys higher than the node's key.
    3) the left and right subtree each must also be a binary search tree. there must be no duplicate nodes.

    eg.
                            4
                           / \
                          2    6
                         / \  / \
                        1   3 5  7



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

Node *add_into_BST(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = add_into_BST(root->left, val);
    }
    else
    {
        root->right = add_into_BST(root->right, val);
    }
    return root;
}

bool search_ele(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (key == root->data)
    {
        return true;
    }
    else if (key < root->data)
    {
        return search_ele(root->left, key);
    }
    else
    {
        return search_ele(root->right, key);
    }
}

Node *inorder_successor(Node *root)
{
    Node *temp = root;

    while (temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *delete_ele(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete_ele(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete_ele(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = inorder_successor(root->right);
            root->data = temp->data;
            root->right = delete_ele(root->right, temp->data);
        }
    }
    return root;
}

void inorder_tree_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_tree_traversal(root->left);
    cout << root->data << " ";
    inorder_tree_traversal(root->right);
}

int main()
{
    Node *root = NULL;
    root = add_into_BST(root, 4);
    root = add_into_BST(root, 6);
    root = add_into_BST(root, 2);
    root = add_into_BST(root, 3);
    root = add_into_BST(root, 1);
    root = add_into_BST(root, 5);
    root = add_into_BST(root, 7);

    /*
                            4
                           / \
                          2    6
                         / \  / \
                        1   3 5  7
     */

    /*
        int n;
        cout << "enter total no. of elements : ";
        cin >> n;
        cout << "enter elements : ";
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = add_into_BST(root, x);
        }
    */
    cout << "inorder of binary search tree is always sorted so here we check it : " << endl;
    inorder_tree_traversal(root);
    cout << endl;

    int x;
    // cout << "enter element for searching : ";
    // cin >> x;
    x = 5;
    cout << "is " << x << " present in binary search tree ? " << search_ele(root, x) << endl;

    // cout << "enter element for delete : ";
    // cin >> x;
    x = 6;
    root = delete_ele(root, x);

    cout << "after deleting " << x << " list is : ";
    inorder_tree_traversal(root);
    cout << endl;

    delete root;
    return 0;
}