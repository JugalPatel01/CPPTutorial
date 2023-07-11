/*

    ## seraches in the graphs :
    1) depth first search (DFS)
    2) breadth first search (BFS)


    1) depth first serach
    -> going in the depth for searching
    -> it is using stack data structure for searching

            a
           / \
           b d
           | |
           c e - g
           \ /
            f

        (first time when call comes on the node.)
        pre-order printing for dfs(a) = a->b->c->f->e->g->d
                                      = a->b->c->f->e->d->g

        in-order(when the call works inside the subtree of that node)

        (after working on all subtree, call comes last time on the node.)
        post-order printing for dfs(a) = g->d->e->f->c->b->a
                                       = d->g->e->f->c->b->a

 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_using_stack(vector<int> graph_adj_list[], int nodes, vector<bool> &visited, int start_node)
{
    stack<int> st;
    st.push(start_node);
    visited[start_node] = true;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        cout << node << " -> ";

        vector<int>::iterator it;
        for (it = graph_adj_list[node].begin(); it != graph_adj_list[node].end(); it++)
        {
            if (visited[*it] == false)
            {
                st.push(*it);
                visited[*it] = true;
            }
        }
    }
}

void dfs_using_recursion(vector<int> graph_adj_list[], int nodes, vector<bool> &visited, int start_node)
{
    // preorder
    visited[start_node] = true;
    cout << start_node << " -> ";

    // inroder
    vector<int>::iterator it;
    for (it = graph_adj_list[start_node].begin(); it != graph_adj_list[start_node].end(); it++)
    {
        if (visited[*it] == false)
        {
            dfs_using_recursion(graph_adj_list, nodes, visited, *it);
        }
    }
    // for post order uncomment below line :
    // cout << start_node << " -> ";
}

int main()
{
    int nodes, edges;
    cout << "enter no. nodes : ";
    cin >> nodes;
    cout << "enter no. edges : ";
    cin >> edges;

    // here we took nodes+1 because we know that array's are starting from 0 not 1. so we have to take one more extra space.
    vector<int> graph_adj_list[nodes + 1];
    vector<bool> visited(nodes + 1, 0);
    cout << "enter edges : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        graph_adj_list[x].push_back(y);
        graph_adj_list[y].push_back(x);
    }

    /*
                                   1 -- 3
                                  /   /
                                 2 -- 7
                               / | \ /
                              4  5  6

                           vertices : 7
                           edges : 8 [12 13 24 25 26 27 37 67]
                    preorder dfs(1) = 1 -> 3 -> 7 -> 6 -> 2 -> 5 -> 4         // if edge 12 is added before 13
                                    = 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 3         // if edge 13 is added before 12
                   postorder dfs(1) = 4 -> 5 -> 3 -> 7 -> 6 -> 2 -> 1         // if edge 12 is added before 13

                           i/p for terminal for whole graph : 7 8 1 2 1 3 2 4 2 5 2 6 2 7 3 7 6 7

    */

    cout << "dfs traversal of given graph using stack data structure : " << endl;
    dfs_using_stack(graph_adj_list, nodes, visited, 1);

    for (auto i : visited)
    {
        i = false;
    }
    cout << "dfs traversal of given graph using recursion (memory stack) : " << endl;
    dfs_using_recursion(graph_adj_list, nodes, visited, 1);
    return 0;
}