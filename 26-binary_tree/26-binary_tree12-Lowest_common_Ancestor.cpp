/*

    * Lowest common Ancestor for two nodes

                        1
                       / \
                      2   3
                     /   / \
                    4   5   6
                       /
                      7
    i/p :   4 & 6
    o/p :   1

    i/p :   7 & 6
    o/p :   3
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

bool find_route(Node *root, int val, vector<int> &path)
{
    // here we will find path using backtracking
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);

    if (root->data == val)
    {
        return true;
    }

    if (find_route(root->left, val, path) || find_route(root->right, val, path))
    {
        return true;
    }

    path.pop_back();

    return false;
}

int common_ance(Node *root, int x, int y)
{
    vector<int> x_path, y_path;
    if (find_route(root, x, x_path) && find_route(root, y, y_path))
    {
        int pc;
        for (pc = 0; (pc < x_path.size()) && (pc < y_path.size()); pc++)
        {
            if (x_path[pc] != y_path[pc])
            {
                break;
            }
        }
        return x_path[pc - 1];
    }
    else
    {
        return -1;
    }
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

Node *common_ance_reduced(Node *root, int x, int y)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x || root->data == y)
    {
        return root;
    }

    Node *left = common_ance_reduced(root->left, x, y);
    Node *right = common_ance_reduced(root->right, x, y);

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
    cin >> x >> y;
    // x = 3,y =7;
    cout << "lowest common ancestor of " << x << " and " << y << " is (if -1 then they havn't lca) : " << common_ance(root, x, y) << endl;

    Node *LCA = common_ance_reduced(root, x, y);
    if (LCA == NULL)
    {
        cout << "LCA not present." << endl;
    }
    else if (check_present(root, x) && check_present(root, y))
    {
        cout << "lowest common ancestor of " << x << " and " << y << " using reduced method is : " << LCA->data << endl;
    }
    else
    {
        cout << "LCA not present." << endl;
    }
    delete root;
    return 0;
}