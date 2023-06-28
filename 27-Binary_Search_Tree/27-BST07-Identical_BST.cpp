/*

    * Find weather given trees are identical binary search trees or not ?
    Q : For given root nodes of 2 binary search trees, print if the BSTs are identical or not.
    -> Identical BSTs are structurally identical & have equal values for the nodes in the structre.


    i/p:
                    4                4
                   / \              / \
                  2   6            2   6
                 / \ / \          / \ / \
                1  3 5  7        1  3 5  7

    o/p : 1

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

bool check_identical(Node *root1, Node *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (root1 && root2)
    {

        if (root1->data == root2->data)
        {

            if (check_identical(root1->left, root2->left) && check_identical(root1->right, root2->right))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Node *root1 = new Node(4);
    root1->left = new Node(2);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right = new Node(6);
    root1->right->left = new Node(5);
    root1->right->right = new Node(7);

    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right = new Node(6);
    root2->right->left = new Node(5);
    root2->right->right = new Node(7);

    /*
                    4
                   / \
                  2   6
                 / \ / \
                1  3 5  7
    */
    cout << "are both trees identical ? : " << check_identical(root1, root2);
    delete root1;
    delete root2;

    return 0;
}