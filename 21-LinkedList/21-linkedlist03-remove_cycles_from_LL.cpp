/*
    * Floyd's Algorithm / Hare and Tortoise Algorithm
    -> Detect Cycles and remove cycles from the Linked list
    -> This algo uses two pointers one moving twice as fast as the other one. The faster one is called the faster pointer and the other one is called the slow pointer.
    -> steps:
        -> take two pointers : fast & slow
        -> fast will move two steps and slow will move one step
        -> run a loop till (fast or fast->next will be null)
        -> if both pointer met to each other then there exist a loop otherwise there is no loop.
        -> to remove loop take any pointer to the starting position again. suppose we took fast to the starting point.
        -> now both pointer (fast & slow) will move only one step.
        -> now when they both met to each other. make slow pointers previous node's next to NULL instead of meeting point.
        -> so it will remove cycle from the linked list.

    other then above method there are tons of methods to find loop/ cycle in the linked list .
    like, using hashing , by putting flag in each node, etc...

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

void make_cycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (--count < pos)
    {
        cout << "can't able to make loop" << endl;
        return;
    }
    temp->next = startNode;
    return;
}

bool detect_cycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void remove_cycle_from_LL(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            fast = head;

            if (fast == slow)
            {
                while (fast->next != slow)
                {
                    fast = fast->next;
                }
                fast->next = NULL;
                return;
            }
            while (true)
            {
                if (fast->next == slow->next)
                {
                    slow->next = NULL;
                    return;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
    }
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
    make_cycle(head, 5);
    // display(head);
    cout << detect_cycle(head) << endl;

    remove_cycle_from_LL(head);
    display(head);

    return 0;
}