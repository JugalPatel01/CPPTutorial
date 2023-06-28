/*
    revese the linked list

    there are two methods for changing the direction of the list
    1) iterative method 2) recursive method

    1) in interative method take just three pointers next,current and privious to traverse the list and changing the direction
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
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

// reverse list using iterative method
node *reverse_iterate_ll(node *&head)
{
    node *prv = NULL;
    node *cur = head;
    node *next;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prv;
        prv = cur;
        cur = next;
    }
    head = prv;
    return head;
}

// reverse list using recursive method
node *reverse_recursive_ll(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverse_recursive_ll(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    delete temp;
}

int main()
{
    node *head = NULL;
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_head(head, 4);
    insert_at_head(head, 5);

    cout << "normal order ";
    display(head);
    head = reverse_iterate_ll(head);
    cout << "reverse order using iterative method ";
    display(head);
    head = reverse_recursive_ll(head);
    cout << "reverse order using recursive method ";
    display(head);

    return 0;
}