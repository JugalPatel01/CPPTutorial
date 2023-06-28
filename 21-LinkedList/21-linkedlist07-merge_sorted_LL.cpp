/*
    merge 2 sorted linked lists

    Question : given 2 sorted linked list. our task to make single sorted linked list
    eg.
        ll 1 :  2 5 6 8
        ll 2 :  1 2 3 7

        o/p : 1 2 2 3 5 6 7 8

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

node *merged_ll_iter(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *temp = new node(-1);
    node *p3 = temp;

    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    node* merged_head = temp->next;
    delete temp;
    return merged_head;
}

node *merged_ll_recur(node *&head1, node *&head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merged_ll_recur(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merged_ll_recur(head1, head2->next);
    }

    return result;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insert_at_head(head1, 9);
    insert_at_head(head1, 7);
    insert_at_head(head1, 3);
    insert_at_head(head1, 1);
    cout << "linked list 1 : ";
    display(head1);
    insert_at_head(head2, 8);
    insert_at_head(head2, 5);
    insert_at_head(head2, 4);
    insert_at_head(head2, 1);
    cout << "linked list 2 : ";
    display(head2);

    node *merged_head = merged_ll_iter(head1, head2);
    cout << "merged  linked list : ";
    display(merged_head);
    // node* merged_head = merged_ll_recur(head1, head2);
    // cout << "merged  linked list : ";
    // display(merged_head);

    return 0;
}