/*

    * what is height of binary tree?
    -> It is the depth of the tree's deepest node

    * what is diameter of tree?
    -> Number of nodes in the longest path between any 2 leaves
*/

#include <iostream>
#include <math.h>
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

int height_of_tree(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
}

int diameter_of_tree(Node *root)
{
    int dia = 0;
    if (root == NULL)
        return 0;

    int curr_dia = height_of_tree(root->left) + height_of_tree(root->right) + 1;

    int recur_dia = max(diameter_of_tree(root->left), diameter_of_tree(root->right));

    dia = max(recur_dia, curr_dia);

    return dia;
}

int diameter_of_tree_reduced(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int left_subtree_height = 0, right_subtree_height = 0;

    int left_subtree_dia = diameter_of_tree_reduced(root->left, &left_subtree_height);
    int right_subtree_dia = diameter_of_tree_reduced(root->right, &right_subtree_height);

    // calculate height of tree
    *height = max(left_subtree_height, right_subtree_height) + 1;

    int curr_diameter = left_subtree_height + right_subtree_height + 1;

    return max(curr_diameter, max(left_subtree_dia, right_subtree_dia));
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
    // root->right->left->left = new Node(8);
    // root->right->left->left->left = new Node(9);
    // root->right->right->right = new Node(10);

    /*
                        1
                       / \
                      2   3                         height = 3 & diameter = 5
                     / \ / \
                     4 5 6 7

                        1
                         \
                          3
                         / \
                        6   7                       height = 5 & diameter = 6
                       /     \
                      8      10
                     /
                    9

    */

    cout << "height of tree is " << height_of_tree(root) << endl;
    cout << "diameter of tree is " << diameter_of_tree(root) << endl;
    int height = 0;
    cout << "diameter of tree with reduced time complex function is " << diameter_of_tree_reduced(root, &height) << endl;
    delete root;
    return 0;
}