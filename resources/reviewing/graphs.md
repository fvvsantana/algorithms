# Graphs
- Bipartite graph
- Adjacency matrix
    Space: O(N^2)
    Lookup: O(1)
- Adjacency list (a linked list for each row of the adjacency matrix).
    Space: O(E + N) (good for sparse graphs)
    Lookup: O(degree of node)
    Expensive allocation
Searches:    
    Time complexity:
        Adjacency matrix: O(N + N^2)
        Adjacency list: O(N + E)
    DFS:
        color(white, gray, black) recursion (or stack)
    BFS:
        color(white, gray, black) queue

Dijkstra:
    Greedy + heap containing non-visited nodes.
    Time: O(E log(N))
Floyd-Warshall:
    Loop N times through matrix: E[i, j] = min(E[i,j], E[i,k] + E[k,j])
    See if the path passing through k is better than the direct path.
    Time: O(N^3)
Prim:
    Greddy + heap of edges
    Time: O(E log(E)) == O(E log(V^2)) == O(E*2*log(V)) == O(E log(V))
    (could be even better, O(E + V log(V)) using sorcery)
Kruskal:
    Multiple initial connected components. Add edges if they connect different components.
    O(E log(V))
