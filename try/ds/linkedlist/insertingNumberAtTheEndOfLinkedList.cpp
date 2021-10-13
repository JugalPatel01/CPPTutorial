#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node *head;
void insert(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        node *temp1 = head;

        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}
void print()
{
    node *temp = head;
    cout << "list is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    head = NULL;
    cout << "how many number you wan't to add ";
    int n;
    cin >> n;
    cout << "enter number" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(x);
        print();
    }

    print();

    return 0;
}