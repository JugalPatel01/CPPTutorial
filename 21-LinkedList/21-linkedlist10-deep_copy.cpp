/*
    Q : Given a linked list of size N and each node of linked list has two links: one next pointer and second randomptr
        pointer.clone this linked list in O(N) time.

        struct Node {
            int x;
            *Node randomptr;
            *Node next;
        };

    eg :
                |---------|
    i/p :  1 -> 2 -> 3 -> 4 -> 5      { 1 points to 2 and 4; 2 points to 3 and 1; 3 points to 4 and 5; 4 points to 5 and 2;
           |^____|   |____^____^        5 points to NULL; }
           |______________|

    o/p : deep copy of above linked list
                  |---------|
             1 -> 2 -> 3 -> 4 -> 5
             |^____|   |____^____^
             |______________|

    Approach :
    there are two approaches :
    1) using extra memory
        -> make new linked list with only next pointers and map old and new nodes
        -> traverse the old list and set new node's randomptr as value of old node's randomptr
                new_node->randomptr = mp[old_node->randomptr]

    2) without using extra memory
        -> add a new nodes between old list. so new list will look like
            old_node_1 -> new_node_1 -> old_node_2 -> new_node_2 -> old_node_3 -> new_node_3 -> ... -> NULL
        -> now map the random pointers
                new_node_1->randomptr = old_node_1->randomptr->next;
        -> now seperate both list.
            old_node_1 -> old_node_2 -> old_node_3 -> old_node_4 -> ... -> NULL
            new_node_1 -> new_node_2 -> new_node_3 -> new_node_4 -> ... -> NULL

*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *randomptr;

    Node(int x)
    {
        data = x;
        next = NULL;
        randomptr = NULL;
    }
};

Node *make_copy(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    // make a map for mapping old and new nodes
    unordered_map<Node *, Node *> mp;
    Node *n_head = new Node(head->data);
    Node *temp = head;
    mp[temp] = n_head;

    // make new nodes and map with old nodes
    while (temp->next != NULL)
    {
        n_head->next = new Node(temp->next->data);
        temp = temp->next;
        n_head = n_head->next;
        mp[temp] = n_head;
    }
    temp = head;

    // set randomptr for new nodes using mapping
    while (temp != NULL)
    {
        mp[temp]->randomptr = mp[temp->randomptr];
        temp = temp->next;
    }

    return mp[head];
}

Node *make_copy_without_map(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    // add new nodes between the existing nodes
    Node *temp = head;
    while (temp != NULL)
    {
        Node *new_node = new Node(temp->data);
        new_node->next = temp->next;
        temp->next = new_node;
        temp = new_node->next;
    }

    // set random pointers
    temp = head;
    while (temp)
    {
        if (temp->randomptr != NULL)
        {
            temp->next->randomptr = temp->randomptr->next;
        }
        temp = temp->next->next;
    }

    // separate the new nodes
    temp = head;
    Node *n_head = temp->next;
    Node *n_temp = n_head;
    while (n_temp->next != NULL)
    {
        temp->next = temp->next->next;
        n_temp->next = n_temp->next->next;
        temp = temp->next;
        n_temp = n_temp->next;
    }
    temp->next = NULL;
    n_temp->next = NULL;

    return n_head;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "(";
        if (temp->randomptr)
            cout << temp->randomptr->data;
        cout << ") -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->randomptr = head->next->next->next;
    head->next->randomptr = head;
    head->next->next->randomptr = head->next->next->next->next;
    head->next->next->next->randomptr = head->next;

    Node *copied_list = make_copy(head);

    Node *copied_list_2 = make_copy_without_map(head);

    cout << "original list is : ";
    print_list(head);
    cout << "duplicate list is : ";
    print_list(copied_list);
    cout << "duplicate list without using any extra memory : ";
    print_list(copied_list_2);

    delete head;
    return 0;
}