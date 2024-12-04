/*

    # Tree traversal using stack
    -> It uses stack data structure for implementing preorder, inorder and postorder tree traversal
    -> This will take time complexity of O(N) and space complexity of O(N) to traversal who tree.
    -> Basic Approach :
        * for pre-orer approach 1
            0> we know that pre-order traversal means root-left-right.
            1> first we initialize the stack.
            2> we will push the node(root) into it.
            3> then we will pop it from the stack and will add it to the pre-order list and then we will push right node and left node of that node(root) respectively.
            4> we will follow step 3 until our stack will not become empty.
            5> at the end when our stack will become empty, we will have pre-order traversal of the given tree in the pre-order list.

        * for pre-order approach 2
            1> first we initialize the stack.
            2> then we visit the node from the root node and then add it into the pre-order list and also we will push it into the stack and then move towards to the left node of the current node.
            3> we will continue this process until our current node will not become NULL.
            4> now if current node is null then we pop the element from the stack and check for the right.
            5> then we will repeat the steps 2 to 4 until our stack will not become empty.
            6> at last we have pre-order traversal in the pre-order list.

        * for in-order
            0> NOTE : we know that inorder traversal means left-root-right.
            1> first we initialize the stack.
            2> then we push root into it and then we will go left to the root.
            3> we will continue this thing until our node will not become null.
            4> if our node is null then we will pop the element from the stack and then add it to the in-order list. and will go to the right of the poped node.
            5> we will repeat this proecess until our stack will not become empty.
            6> After our stack become empty we have a list of the in-order traversal in the in-order list.

        * for post-order using 2 stack
            0> we know that post-order traveral means left-right-root.
            1> first we initialize 2 stacks(stack 1 & stack 2).
            2> then we will push root into the first stack(stack 1).
            3> then we pop the node(temp) from the first stack(stack 1) and then push it to the second stack(stack 2).and push left and right of the poped node(temp) into the first stack(stack 1) respectively.
            4> we will repeat the same process until our first stack(stack 1) not become empty.
            5> once our first stack(stack 1) become empty. we have a post-order traversal in the stack in the reverse order.
            6> so we have to pop all the elements from the second stack(stack 2). and then push those elements into the post-order list.
            7> After second stack(stack 2) will become empty. we have correct post-order in the post-order list.

        * for post-order using 1 stack
            1> first we initalize stack.
            2> then we push the node(root) and then move to the left.
            3> we will repeat the same process until our node will become null.
            4> if it's null then we will go to the right of the stack's top element(top node of stack).
            5> if right node is not null then we will make our current node to the right node.
            6> otherwise when our right node is NULL then we will pop the element from the stack and push that element in to the post-order list.
            7> after this we will check whether our stack's top element's right is poped element or not. if it is true then we will  pop that node from the stack and add it to the post-order list. we will repeat this  process until stack's top element's right is not same as the poped element.
            8> we will repeat step 2 to 7 till our stack will become empty.
            9> At the end we have a perfect post-order traversal in the post-order list.

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void pre_order_approach_1(struct Node *root)
{
    vector<int> pre_ord_trav;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        pre_ord_trav.push_back(temp->data);
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }

    cout << "preorder traversal of given tree using appraoch 1 is : ";
    for (auto i : pre_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

void pre_order_approach_2(struct Node *root)
{
    vector<int> pre_ord_trav;

    stack<Node *> st;

    Node *current = root;
    while (current != NULL or !st.empty())
    {
        if (current != NULL)
        {
            pre_ord_trav.push_back(current->data);
            st.push(current);
            current = current->left;
        }
        else
        {
            Node *temp = st.top();
            st.pop();
            current = temp->right;
        }
    }

    cout << "preorder traversal of given tree using approch 2 is : ";
    for (auto i : pre_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

void in_order(struct Node *root)
{
    stack<Node *> st;
    Node *temp = root;
    vector<int> in_ord_trav;
    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            temp = st.top();
            st.pop();
            in_ord_trav.push_back(temp->data);
            temp = temp->right;
        }
    }

    cout << "Inorder traversal for given tree is : ";
    for (auto i : in_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

void post_order_using_1_stack(struct Node *root)
{
    stack<Node *> st;
    vector<int> post_ord_trav;
    Node *current_node = root;

    while (current_node != NULL || !st.empty())
    {
        if (current_node != NULL)
        {
            st.push(current_node);
            current_node = current_node->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                post_ord_trav.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    post_ord_trav.push_back(temp->data);
                }
            }
            else
            {
                current_node = temp;
            }
        }
    }

    cout << "post order of given tree using 1 stacks is : ";
    for (auto i : post_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

void post_order_using_2_stack(Node *root)
{
    stack<Node *> st1, st2;
    vector<int> post_ord_trav;

    st1.push(root);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();

        st2.push(temp);
        if (temp->left)
        {
            st1.push(temp->left);
        }
        if (temp->right)
        {
            st1.push(temp->right);
        }
    }

    while (!st2.empty())
    {
        post_ord_trav.push_back(st2.top()->data);
        st2.pop();
    }

    cout << "post order of given tree using 2 stacks is : ";
    for (auto i : post_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    pre_order_approach_1(root);
    pre_order_approach_2(root);
    in_order(root);
    post_order_using_1_stack(root);
    post_order_using_2_stack(root);

    delete root;

    return 0;
}