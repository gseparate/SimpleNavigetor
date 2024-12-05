Implementation of the graph library and graph algorithms library

To compilation: \
$ make

Program can:\
1) load a graph from file in the adjacency matrix format, for example:\
5 \
0 1 1 1 0 \
1 0 0 1 1 \
1 0 0 1 0 \
1 1 1 0 1 \
0 1 0 1 0 
   
2) export a graph to a dot file, for example:\
graph graphname {\
    a;\
    b;\
    c;\
    d;\
    a -- b;\
    b -- c;\
    b -- d;\
}
3) Implement few algorithms with graph:\
    a) depth-first search in the graph from a given vertex\
    b) breadth-first search in the graph from a given vertex\
    c) searching for the shortest path between two vertices in a graph using Dijkstra's algorithm\
    d) searching for the shortest paths between all pairs of vertices in a graph using the Floyd-Warshall algorithm\
    e) searching for the minimal spanning tree in a graph using Prim's algorithm\
    f) solving the traveling salesman's problem using the ant colony algorithm\
    To be continued...
