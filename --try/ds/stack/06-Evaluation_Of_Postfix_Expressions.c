/*
    Infix, Postfix, Prefix

    Infix : <operand><operator><operand> eg. : 4+6 , a-b , (x*6) , (2+6)*9 , (a+b)*(c+d)
    ==> It is human-Readable

    -> order of operation
    1) Parentheses (),{}    => left to right
    2) Exponenets ^  => right to left
    3) Multiplication and Division  => left to right
    4) Addition and Subtraction => left to right


    -> Prefix(polish notation) : <operator><operand><operand> eg. : +4 6,-a b,*x 6,*9+2 6
    -> Postfix(reverse polish notation) : <operand><operand><operator> eg. : 46+,a b-,x6*
    ==> These are good for machines

    Infix to postfix
        {(a*b)+(c*d)}-e
    ->  {(ab*)+(cd*)}-e
    ->  {(ab*)(cd*)+}-e
    ->  {(ab*)(cd*)}e-
    ->  ab*cd*e-

    Postfix calculation
    // scan from left to right
       2 3 * 5 4 * + 9 -
    -> 6 5 4 * + 9 -
    -> 6 20 + 9 -
    -> 26 9 -
    -> 17

    Infix to prefix
       {(2*3)+(5*4)}-9
    -> {(*23)+(*54)}-9
    -> {+(*23)(*54)}-9
    -> -{+(*23)(*54)}9
    -> -+*23*549

    Prefix calculation
    //scan from right to left
       - + * 2 3 * 5 4 9
    -> - + * 2 3 20 9
    -> - + 6 20 9
    -> - 26 9
    -> 17


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
    int data;
    struct Stack *next;
};
struct Stack *top = NULL;

void Push(int c)
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

bool IsNumericDigit(char exp)
{
    if (exp >= '0' && exp <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EvaluatePostfix(char exp[1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if (exp[i] == '*' || exp[i] == '+' || exp[i] == '/' || exp[i] == '-' || exp[i] == '^')
        {

            int a, b, result;
            b = top->data;
            Pop();
            a = top->data;
            Pop();
            if (exp[i] == '+')
            {
                result = a + b;
            }
            else if (exp[i] == '-')
            {
                result = a - b;
            }
            else if (exp[i] == '*')
            {
                result = a * b;
            }
            else if (exp[i] == '/')
            {
                result = a / b;
            }
            else if (exp[i] == '^')
            {
                result = a ^ b;
            }
            else
            {
                printf("\ninvalid Expression\n");
                return -1;
            }
            Push(result);
        }
        else if (IsNumericDigit(exp[i]))
        {
            int operand = 0;
            while (i < n && IsNumericDigit(exp[i]))
            {
                operand = (operand * 10) + (exp[i] - '0');
                i++;
            }
            i--;
            Push(operand);
        }
    }
    return top->data;
}

int main()
{
    printf("enter the expression : ");
    char exp[1000];
    gets(exp);
    int n = strlen(exp);
    int result;
    result = EvaluatePostfix(exp, n);
    printf("%d", result);
    return 0;
}