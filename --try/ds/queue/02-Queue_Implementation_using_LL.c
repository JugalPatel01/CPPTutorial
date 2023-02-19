// Queue implementation using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int data;
    struct Queue *next;
};
struct Queue *front = NULL, *rear = NULL;

void Enqueue(int x)
{
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
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
    if (front == NULL)
    {
        printf("queue is empty can't dequeue :((\n");
        return;
    }
    if (front == rear)
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

void FrontOfQueue()
{
    if (front == NULL)
    {
        printf("Queue is empty so front is NULL :>>\n");
        return;
    }
    printf("* front of the queue is : %d \n", front->data);
}

void Print()
{
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp = front;
    printf("=> Queue is : ");
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
    FrontOfQueue();
    Enqueue(2);
    Print();
    FrontOfQueue();
    Enqueue(3);
    Print();
    Enqueue(4);
    Print();
    FrontOfQueue();
    Enqueue(5);
    Print();
    Dequeue();
    Print();
    FrontOfQueue();
    Dequeue();
    Print();
    FrontOfQueue();
    return 0;
}