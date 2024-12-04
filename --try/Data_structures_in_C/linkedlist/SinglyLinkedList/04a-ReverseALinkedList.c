// Interative solution for the reverse a linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void Reverse()
{
    struct Node *current, *next, *prev;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Insert(int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    free(temp);
}
int main()
{
    head = NULL;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    Reverse();
    Print();
    return 0;
}