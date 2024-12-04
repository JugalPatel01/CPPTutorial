#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void Insert(int n) // insert an integer at end of list
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = n;
    temp1->next = head;
    head = temp1;
    return;
}
void Delete(int n) // delete node at position n
{

    struct Node *temp = head;
    if (n == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
        // temp1 points to (n-1)th node
    }
    struct Node *temp2 = temp->next;

    temp->next = temp2->next;
    free(temp2);
}
void Print() // print all elements in the list
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
int main()
{
    head = NULL;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Print();
    int n;
    printf("enter the position for deleting the node ");
    scanf("%d ", &n);
    Delete(n);
    Print();
    return 0;
}