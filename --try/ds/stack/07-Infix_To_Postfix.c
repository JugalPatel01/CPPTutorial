// Infix expression to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool IsOperand(char c)
{
    if (c >= '0' || c <= '9')
        return 1;
    if (c >= 'a' || c <= 'z')
        return 1;
    if (c >= 'A' || c <= 'Z')
        return 1;
    return 0;
}

bool IsOperator(char c)
{
    if (c == '*' || c == '/' || c == '-' || c == '+' || c == '^')
        return 1;
    return 0;
}

int IsRightAssociative(char op)
{
    if (op == '^')
        return 1;
    return 0;
}

int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    case '^':
        weight = 3;
        break;
    }
    return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
    int op1weight = GetOperatorWeight(op1);
    int op2weight = GetOperatorWeight(op2);

    if (op1weight == op2weight)
    {
        if (IsRightAssociative(op1))
            return 0;
        else
            return 1;
    }

    return op1weight > op2weight ? 1 : 0;
}

char *InfixToPostfix(char exp[], int n)
{
    char *Postfix = (char *)malloc(1000 * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
        {
            Postfix[j] = exp[i];
            j++;
            continue;
        }

        else if (IsOperator(exp[i]))
        {
            while (top != NULL && top->data != '(' && HasHigherPrecedence(top->data, exp[i]))
            {
                Postfix[j] = top->data;
                j++;
                Pop();
            }
            Push(exp[i]);
        }

        else if (IsOperand(exp[i]))
        {
            Postfix[j] = exp[i];
            j++;
        }

        else if (exp[i] == '(')
        {
            Push(exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (top != NULL && top->data != '(')
            {
                Postfix[j] = top->data;
                j++;
                Pop();
            }
            Pop();
        }
    }

    while (top != NULL)
    {
        Postfix[j] = top->data;
        j++;
        Pop();
    }

    return Postfix;
}
int main()
{
    printf("enter the expression : ");
    char Infixexp[1000];
    gets(Infixexp);
    char *Postfixexp;
    Postfixexp = InfixToPostfix(Infixexp, strlen(Infixexp));
    puts(Postfixexp);
    return 0;
}