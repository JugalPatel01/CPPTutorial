/*
    Graph : 
    -> A graph G is an ordered pair of a set V of vertices and a set E of edges. 
    G = (V,E)

    In the graph there are two types of the edges : 1) directed edges and 2) undirected Edges
    graph with directed edges are called a directed graph.
    graph with undirected edges are called an undirected graph.

    application of the graphs : 
    1) Social Network => undirected graph
    2) Inter linked webpages (world wide web) => directed graph
    3) web-crawling
    4) maps
    5) Peer to Peer Networks

    There are another two types of the graphs : 
    1) weighted graph : every edge has a different weight
    
    2) unweighted graph : It is a weighted graph with all edges having weight = 1 unit

    minimum posible edges in directed graph without selfloop and multiedges : 0
    maximum posible edges in directed graph without selfloop and multiedges : n*(n-1)
    minimum posible edges in undirected graph without selfloop and multiedges : 0
    maximum posible edges in undirected graph without selfloop and multiedges : n*(n-1)/2

    if graph has too many edges (nearly max) then that graph is called dense graph.for dense graph we use adjacency matrix
    if graph has too few edges then that graph is called sparse graph.for sparse graph we use adjacency list

    walk :- a sequence of vertices where each adjacent pair is connected by an edge.
    Simple Path : a walk in which no vertices (and thus no edges) are repeated.
    Trail : a walk in which no edges are repeated

    strongly connected graphs : If there is a path from any vertex to any other vertex.

    closed walk :- starts and ends at same vertex
    simple cycle :- no repetition other than start and end
    Acyclic grpah :- A graph with no cycles

    There are three different representation of graph : 
    1) Edge List
    time complexity for searching adjacent nodes = O(V^2) = O(E)
    time complexity for finding if two nodes are connected = O(E)

    2) Adjacency Matrix
    time complexity for searching adjacent nodes = O(V) + O(V) = O(V)
    time complexity for finding if two nodes are connected = O(1) =>if names are given as vertex then Time complexity = O(V)(for finding the node) + O(1)
    space complexity for storing all the edges is O(E) = O(V^2)

    3) Adjacency List
    time complexity for searching adjacent nodes = O(V) + O(V) = O(V)
    time complexity for finding if two nodes are connected = O(v)
    space complexity for storing all the edges is O(E + V) where |E|<<|V|*|V|



*/