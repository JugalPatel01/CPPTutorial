/*
    doubly linked list ( basic operations  )

    * insertion at tail
    * insertion at head
    * deletion using position
    * deletion using value matching
    * display from front and reverse side;

 */
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
    head->prev = n;
    head = n;
}

void insert_at_tail(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void delete_node_using_val(node *&head, int val)
{
    node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            if (temp == head)
            {
                if (temp->next == NULL)
                {
                    head = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp->next->prev = NULL;
                    head = temp->next;
                    delete temp;
                    return;
                }
            }
            if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                delete temp;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }

        temp = temp->next;
    }
    cout << "given value is not present in the linked list :<" << endl
         << endl;
}

void delete_node_using_pos(node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    node *temp = head;
    int track = 1;
    while (temp != NULL && track <= pos)
    {
        if (track == pos)
        {
            if (pos == 1)
            {
                if (temp->next == NULL)
                {
                    head = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    head = temp->next;
                    temp->next->prev = NULL;
                    delete temp;
                    return;
                }
            }

            if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                delete temp;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
        track++;
    }
    cout << "linked list is smaller then given position" << endl;
}

void display(node *head)
{
    node *temp = head;
    node *temp2; // for storing last node of the linked list
    // traverse head to tail
    cout << "forward traverse using next pointer : ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp2 = temp;
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "reverse traverse using prev pointer : ";
    // traverse back to the head
    while (temp2 != NULL)
    {
        cout << temp2->data << " -> ";
        temp2 = temp2->prev;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;

    // insert node at tail
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);

    // insert node at head
    insert_at_head(head, 0);
    insert_at_head(head, -1);
    insert_at_head(head, -2);
    insert_at_head(head, -3);

    // print linked list
    display(head);
    cout << endl;

    // delete node if value matches
    delete_node_using_val(head, 5);
    delete_node_using_val(head, -5);
    delete_node_using_val(head, -3);
    display(head);
    cout << endl;

    // delete node if position matches
    delete_node_using_pos(head, 2);
    delete_node_using_pos(head, 1);
    display(head);
    cout << endl;

    return 0;
}