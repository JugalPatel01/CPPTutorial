// Check if a given binary tree is BST or not
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *GetNewNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *Insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (root->data >= data)
    {
        root->left = Insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

int IsSubtreeLesser(struct Node *root, int value)
{
    if (root == NULL)
        return 1;
    if ((root->data <= value) && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsSubtreeGreater(struct Node *root, int value)
{
    if (root == NULL)
        return 1;
    if (root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsBinarySearchTree(struct Node *root)
{
    if (root == NULL)
        return 1;
    if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
        return 1;
    else
        return 0;
}

void print_tree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main()
{
    struct Node *rootptr = NULL;
    rootptr = Insert(rootptr, 5);
    rootptr = Insert(rootptr, 2);
    rootptr = Insert(rootptr, 3);
    rootptr = Insert(rootptr, 7);

    print_tree(rootptr);

    if (IsBinarySearchTree(rootptr))
        printf("\nThis is binary search tree");

    free(rootptr);
    rootptr = NULL;
    return 0;
}