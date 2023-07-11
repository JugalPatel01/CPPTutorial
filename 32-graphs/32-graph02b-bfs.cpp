/*
    ## seraches in the graphs :
    1) depth first search (DFS)
    2) breadth first search (BFS)


    2) breadth first serach
    -> going in the breadth for searching
    -> it is using queue data structure for searching

            a
           / \
           b d
           | |
           c e - g
           \ /
            f

        bfs(a) = a->b->d->d->e->f->g

 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
                           bfs(1) = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

                           i/p for terminal for whole graph : 7 8 1 2 1 3 2 4 2 5 2 6 2 7 3 7 6 7

    */

    queue<int> q;
    q.push(1);
    visited[1] = true;

    cout << "bfs traversal of given graph is : " << endl;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " -> ";

        vector<int>::iterator it;
        for (it = graph_adj_list[node].begin(); it != graph_adj_list[node].end(); it++)
        {
            if (visited[*it] == false)
            {
                q.push(*it);
                visited[*it] = true;
            }
        }
    }

    return 0;
}