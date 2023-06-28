/*
    Basic operations on circular linked list

    circular linked list        1->2->3->4->5
                                |___________|

    insertion at head, insertion at tail , deletion, print CLL.

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
        head->next = head;
    }
    n->next = head;
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    head = n;
}

void insert_at_tail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    return;
}

int length_of_CLL(node *head)
{
    int count = 1;
    node *temp = head;
    if (temp->next == head)
    {
        return count;
    }
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_node_CLL(node *&head, int pos)
{
    node *temp = head;
    int length = length_of_CLL(head);
    pos = pos % length;
    /*
        // or we can give error of exceed length
        if(pos>length){
            cout<< "position out of bound "<<endl;
            return;
        }
     */
    int count = 1;
    if (pos == 1)
    {
        node *temp2 = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete temp2;
        return;
    }
    else
    {
        // to delete node in middle
        while (count != pos - 1)
        {
            count++;
            temp = temp->next;
        }
        node* to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;
    }
}

void display(node *head)
{
    node *temp = head;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    node *head = NULL;
    insert_at_head(head, 0);
    insert_at_head(head, -1);
    insert_at_head(head, -2);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);

    display(head);

    delete_node_CLL(head, 1);
    delete_node_CLL(head, 2);

    display(head);
    return 0;
}