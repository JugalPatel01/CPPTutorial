/*

    * Balanced Height Tree
    -> For each node, the difference between the height of the left subtree & right subtree <= 1
*/

#include <iostream>
#include <math.h>
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

int check_height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(check_height(root->left), check_height(root->right)) + 1;
}

bool check_balance(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (!check_balance(root->left) || !check_balance(root->right))
    {
        return false;
    }

    int check = abs(check_height(root->left) - check_height(root->right));
    if (check <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_balanced_optimized(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int left_height = 0, right_height = 0;
    if (!check_balanced_optimized(root->left, &left_height) || !check_balanced_optimized(root->right, &right_height))
    {
        return false;
    }
    *height = max(left_height, right_height) + 1;

    int check = abs(left_height - right_height);
    if (check <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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
                                4  5 6  7


    after commenting root->right, root->right->left, root->right->right.
                                    1
                                   /
                                  2
                                 / \
                                4  5

     */

    cout << "is binary tree is balanced using bruteforce (O(N^2)) ? : " << check_balance(root) << endl;
    int height = 0;
    cout << "is binary tree is balanced using optimized algo (O(N)) ? : " << check_balanced_optimized(root, &height) << endl;

    delete root;
    return 0;
}