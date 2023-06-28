/*
    reverse K nodes in a linked list

    eg.  1 2 3 4 5 6             & k = 2 then
    opt  2 1 4 3 6 5
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

void insert_at_front(node *&head, int val)
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
}

node *reverse_k_node(node *&head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *next;
    int temp = k;
    while (temp>0 && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        temp--;
    }
    head->next = reverse_k_node(curr, k);

    return prev;
}

void display_LL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *head = NULL;
    insert_at_front(head, 8);
    insert_at_front(head, 7);
    insert_at_front(head, 6);
    insert_at_front(head, 5);
    insert_at_front(head, 4);
    insert_at_front(head, 3);
    insert_at_front(head, 2);
    insert_at_front(head, 1);

    int k;
    cout << "enter the k : ";
    cin >> k;

    display_LL(head);
    head = reverse_k_node(head, k);
    display_LL(head);
    return 0;
}