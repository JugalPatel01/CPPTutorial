/*
    Binary tree traversal
    -> Process of visiting each node in the tree exactly once in some order.
    * Techniques to traverse the tree
    1) Breadth-first-traversal(Level-order-traversal)
    2) depth-first-traversal
      - <root><left><right> - Preorder
      - <left><root><right> - Inorder
      - <left><right><root> - Postorder

 */

// Level Order Traversal

/*
    Time complexity = O(n)
    Space complexity = O(n) - worst & average case ,O(1) best case
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};
struct Node *rootptr;

struct Queue
{
    struct Node *ptr;
    struct Queue *next;
};
struct Queue *front = NULL, *rear = NULL;

void Enqueue(struct Node *data)
{
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->ptr = data;
    temp->next = NULL;
    if (front == NULL & rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Queue *temp;
    if (front == NULL && rear == NULL)
    {
        printf("nothing to dequeue");
        return;
    }
    else if (front == rear)
    {
        temp = front;
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = front->next;
    }
    free(temp);
}

bool IsQueueEmpty()
{
    if (front == NULL & rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *getNode(char c)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = c;
    temp->left = NULL;
    temp->right = NULL;
}

struct Node *Insert(struct Node *root, char c)
{
    if (root == NULL)
    {
        root = getNode(c);
    }
    else if (c <= root->data)
    {
        root->left = Insert(root->left, c);
    }
    else
    {
        root->right = Insert(root->right, c);
    }

    return root;
};

void LevelOrder(struct Node *root)
{
    if (root == NULL)
        return;
    Enqueue(root);
    while (!IsQueueEmpty())
    {
        struct Node *current = front->ptr;
        printf("%c ", current->data);
        if (current->left != NULL)
        {
            Enqueue(current->left);
        }
        if (current->right != NULL)
        {
            Enqueue(current->right);
        }
        Dequeue();
    }
}

void Preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}
void Postorder(struct Node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);
}

int main()
{
    rootptr = NULL;
    rootptr = Insert(rootptr, 'f');
    rootptr = Insert(rootptr, 'j');
    rootptr = Insert(rootptr, 'd');
    rootptr = Insert(rootptr, 'e');
    rootptr = Insert(rootptr, 'b');
    rootptr = Insert(rootptr, 'a');
    rootptr = Insert(rootptr, 'c');
    rootptr = Insert(rootptr, 'g');
    rootptr = Insert(rootptr, 'k');
    rootptr = Insert(rootptr, 'i');
    rootptr = Insert(rootptr, 'h');

    printf("LEVEL ORDER TRAVERSING : ");
    LevelOrder(rootptr);

    // Time complexity O(n) where n is nodes in the tree
    // Space complexity O(h) where h is height of the tree so best & average case is O(logn) and worst case is O(n)
    printf("\nPREORDER TREE TRAVERSAL : ");
    Preorder(rootptr);
    printf("\nINORDER TREE TRAVERSAL : ");
    Inorder(rootptr);
    printf("\nPOSTORDER TREE TRAVERSAL : ");
    Postorder(rootptr);

    return 0;
}