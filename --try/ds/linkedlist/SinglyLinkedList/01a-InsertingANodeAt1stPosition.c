// array and vectors are not good solution for dynamic memory allocation for that concept of linked list is introduced.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void insert(int x)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    // temp->next = NULL;
    // if(head!=NULL) temp->next = head;
    head = temp;
};

void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
};

int main()
{
    head = NULL; // till here our list is empty
    printf("How many numbers?\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter the number\n");
        scanf("%d", &x);
        insert(x);
        Print();
    }

    return 0;
}
