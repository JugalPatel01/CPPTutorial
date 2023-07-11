/*
    NOTE : in this block of comment block we discuss about what is disjoint set union.

    * disjoint set union (Union find)

    * disjoint-set
    -> This data structure is defined as a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.

    ## Applications of disjoint set union
    1) finding MST (krushkal algorithm)
    2) connected components in a grpah
    3) cycle detection, etc...

    * equivalent classes
    -> a relation over a set of elements a1,a2,...,an. can be divided into equivalent classes. The equivalent class of an
       element a is the subset of S that contains all the elements of s that are related to a.

    Now, divide a sets into equivalent classes through two opeartions : find, union
    1) union : join two subsets into a single subset.

        pseudo code :
        union(int a, int b){
            a = find_set_parent(a);
            b = find_set_parent(b);
            if(a!=b){
                parent[b] = a;
            }
        }

    2) find : determine which subset a particular element is in. this can be used for determining if two elements are in the
              same subset.
        pseudo code :
        find_set_parent(int a){
            if(a == parent[a])
            return a;
            return find_set_parent(parent[a]);
        }


    -> A set is divided into subsets. each subset contains related elements.If we come to know that the two element aᵢ aⱼ are
       related, then we do following things:
    1) find the subset : sᵢ contains aᵢ
    2) find the subset : sⱼ contains aⱼ
    3) if sᵢ sⱼ are two independent subsets then we create a new subset by taking union of sᵢ sⱼ.

    eg. -> sets s1 = {1,2,3} s2 = {4,5,6}
    Q. which set contains 5?
    -> s2
    to reduce time complexity we use leading element/parent technique.
    -> in this technique we give a parent to each elements.
    -> so in above example {1,2,3} has parent 1 and {4,5,6} has parent 4.
    -> in find operation suppose we ask that whether 1 & 4 are in same set? then we compare their parent.

    * Basic implementation of disjoint set union
    -> i/p : elements : 1,2,3,4     here, leaders of each element are element itself.
    -> operation : unoin(1,2)
        1--2    leader of 1 is 1 itself and leader of 2 is 1
    -> operation : unoin(3,4)
        3--4    leader of 3 is 3 itself and leader of 4 is 3
    -> operation : unoin(2,4)
    here we do union of leaders/parents so,
        1--3    here leader of 1 & 3 is 1.
        |  |
        2  4    leader of 2 is 1 and leader of 4 is 3.

    -> so building time complexity for building this kind of set is O(n) for this chaining reasons.

    -> to reduce time complexity we can directly assign parents while finding parent when doing union.
        1--3    here leader of 1 & 3 is 1.
        |  |
        2  4    leader of 2 is 1 and leader of 4 is 3.

    -> to further reduce time complexity of making set we can use concept of union by size/rank :
        (it will reduce time complexity to O(α(n)). where α(n) is inverse ackermann function and it has O(n) space complexity )


    pseudo code for above technique:

    void make(int v){
        parent[v] = v;
        size[v] = 1;
    }

    void find_set(int a){
            if(a == parent[a])
            return a;
            return find_set(parent[a]);
    }

    void union_sets(int a,int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(size[a] < size[b]){
                swap(a,b);
            }
        parent[b] = a;
        size[a] += size[b];
        }
    }

 */

/*

    * Cycle detection in a undirected graph using disjoing set union
                0
               / \
              1   2
               \ /
                3


 */

#include <iostream>
#include <vector>
using namespace std;

void make_set(vector<int> &parent, vector<int> &size_of_set, int i)
{
    parent[i] = i;
    size_of_set[i] = 1;
}

int find_set(vector<int> &parent, int a)
{
    if (parent[a] == a)
    {
        return a;
    }
    return parent[a] = find_set(parent, parent[a]); // path compression
}

void union_sets(vector<int> &parent, vector<int> &size_of_set, int a, int b)
{
    a = find_set(parent, a);
    b = find_set(parent, b);

    if (a != b)
    {
        if (size_of_set[a] < size_of_set[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size_of_set[a] += size_of_set[b];
    }
}

int main()
{
    int nodes, edges;
    cout << "enter no. nodes : ";
    cin >> nodes;
    cout << "enter no. edges : ";
    cin >> edges;
    vector<vector<int>> graph_adj_list(nodes);
    vector<int> parent(nodes);
    vector<int> size_of_set(nodes);
    bool cycle = false;

    for (int i = 0; i < nodes; i++)
    {
        make_set(parent, size_of_set, i);
    }

    cout << "enter edges : ";
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        graph_adj_list[x].push_back(y);
        graph_adj_list[y].push_back(x);

        int set_of_x = find_set(parent, x);
        int set_of_y = find_set(parent, y);

        if (set_of_x == set_of_y)
        {
            cycle = true;
        }
        else
        {
            union_sets(parent, size_of_set, x, y);
        }
    }

    if (cycle)
    {
        cout << " There is cycle in the graph " << endl;
    }
    else
    {
        cout << " There is no cycle in the graph." << endl;
    }

    /*
            (init 0) (init 1)
      (parent 0) 0 -- 1 (parent 0)
                 |    |
      (parent 0) 2 -- 3 (parent 0)
            (init 2)|(init 3)
                    |
                    |------> for this edge both parents are same so we can conclude that there is a cycle in the graph.

        nodes : 4
        edges : 4 [01 13 23 02]
        o/p : cycle found

        template input : 4 4 0 1 1 3 2 3 0 2
    */

    return 0;
}