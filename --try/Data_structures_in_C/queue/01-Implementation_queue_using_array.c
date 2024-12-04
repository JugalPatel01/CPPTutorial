/*
    * Queue
    -> A list or collection with the restriction that insertion can be performed at one end (rear) and deletion can be performed at other end (front)
    -> It is a FIFO structure (first in first out)

    // Operations with queue
    1) EnQueue(x)   or Push(x)
    2) DeQueue()    or Pop()
    3) front()      or Peek()
    4) IsEmpty()
    5) IsFull() // for limited sized queue

    All the above operations takes constant time means it's time complexity is O(1)

    * Use cases of the queue data structure or application of the queue data structure
    -> Printer queue
    -> process scheduling Processor of the computer
    -> simulating wait

*/

// Implementation of Queues using Circular Array
// To reduce the memory wastage we use concept of circular array.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_Size 500

int Queue[Max_Size];
int front = -1, rear = -1;

bool IsQueueIsEmpty()
{
    return (front == -1 && rear == -1);
}

void Enqueue(int x)
{
    if ((rear + 1) % Max_Size == front)
    {
        printf("Queue is Full");
        return;
    }
    else if (IsQueueIsEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % (Max_Size);
    }
    Queue[rear] = x;
}

void Dequeue()
{
    if (IsQueueIsEmpty())
    {
        printf("No elements to dequeue from the queue");
        return;
    }
    else if ((front == rear))
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % (Max_Size);
    }
}

int frontOfQueue()
{
    if (!IsQueueIsEmpty())
        return Queue[front];
}

void print()
{
    int count = (rear + Max_Size - front) % (Max_Size) + 1;
    printf("=> Queue is : ");
    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % Max_Size;
        printf("%d ", Queue[index]);
    }
    printf("\n");
}

int main()
{
    Enqueue(2);
    print();
    printf("* front is : %d \n", frontOfQueue());
    Enqueue(4);
    print();
    Enqueue(5);
    print();
    Enqueue(6);
    print();
    printf("front is : %d \n", frontOfQueue());
    Dequeue();
    print();
    Dequeue();
    print();
    printf("front is : %d \n", frontOfQueue());
    return 0;
}