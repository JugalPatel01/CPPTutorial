// we can move in the both direction in the list in doubly linked list so we can do reverse look-up

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head; // global variable - Pointer to head Node
struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int n)
{
    struct Node *temp = GetNewNode(n);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void InsertAtTail(int n)
{
    struct Node *temp = GetNewNode(n);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->prev = temp2;
}
void Print()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    printf("forward : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    free(temp);
}
void ReversePrint()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("backward : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtTail(3);
    InsertAtTail(4);
    InsertAtHead(5);
    Print();
    ReversePrint();
    return 0;
}