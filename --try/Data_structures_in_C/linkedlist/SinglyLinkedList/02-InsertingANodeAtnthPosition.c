#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void Insert(int x, int pos)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    if (pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp2 = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print()
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

int main()
{
    head = NULL;
    Insert(2, 1); // list : 2
    Insert(3, 2); // list : 2,3
    Insert(4, 1); // list : 4,2,3
    Insert(5, 2); // list : 4,5,2,3
    print();

    return 0;
}