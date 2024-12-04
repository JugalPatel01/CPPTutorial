#include <stdio.h>
#include <stdlib.h>

// initailizing LinkedList
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

// initailizing Stack
struct Stack
{
    struct Node *pointer_of_LL;
    struct Stack *next;
};
struct Stack *top = NULL;

// Insert for the LL
void Insert(int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = head;
    head = temp;
}

// print of the linked list
void Print()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    free(temp);
    printf("\n");
}

// push function for the stack
void Push(struct Node *pointer_Location_LL)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->pointer_of_LL = pointer_Location_LL;
    temp->next = top;
    top = temp;
}

// pop function for the stack
void Pop()
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp = top;
    top = temp->next;
    free(temp);
}

// function for the reversing Linked List
void Reverse()
{
    if (head == NULL)
        return;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    
    // For push the elements in the stack
    while (temp != NULL)
    {
        Push(temp);
        temp = temp->next;
    }

    // For Pop the elements from the stack
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1 = top->pointer_of_LL;
    head = temp1;
    Pop();
    while (top != NULL)
    {
        temp1->next = top->pointer_of_LL;
        Pop();
        temp1 = temp1->next;
    }
    temp1->next = NULL;
}

int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Print();
    Reverse();
    Print();
    return 0;
}