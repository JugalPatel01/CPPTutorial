/*
    stack as a Abstract Data Structure
    -> A stack is a list with the restriction that insertion and deletion can be performed only from one end, called the top.
    -> only top of the stack is accessible
    -> It is a Last In First Out (LIFO)Collection
    -> We can push or pop item from the stack

    * Operations on the stacks
    1) Push(x)
    2) Pop()
    3) Top()
    4) IsEmpty()
    Note : All the above mentioned operations can be perfomed in constant time means time complexity is O(1).

    Applications Of Stack:
    -> Function Calls/Recursion
    -> undo/Redo operation in any text or image editor
    -> For checking Balanced Parentheses

*/

// Array Implementation of stacks

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("\nstack Overflow\n");
        return;
    }
    top++;
    A[top] = x;
    // A[++top] = x;
}
void Pop()
{
    if (top == -1)
    {
        printf("NO elemnts in the stack\n");
        return;
    }
    top--;
}
int GetTop()
{
    return A[top];
}
bool IsEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Print()
{
    printf("Stack is : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    int topelement = GetTop();
    printf("Top of the stack is : %d\n", topelement);
    bool checkstack = IsEmpty();
    printf("stack's is empty ? ->  %s\n", checkstack ? "true" : "false");

    return 0;
}