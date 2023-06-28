/*
    Q : Build a tree from preorder and postorder traversal .
    i/p : preorder [ 1,2,4,3,5]     inorder [4,2,1,5,3]
    o/p : tree


 */
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
        if (inorder[i] == curr)
        {
            return i;
        }
    }

    return -1;
}

Node *build_tree(vector<int> preorder, vector<int> inorder, int instart, int inend)
{
    static int index = 0;
    if (instart > inend)
    {
        return NULL;
    }

    int curr = preorder[index];
    Node *node = new Node(curr);
    index++;

    if (instart == inend)
    {
        return node;
    }
    int pos = search(curr, inorder, instart, inend);

    node->left = build_tree(preorder, inorder, instart, pos - 1);
    node->right = build_tree(preorder, inorder, pos + 1, inend);

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
    vector<int> preorder(n), inorder(n);
    cout << "insert preorder elements : ";
    for (auto &i : preorder)
    {
        cin >> i;
    }
    cout << "insert inorder elements : ";
    for (auto &i : inorder)
    {
        cin >> i;
    }

    Node *root = build_tree(preorder, inorder, 0, n - 1);

    print_inorder(root);

    return 0;
}