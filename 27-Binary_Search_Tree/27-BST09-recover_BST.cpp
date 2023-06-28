/*

    * Restore BST
     Q : 2 nodes of a BST are swapped. Our task is to restore

     eg. inorder traversal of BST is {1, 2, 7, 4, 5, 6, 3}
     so here 7 and 3  are swapped

     sol : {1, 2, 3, 4, 5, 6, 7}    correct BST
*/
#include <iostream>
#include <deque>
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

void check_inorder(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }
    check_inorder(root->left, first, mid, last, prev);
    if (*prev && (*prev)->data > root->data)
    {
        if (*first)
        {
            *last = root;
        }
        else
        {
            *first = *prev;
            *mid = root;
        }
    }
    *prev = root;
    check_inorder(root->right, first, mid, last, prev);
}

void swap_nodes(Node **first, Node **second)
{
    int temp = (*first)->data;
    (*first)->data = (*second)->data;
    (*second)->data = temp;
}

void restore_BST(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
    check_inorder(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        cout << first->data << " " << last->data << endl;
        swap_nodes(&first, &last);
    }
    else if (first && mid)
    {
        cout << first->data << " " << mid->data << endl;
        swap_nodes(&first, &mid);
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
    Node *root = new Node(4);
    root->left = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    /*
                    4
                   / \
                  2   6
                 / \ / \
                1  3 5  7
    */

    print_tree(root);
    cout << endl;

    restore_BST(root);

    print_tree(root);
    cout << endl;
    delete root;
    return 0;
}