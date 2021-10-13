#include <iostream>
using namespace std;

class Node
{
public:
    int a;
    Node *next;
};
Node *head;

void Insert(int data, int n)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    
}
void print();

int main()
{

    head = NULL;
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Print();
    return 0;
}