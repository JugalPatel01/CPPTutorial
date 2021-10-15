#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node *head;
void Insert(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print()
{
    node *temp = head;
    cout << "list is ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    head = NULL; // empty list;
    cout << "enter how many number? " << endl;
    int n;
    cin >> n;
    cout << "enter the numbers " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(x);
        print();
    }

    print();
    return 0;
}
