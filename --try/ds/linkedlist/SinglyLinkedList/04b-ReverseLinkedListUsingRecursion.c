// Reverse A linked list using the recursion

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
    {
        head = temp;
    }
    else
    {
        struct Node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    return head;
}

void Print(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    free(temp);
}
struct Node *ReverseLL(struct Node *p)
{
    struct Node *head;
    if (p->next == NULL)
    {
        head = p;
        return head;
    }
    head = ReverseLL(p->next);
    // struct Node *q = p->next;
    // q->next = p;
    p->next->next = p;
    p->next = NULL;
    return head;
}
int main()
{
    struct Node *head = NULL;
    head = Insert(1, head);
    head = Insert(2, head);
    head = Insert(3, head);
    head = Insert(4, head);
    Print(head);
    struct Node *temp = head;
    head = ReverseLL(temp);
    Print(head);

    return 0;
}