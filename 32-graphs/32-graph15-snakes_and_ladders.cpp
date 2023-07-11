/*

    * Snakes & Ladders
    Q : we are at square 1 and have to reach square 100. we have complete control over the die and can get any number from 1-6.
    For given ladders and snakes, find the minimum steps to reach at 100th square.

    i/p : Number of ladders : 2 => (3, 90), (56,76)
          Number of snakes : 3 => (99,10), (30,20), (20,5)

    o/p : 3 moves    1->(3->90)->96->100

    appraoch :
    -> run bfs and find shortest path

 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int find_moves(unordered_map<int, int> &ladders, unordered_map<int, int> &snakes)
{

    int moves = 0;
    bool found_100 = false;
    queue<int> q;
    vector<bool> visited(101, 0); // to avoid repetation and reduce time complexity we can use visited nodes
    q.push(1);
    visited[1] = 1;

    while (!q.empty() && !found_100)
    {
        int sz = q.size();
        while (sz--)
        {
            int x = q.front();
            q.pop();
            for (int i = 1; i <= 6; i++)
            {
                if (x + i <= 100 && snakes[x + i] && !visited[x + i])
                {
                    visited[snakes[x + i]] = 1;
                    q.push(snakes[x + i]);
                }
                else if (x + i <= 100 && ladders[x + i] && !visited[x + i])
                {
                    visited[ladders[x + i]] = 1;
                    if (ladders[x + i] == 100)
                    {
                        found_100 = true;
                    }
                    q.push(ladders[x + i]);
                }
                else if (x + i <= 100 && !visited[x + i])
                {
                    visited[x + i] = 1;
                    if (x + i == 100)
                    {
                        found_100 = true;
                    }
                    q.push(x + i);
                }
            }
        }
        moves++;
    }

    return moves;
}

int main()
{
    int no_of_ladders, no_of_snakes;
    cout << "enter total number of ladders : ";
    cin >> no_of_ladders;
    cout << "enter total number of snakes : ";
    cin >> no_of_snakes;
    unordered_map<int, int> ladders;
    unordered_map<int, int> snakes;

    cout << "enter starting and ending position of ladders : ";
    for (int i = 0; i < no_of_ladders; i++)
    {
        int start, end;
        cin >> start >> end;
        ladders[start] = end;
    }
    cout << "enter starting and ending position of snakes : ";
    for (int i = 0; i < no_of_snakes; i++)
    {
        int start, end;
        cin >> start >> end;
        snakes[start] = end;
    }

    int moves = 0;
    cout << "minimum moves to reach 100 is : " << find_moves(ladders, snakes) << endl;

    return 0;
}