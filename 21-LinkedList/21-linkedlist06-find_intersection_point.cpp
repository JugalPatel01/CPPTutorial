/*
    find intersection point of 2 linked lists
    1-> 2-> 3
              \
                7-> 8-> 9
              /
    4-> 5-> 6

    so here we have to find intersection point 7.

    steps & logic:
    -> here we know that both are linked list are intersecting to each other so both share some nodes
    -> so we find the difference between them and move difference steps forword in longer linked list
    -> now if we traverse both linked list then when then both intersect each other they point to the same node
    -> so we will return that node's data from the function.

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

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    node *temp2 = head2;
    while (--pos)
    {
        temp1 = temp1->next;
    }
    while (temp2->next)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int intersection(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int diff = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        diff = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        diff = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (diff)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        diff--;
    }

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    insert_at_head(head1, 1);
    insert_at_head(head1, 2);
    insert_at_head(head1, 3);
    insert_at_head(head1, 5);
    cout << "linkedlist 1 ";
    display(head1);
    insert_at_head(head2, 4);
    insert_at_head(head2, 5);
    insert_at_head(head2, 6);
    cout << "linkedlist 2 ";
    display(head2);
    intersect(head1, head2, 3);
    cout << "linkedlist 1 ";
    display(head1);
    cout << "linkedlist 2 ";
    display(head2);
    cout << "intersection at :" << intersection(head1, head2);

    return 0;
}