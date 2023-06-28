/*
    * binary trees
    -> it is used for storing hierarchical data.
    -> it consists a node which contains data and address of left and right children(because binary tree can have atmost two children).
    -> topmost node is called root node.
    -> last node in hierarchy is called leaf node. leaf node doesn't have any child.


     level 0                   1   --------------------> root node     2^0 = max 1 node
                              / \
     level 1                 2   3                                     2^1 = max 2 nodes
                            / \ / \
     level 2               4  5 6  7  --------------------> leaves     2^2 = max 4 nodes

                    Total Node = 2^(height_of_tree) - 1 = 2^3 - 1 = 8-1 = 7
                    height of tree = total no. of levels

    * vocabulary for tree :
    -> Nodes
    -> root
    -> link
    -> parent
    -> children
    -> sibling ==> have same parent
    -> cousin ==> on same level but not having same parent
    -> leaf ==> has no child
    -> subtrees
    -> Ancestor ==> if we go from A to B then A is ancestor of B
    -> Descendent ==> if we go from A to B then B is descendent of A


    * Properties of binary trees :
    -> Maximum nodes at level L = 2^L
    -> Maximum nodes in a tree of height H is ((2^H) - 1)
    -> For N nodes, minimum possible height or minimum number of levels are log(N+1)
    -> A binary tree with L leaves has atleast log(N+1)+1 number of levels

    We can implement binary tree using :
    a) dynamically created nodes
    b) arrays
        =>  In array for node at index i,
            left-child-index = 2i+1,right-child-index = 2i+2

    * traversal in tree
    -> pre_order  => root left right
    -> in_order   => left root right
    -> post_order => left right root


*/
#include <iostream>
using namespace std;

/*
    * difference between class and structure in cpp.
    -> members and base classes are private by default in classes, whereas they are public by default in structs.
    -> When a structure is implemented, memory allocates on a stack. In contrast, memory is allocated on the heap in class.

*/
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

void pre_order(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    pre_order(root->left);
    cout << root->data << " ";
    pre_order(root->right);
}

void post_order(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    pre_order(root->left);
    pre_order(root->right);
    cout << root->data << " ";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "pre order traversal : ";
    pre_order(root);
    cout << endl;

    cout << "in order traversal : ";
    in_order(root);
    cout << endl;

    cout << "post order traversal : ";
    post_order(root);
    cout << endl;

    delete root;

    return 0;
}
