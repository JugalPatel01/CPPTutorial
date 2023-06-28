/*
    stack implementation using singly linked list
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *head = NULL;
int stack_size = 0;

void push(int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
    stack_size = stack_size + 1;
}

void pop()
{
    if (head == NULL)
    {
        // stack underflow condition
        cout << "nothing to pop out because stack is empty." << endl;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    stack_size = stack_size - 1;
    return;
}

int top()
{
    if (head == NULL)
    {
        cout << "stack is empty " << endl;
        return -1;
    }
    return head->data;
}

int size()
{
    return stack_size;
}

bool empty()
{
    if (stack_size == 0)
        return true;
    return false;
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);

    cout << "top of the stack is : " << top() << endl;
    
    cout << "is stack empty ? : " << empty() << endl;

    cout << "size of the stack is : " << size() << endl;

    pop();

    cout << "top of the stack is : " << top() << endl;

    pop();
    pop();
    pop();

    cout << "is stack empty ? : " << empty() << endl;
    return 0;
}