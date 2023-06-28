/*

    * find distance between 2 nodes of a binary tree
    -> The distance between two nodes is the minimum number of edges to be traversed to reach one node from another.
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

Node *least_common_ancestor(Node *root, int x, int y)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x || root->data == y)
    {
        return root;
    }
    Node *left = least_common_ancestor(root->left, x, y);
    Node *right = least_common_ancestor(root->right, x, y);

    if (left && right)
    {
        return root;
    }
    if (left == NULL)
    {
        return right;
    }
    return left;
}

bool check_present(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (check_present(root->left, x) || check_present(root->right, x))
    {
        return true;
    }
    return false;
}

int total_distance(Node *root, int x, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == x)
    {
        return dist;
    }
    int left = total_distance(root->left, x, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return total_distance(root->right, x, dist + 1);
}

int find_distance(Node *root, int x, int y)
{
    if (!check_present(root, x) || !check_present(root, y))
    {
        return -1;
    }
    Node *common_anc = least_common_ancestor(root, x, y);

    int dist1 = total_distance(common_anc, x, 0);
    int dist2 = total_distance(common_anc, y, 0);

    return dist1 + dist2;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(4);

    /*
                        1
                       / \
                      2   5
                     /   / \
                    3   6   7
                       /
                      4
     */
    int x, y;
    cout << "enter value of x & y respectivly : ";
    // cin >> x >> y;
    x = 3,y =7;
    cout << "distance is : " << find_distance(root, x, y) << endl;

    delete root;
    return 0;
}