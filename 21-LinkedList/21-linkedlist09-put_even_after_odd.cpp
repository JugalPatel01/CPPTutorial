/*
    Put even position's elements after odd position's elements in linked list

    Q.  : 1 2 3 4 5 6
    o/p : 1 3 5 2 4 6
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

void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void rearrange(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *oddptr = head;
    node *evenptr = head->next;
    node *evenptrstart = head->next;
    while (oddptr->next && evenptr->next)
    {
        oddptr->next = oddptr->next->next;
        oddptr = oddptr->next;
        evenptr->next = evenptr->next->next;
        evenptr = evenptr->next;
    }
    oddptr->next = evenptrstart;
    return;
}

void display(node *head)
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
    node *head = NULL;
    insert_at_head(head, 6);
    insert_at_head(head, 5);
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    display(head);
    rearrange(head);
    display(head);
    return 0;
}