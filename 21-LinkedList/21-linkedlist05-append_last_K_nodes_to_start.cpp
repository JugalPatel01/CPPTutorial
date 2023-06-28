/*
    Append last K nodes to start of linked list using singly linked list

    eg. k = 3

    LL : 1 2 3 4 5 6
    o/p : 4 5 6 1 2 3

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

void append_node(node *&head, int k)
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        cout << "list has only one node" << endl;
        return;
    }

    int count = 0;
    node *temp = head;

    // count nodes in the list
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // give a counter for reaching at cutting node
    /*
        if k's value is higher then the count then there are many ways to handle that situation here are some
        * take modulo of k
        * return from the function with invalid k message
     */
    k = k % count;
    count = count - k;
    temp = head;
    while (temp && count - 1)
    {
        temp = temp->next;
        count--;
    }
    if (temp == NULL || temp->next == NULL)
    {
        cout << "there is no node to cut" << endl;
        return;
    }
    // store cut node into the temp2
    node *temp2 = temp->next;
    node *temp3 = temp->next;
    temp->next = NULL;

    // reach at the end of the linked list to connect it with the head
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    // connect end of cut linked list to head of the original linked list
    temp2->next = head;

    // change head to the starting point of the cut linked list
    head = temp3;
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

    int k;
    cout << "enter value of K (k is no. of last nodes to append infront of the list) : ";
    cin >> k;
    append_node(head, k);
    display(head);
    return 0;
}