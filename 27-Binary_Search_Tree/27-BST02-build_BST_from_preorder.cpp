/*

    * Build BST from preorder

    -> Inorder of Any BST is sorted preorder/postorder list.
    -> so using Inorder and preorder we can built a tree.

    i/p : [10, 2 , 1 , 13, 11]
    o/p : BST
*/

#include <iostream>
#include <climits>
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

Node *make_BST(vector<int> preorder, int *preorder_index, int key, int min, int max)
{
    if (*preorder_index >= preorder.size())
    {
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorder_index = *preorder_index + 1;

        if (*preorder_index < preorder.size())
        {
            root->left = make_BST(preorder, preorder_index, preorder[*preorder_index], min, key);
        }
        if (*preorder_index < preorder.size())
        {
            root->right = make_BST(preorder, preorder_index, preorder[*preorder_index], key, max);
        }
    }

    return root;
}

void print_preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main()
{
    vector<int> preorder = {10, 2, 1, 13, 11};
    cout << "enter no. of element in preorder : ";
    int n;
    cin >> n;
    cout << "fill elements in array : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    int x = 0;
    Node *root = make_BST(preorder, &x, preorder[x], INT_MIN, INT_MAX);
    print_preorder(root);
    cout << endl;
    delete root;
    return 0;
}