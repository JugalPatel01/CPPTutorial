/*
    Problem : Given an expression in the form of string contains constant, variable, operator and parentheses
    eg. => balanced :(a+b) , {(a+b)+(c+d)},[()]
        => unbalanced : {a+b) , [2+3]+(a)] , )( , [(])

    Solution : -> scan from left to right
               -> if opening symbol, add it to a list
               -> if closing symbol, remove last opening symbol in list
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char data;
    struct Stack *next;
};
struct Stack *top = NULL;

void Push(char c)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = c;
    temp->next = top;
    top = temp;
}
void Pop()
{
    if (top == NULL)
    {
        printf("No element in the stack");
        return;
    }
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp = top;
    top = temp->next;
    free(temp);
}

void CheckBalancedParenthesis(char string1[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (string1[i] == '(' || string1[i] == '{' || string1[i] == '[')
        {
            Push(string1[i]);
        }
        else if (string1[i] == ')' || string1[i] == '}' || string1[i] == ']')
        {
            if (top == NULL)
            {
                printf("This expression has not balanced Parentheses");
                return;
            }

            if ((string1[i] == ')' && top->data == '(') || (string1[i] == '}' && top->data == '{') || (string1[i] == ']' && top->data == '['))
            {
                Pop();
            }
            else
            {
                printf("This expression has not balanced Parentheses");
                return;
            }
        }
    }
    printf("This Expression has Balanced Parentheses :D ");
}

int main()
{
    char string1[100];
    printf("Enter the string for checking whether it's parentheses are balanced or not :\n");
    gets(string1);
    int n = strlen(string1);
    CheckBalancedParenthesis(string1, n);
    return 0;
}