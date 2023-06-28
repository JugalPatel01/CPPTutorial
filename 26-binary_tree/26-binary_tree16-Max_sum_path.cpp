/*

    * Maximum path sum
    Q: Maximum possible sum of a path in the binayr tree, starting & ending at any node

                        1
                       / \
                      2   3
                     / \ / \
                     4 5 6 7

*/

#include <iostream>
#include <math.h>
#include <climits>
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

int find_max_sum(Node *root, int &sum)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_subtree_value = find_max_sum(root->left, sum);
    int right_subtree_value = find_max_sum(root->right, sum);

    int path_max = max(max(root->data, root->data + left_subtree_value + right_subtree_value),
                       max(root->data + left_subtree_value, root->data + right_subtree_value));

    sum = max(path_max, sum);
    int single_path_sum = max(root->data, max(root->data + left_subtree_value, root->data + right_subtree_value));
    return single_path_sum;
}

int cal_sum(Node *root)
{
    int ans = INT_MIN;
    find_max_sum(root, ans);

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->left->left = new Node(-3);
    root->left->right = new Node(4);
    root->right = new Node(-5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
                            1
                           /  \
                         -2    5
                         / \  / \
                       -3  4 -6 -7

     */
    cout << cal_sum(root);
    delete root;
    return 0;
}
