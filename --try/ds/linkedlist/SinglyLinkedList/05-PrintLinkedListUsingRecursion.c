// Print elements of a linked list in forward and reverse order using recursion
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *Insert(int n, struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        struct Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

void Print(struct Node *p)
{
    if (p == NULL) // Exit Condition
    {
        return;
    }
    printf("%d ", p->data); // print the value of the particular node
    Print(p->next);         // recursive call of function
}

void ReversePrint(struct Node *p)
{
    if (p == NULL)
        return;
    ReversePrint(p->next);
    printf("%d ", p->data);
}

int main()
{
    struct Node *head = NULL;
    head = Insert(1, head);
    head = Insert(2, head);
    head = Insert(3, head);
    head = Insert(4, head);
    head = Insert(5, head);
    printf("\nprint list in normal manner\n");
    Print(head);
    printf("\nprint list in reverse manner\n");
    ReversePrint(head);
    return 0;
}