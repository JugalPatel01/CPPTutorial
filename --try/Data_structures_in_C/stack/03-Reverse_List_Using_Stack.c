// We can use Stack to use reverse the string
// Reversing the string using stack takes O(n) time complexity and O(n) Space Complexity
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char data;
    struct Stack *next;
};
struct Stack *top = NULL;

void Push(char n)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
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
    struct Stack *temp = top;
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
    printf("top of stack is %c\n", top->data);
}

void Print()
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp = top;
    printf("stack is : ");
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse(char C[], int n)
{
    // Loop for push
    for (int i = 0; i < n; i++)
    {
        Push(C[i]);
    }
    printf("\n");
    TopOfStack();
    printf("\n");
    Print();
    printf("\n");

    // Loop for pop
    for (int i = 0; i < n; i++)
    {
        C[i] = top->data;
        Pop();
    }
    printf("\n");
    TopOfStack();
    printf("\n");
}
int main()
{
    char C[51];
    printf("Enter a string : ");
    gets(C);
    Reverse(C, strlen(C));
    puts("reverse of the string is : ");
    puts(C);
    return 0;
}