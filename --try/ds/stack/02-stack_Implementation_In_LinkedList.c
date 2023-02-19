// To avoiding the stack overflow condition we implement stack with the use of the linked list.
/*
    There are two posibility to make stack with the linked list.
    1> Insert/Delete element at the end of the list(tail)
    2> Insert/Delete element at the beginning of the list(head)

    -> In the first option the time complexity for inserting and deleting the node is O(n) because for that we need to traverse whole list
    -> So The second option insert/Delete at the beginning of the list is the good option because it's time complexity is O(1) for inserting and deleting the element.
*/
#include <stdio.h>
#include <stdlib.h>
struct List
{
    int data;
    struct List *next;
};
struct List *top = NULL;
void Push(int n)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = n;
    temp->next = top;
    top = temp;
}

void Pop()
{
    if (top == NULL)
    {
        printf("No elements to pop\n");
        return;
    }
    struct List *temp = top;
    top = temp->next;
    free(temp);
}

void TopOfStack()
{
    if (top == NULL)
    {
        printf("stack is empty and top is NULL\n");
        return;
    }
    printf("top of stack is %d\n", top->data);
}

void IsEmpty()
{
    printf("%s", (top == NULL) ? "List is empty\n " : "list in not empty.\n");
}

void Print()
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp = top;
    printf("stack is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Push(2);
    Print();
    Push(3);
    Print();
    Push(4);
    Print();
    Push(5);
    Print();
    TopOfStack();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    IsEmpty();
    return 0;
}