/*
    Linear Data structures : array, queue, stack, Linked list, Doubly Linked list etc...

    Nonlinear Data structures : trees(hierarchical structure), graphs , etc...

    => Tree is used to represent hierarchical data.
    => Tree is collection of nodes which are linked together to simulate the hierarchy. The top most node of the tree is called the root of the tree.

    vocabulary for tree :
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

    * Important Things about trees :
    -> tree can be called recursive data structure.
    -> if tree has N nodes then there will be exactly n-1 edges(links).

    * Depth & Height of the tree :
    -> Depth of x ==> length of the path from root to x  OR no. of edges in path from root to x
        eg. : depth of root is 0.
    -> Height of x ==> No. of edges in longest path from x to a leaf
        eg. : height of leaves is 0.
    -> Height of tree = Number of edges in longest path from root to a leaf node
    -> Height of tree = Height of root node
    -> Height of the empty tree is -1 and height of tree with one node is 0.

    * If a tree in which each node can have at most 2 children then it is a binary tree.
    * If a tree in which each node can have either 2 or 0 children then it is a strict/Proper binary tree.
    * All levels except possibly the last are completely filled and all nodes are as left as possible are called complete binary tree.
    * if a tree in which each node have 2 children except the leaves nodes and all levels are perfectly filled then that tree is called perfect binary tree and no. of nodes in the perfect binary tree is (2^(height of tree + 1))-1.
    * Difference between height of left and right subtree for every node is not more than K ( mostly 1 (AVL tree)) is called balanced binary tree.
    * If a tree in which nodes can have any numbers of children called generic tree.

    * Applications of the tree :
    1) storing naturally hierarchical data => eg. : file system on disk drive
    2) Organize data for quick Search, insertion, deletion => eg. : binary search trees
    3) Trie -> eg. dictionary( for dynamic spell checking)
    4) network routing algorithms

    We can implement binary tree using :
    a) dynamically created nodes
    b) arrays
        =>  In array for node at index i,
            left-child-index = 2i+1,right-child-index = 2i+2

    * Binary serach Tree( BST ) :
    -> A binary tree in which for each node, value of all the nodes in left subtree is lesser or equal and vlaue of all the nodes in right subtree is greater.
    -> in BST all the insert, delete & searching's average time complexity is O(logn) and worst is O(n).We can avoid the worst condition by keep the tree balanced.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};
struct BstNode *rootPtr;

struct BstNode *GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BstNode *Insert(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool SearchElement(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (data == root->data)
    {
        return 1;
    }
    else if (data <= root->data)
    {
        return SearchElement(root->left, data);
    }
    else
    {
        return SearchElement(root->right, data);
    }
}

int FindMaxInTree(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Nothing is inside the tree\n");
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMaxInTree(root->right);
    }
    // while (root->right != NULL)
    // {
    //     root = root->right;
    // }
    // return root->data;
}

int FindMinInTree(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Nothing is inside the tree\n");
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int FindHeight(struct BstNode *root)
{
    if (root == NULL)
    {
        return -1; // because leaf's both children are of NULL addresses so Height of leaf node is 0.so both children return -1
    }

    int num1 = FindHeight(root->left);
    int num2 = FindHeight(root->right);

    return fmax(num1, num2) + 1;
}

int main()
{
    int num;
    rootPtr = NULL;
    rootPtr = Insert(rootPtr, 15);
    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 19);
    rootPtr = Insert(rootPtr, 12);
    rootPtr = Insert(rootPtr, 35);
    rootPtr = Insert(rootPtr, 21);
    rootPtr = Insert(rootPtr, 8);

    printf("Enter the number to serach in the tree : ");
    scanf_s("%d", &num);
    // num = 8;

    (SearchElement(rootPtr, num)) ? printf("number %d is present in the tree\n", num) : printf("number is not present in the tree\n");

    printf("Maximum element in the tree is : %d\n", FindMaxInTree(rootPtr));

    printf("Minimum element in the tree is : %d\n", FindMinInTree(rootPtr));

    printf("Height of the Tree is : %d\n", FindHeight(rootPtr));

    return 0;
}
