/*

    * Sorted array to balanced BST

    i/p : [2,3,4]
    o/p :

            3
           / \
          2   4


*/

#include <iostream>
#include <vector>
#include <algorithm>
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

Node *convert_to_bst(vector<int> arr, int start, int end)
{
    if (end < start)
    {
        return NULL;
    }
    int mid = (start + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = convert_to_bst(arr, start, mid - 1);
    root->right = convert_to_bst(arr, mid + 1, end);

    return root;
}

void print_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main()
{

    cout << "enter no. of elements in array : ";
    int n;
    cin >> n;
    vector<int> s_arr;
    cout << "enter elements of an array : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s_arr.push_back(x);
    }

    sort(s_arr.begin(), s_arr.end());

    Node *root = convert_to_bst(s_arr, 0, n - 1);

    print_tree(root);

    delete root;
    return 0;
}