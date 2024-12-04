/*
    * Linked List
    -> Linked list a linear data structure which stores list of values just like arrays but Linked list is not storing values in a continuous data block(memory location) like array. In linked list elements are connected with the pointers in linear manner.
    -> array
     ____________
    |1|2|3|4|5|6|
    `````````````
    -> Singly Linked list
    ___   ___   ___   ___   ___   ___
    |1|-->|2|-->|3|-->|4|-->|5|-->|6|
    ```   ```   ```   ```   ```   ```

    * why we need linked list (Limitations of arrays)?
    -> fixed size of array
    -> contiguous block of memory assinged to array
    -> Inserting or deleting is costly in terms of time in array

    * properties of linked list.
    -> Size can be modified
    -> Non-contiguous memory
    -> insertion and deletion at any point is easier.

    * Linked list
    -> certain types of linked list are available 1) singly 2) doubly 3) circular
    -> every data block in the linked list called nodes and nodes contain data value and pointer of the next node position.
                   ___________
             NODE  |data|next|-->
                   ```````````
    -> first node of the linked list is called head and it is the starting location of the linked list. so head pointer stores the addres of the first node of the linked list.

 */

#include <iostream>
using namespace std;

// we can build a node by using struct and class
/*
struct node{
    int data;
    node *next;
};

 */

// build a node using class
class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// insert a node at the tail of the linked list
// here we are passing head node's pointer using reference that is why we have used node* &head
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
}

// insert a node at the head of the linked list
void insert_at_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// seraching in the linked list
bool serach(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// delete node from the list
void delete_node(node *&head, int val)
{

    if (head == NULL)
    {
        cout << "list is empty!!!" << endl;
        return;
    }
    node *temp = head;
    if (head->data == val)
    {
        head = temp->next;
        delete temp;
        return;
    }
    if (serach(head, val))
    {
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;
    }
    else
    {
        cout << val << " is not in the list" << endl;
    }
}

// display a linked list
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

    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);

    display(head);

    insert_at_head(head, -1);
    insert_at_head(head, -2);
    insert_at_head(head, -3);

    display(head);

    cout << serach(head, 5) << endl;
    cout << serach(head, -5) << endl;

    delete_node(head, 5);
    delete_node(head, 6);
    delete_node(head, -6);
    delete_node(head, -3);

    display(head);

    return 0;
}