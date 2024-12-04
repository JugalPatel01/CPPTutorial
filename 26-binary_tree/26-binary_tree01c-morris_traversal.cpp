/*

    # Morris traversal for trees
    -> Using normal inorder, preorder, postorder traversal using stack or recursion(auxilary stack for function calls) takes O(N) time complexity and O(N) space complixty.
    -> But by using morris traversal we can reduce time complexity to O(1) from O(N). it will take some more operation then normal tree travarsal algorithms but it's time complexity is still O(N).

    -> Basic Appraoch for inorder traversal using morris traversal :
        -> as we know that inorder = left root right and preorder = root left right
        -> first we have to see whether there is a left child or not for main node(root node)
            -> if not then simply add it to the inorder list.
            -> otherwise before moving to the left child, we have to travere whole left subtree and have to find the right most child of the left subtree. after that we have to connect right most child to the main node(root node) and then move to the left child and repeat the same procedure.
            -> Now once we reach the right most child of the left subtree through traversal we have to check that whether it pointing to the main node(root node). if yes then remove that connection and then move to the right of the main node(root node).
            -> eg.

                       1                      1
                      / \                   / | \
                     /   \                 /  |  \
                    2     3               2   |   3
                   / \                   /|\  |
                  4   5                 4_| 5_|

                inital-tree             morris-traversal tree

            -> here if we have to apply the morris traversal then
            -> 1) we are on the root 1.
            -> 2) check for the left child, here it exists so we have to find the right most element of the left subtree and connect it with the root 1.
            -> 3) so here we have found that 5 is the right most child of the subtree so we connect 5 with 1 and then we move to the left means on the 2.
            -> 4) we will repeat the same process and connecting 4 to 2 and after that we will move to the 4.
            -> 5) now after visiting 4 we have to for right(2) as there is no left child of the 4 and we have to push 4 in the inorder traversal [4].
            -> 6) now we are on the 2 and now we have to again check for the right most child but here we have already connected right child to the main node(2). so here we have to remove that connection, then we have to add 2 in the inorder traversal [4,2] and after visiting 2 we have to move on the 5 and repeat the same process.
            -> 7) after visiting 5 we have to insert it into the inorder traversal [4,2,5] and then we have to move right as there is no left child of the 5.
            -> 8) now we are on the 1. now we have to again find the for the right most child of the subtree. but here we have already connected it with the 1. so we have to add the 1 in the inorder traversal [4,2,5,1] and after that we will disconnect it from 5 and move to the right of the 1. which is 3.
            -> 9) 3 is the last node and there is no right or left node so we have to simply add it to the inorder traversal[4,2,5,1,3].
            -> 10) Here our tree traversal is over and we got our inorder traversal 4, 2, 5, 1, 3.

        # NOTE : preorder traversal is the same but here we have to push the element in the preorder traversal first and then we have to move to the left.

    # Approach for the post order
        -> we know that post order traversal = Left-right-root
        -> so if we reverse the order of this calculation then it will become root-right-left.
        -> in pre_order we have calculated root-left-right. same as we can calculate root-right-left.
        -> after calculating root-right-left traversal we will just reverse that traversal and we will get left-right-root means post-order traversal.


*/

#include <iostream>
#include <vector>
#include <stack>
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

void pre_order(struct Node *root)
{
    vector<int> pre_ord_trav;
    Node *current_node = root;
    while (current_node != NULL)
    {
        if (current_node->left == NULL)
        {
            pre_ord_trav.push_back(current_node->data);
            current_node = current_node->right;
        }
        else
        {
            Node *temp = current_node->left;
            while (temp->right != NULL && temp->right != current_node)
            {
                temp = temp->right;
            }
            if (temp->right == NULL)
            {
                temp->right = current_node;
                pre_ord_trav.push_back(current_node->data);
                current_node = current_node->left;
            }
            else
            {
                temp->right = NULL;
                current_node = current_node->right;
            }
        }
    }

    cout << "Pre-order traversal for given tree is : ";
    for (auto i : pre_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

void in_order(struct Node *root)
{
    vector<int> in_ord_trav;
    Node *current_node = root;
    while (current_node != NULL)
    {

        if (current_node->left == NULL)
        {
            in_ord_trav.push_back(current_node->data);
            current_node = current_node->right;
        }
        else
        {
            Node *temp = current_node->left;
            while (temp->right && temp->right != current_node)
            {
                temp = temp->right;
            }

            if (temp->right == NULL)
            {
                temp->right = current_node;
                current_node = current_node->left;
            }
            else
            {
                temp->right = NULL;
                in_ord_trav.push_back(current_node->data);
                current_node = current_node->right;
            }
        }
    }

    cout << "Inorder Traversal of given tree is : ";
    for (auto i : in_ord_trav)
    {
        cout << i << " ";
    }
    cout << endl;
}

void post_order(struct Node *root)
{
    vector<int> post_ord_trav;
    Node *current_node = root;
    stack<int> reverse_post;
    while (current_node != NULL)
    {
        if (current_node->right == NULL)
        {
            reverse_post.push(current_node->data);
            current_node = current_node->left;
        }
        else
        {
            Node *temp = current_node->right;
            while (temp->left != NULL and temp->left != current_node)
            {
                temp = temp->left;
            }

            if (temp->left == NULL)
            {
                temp->left = current_node;
                reverse_post.push(current_node->data);
                current_node = current_node->right;
            }
            else
            {
                current_node = current_node->left;
                temp->left = NULL;
            }
        }
    }

    while (!reverse_post.empty())
    {
        post_ord_trav.push_back(reverse_post.top());
        reverse_post.pop();
    }

    cout << "Post order traversal for given tree is : ";
    for (auto i : post_ord_trav)
        cout << i << " ";

    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    pre_order(root);

    in_order(root);

    post_order(root);

    return 0;
}