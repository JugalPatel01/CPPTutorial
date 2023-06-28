/*
    * Build tree from postorder and inorder
    i/p : postorder [2 4 5 3 6 7 1 ]         inorder [2 4 5 1 3 6 7 ]
    o/p : tree
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

int search(int curr, vector<int> inorder, int instart, int inend)
{
    for (int i = instart; i <= inend; i++)
    {
        if (curr == inorder[i])
            return i;
    }
    return -1;
}

Node *build_tree(vector<int> postorder, vector<int> inorder, int instart, int inend)
{
    if (instart > inend)
    {
        return NULL;
    }
    static int index = postorder.size() - 1;
    int curr = postorder[index];
    Node *node = new Node(curr);
    index--;
    if (instart == inend)
    {
        return node;
    }

    int pos = search(curr, inorder, instart, inend);

    node->right = build_tree(postorder, inorder, pos + 1, inend);
    node->left = build_tree(postorder, inorder, instart, pos - 1);
    return node;
}

void print_inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

int main()
{
    int n;
    cout << "enter size of the array : ";
    cin >> n;
    vector<int> postorder(n), inorder(n);
    cout << "insert postorder elements : ";
    for (auto &i : postorder)
    {
        cin >> i;
    }
    cout << "insert inorder elements : ";
    for (auto &i : inorder)
    {
        cin >> i;
    }

    Node *root = build_tree(postorder, inorder, 0, n - 1);

    print_inorder(root);

    return 0;
}