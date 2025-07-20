/*
    Name    : Jayed Hoshen
    ID      : 2204076

Tasks:
    01) Write a Graph class with the following members:
    02) Constructor with number of vertices and a directed/undirected flag.
    03) add_edge(int u, int v) : Adds an edge from u to v . If undirected, also add reverse edge.
    04) dfs(int v, vector<bool>& visited) : Performs DFS from vertex v .
    05) full_dfs() : Calls DFS from all unvisited vertices to handle disconnected graphs.
    06) bfs(int v, vector<bool>& visited) : Performs BFS starting from vertex v .
    07) full_bfs() : Calls BFS from all unvisited vertices to handle disconnected graphs.
    08) print_degrees() : Prints the degree of each vertex.
    09) get_adjacent_vertices(int v) : Returns all adjacent vertices of v .
    10) get_indegree(int v) : Returns the in-degree of v (only meaningful for directed graphs).
    11) get_outdegree(int v) : Returns the out-degree of v .
    12) print_indegree_outdegree() : Prints in-degree and out-degree for all vertices (for directed
    graphs only).

Bonus Tasks (Optional):
    01) Implement BFS using adjacency matrix instead of list.
    02) Implement iterative version of DFS.
    03) Add a method to find shortest path from source to all nodes using BFS.
    04) Use characters or strings as node labels.

******--->> Include sample input/output in comments <<---------******
*/

#include<bits/stdc++.h>
using namespace std;

// 01) Graph class created
class Graph{
private:
    int n;
    bool directed;
    vector<vector<int>> adj;
    vector<vector<int>> adj_matrix; // For bonus

public:
    // 02) Constructor created
    Graph(int vertices, bool isDirected) {
        n = vertices;
        directed = isDirected;
        adj.resize(n);
        adj_matrix.resize(n, vector<int>(n, 0)); // For bonus
    }

    // 03) implement add_edge method
    void add_edge(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge: " << u << " -> " << v << endl;
            return;
        }
        adj[u].push_back(v);
        adj_matrix[u][v] = 1; // Bonus
        if (!directed) {
            adj[v].push_back(u);
            adj_matrix[v][u] = 1; // Bonus
        }
    }

    // 04) Performs DFS from vertex v
    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u, visited);
        }
    }

    // 05) implement full_dfs method
    void full_dfs() {
        vector<bool> visited(n, false);
        cout << "DFS Traversal: ";
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited);
                components++;
            }
        }
        cout << endl;
        if (components > 1)
            cout << "\nGraph is not connected.\n";
        else
            cout << "\nGraph is connected.\n";
        cout << "Number of connected components: " << components << endl;
    }

    // 06) Performs BFS starting from vertex v
    void bfs(int v, vector<bool>& visited) {
        queue<int> q;
        visited[v] = true;
        q.push(v);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int u : adj[curr]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

    // 07) implement full_bfs method
    void full_bfs() {
        vector<bool> visited(n, false);
        cout << "\nBFS Traversal: ";
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                bfs(i, visited);
        }
        cout << endl;
    }

    // 08) Prints the degree of each vertex 
    void print_degrees() {
        cout << "\nDegrees:\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " = " << adj[i].size() << endl;
        }
    }

    // 09)  Returns all adjacent vertices of v
    vector<int> get_adjacent_vertices(int v) {
        if (v < 0 || v >= n) {
            cout << "Invalid vertex: " << v << endl;
            return {};
        }
        return adj[v];
    }

    // 10) Returns the in-degree
    int get_indegree(int v) {
        if (!directed) return -1;
        int indegree = 0;
        for (int i = 0; i < n; i++) {
            for (int u : adj[i]) {
                if (u == v)
                    indegree++;
            }
        }
        return indegree;
    }

    // 11) Returns the out-degree
    int get_outdegree(int v) {
        return adj[v].size();
    }

    // 12) Prints in-degree and out-degree
    void print_indegree_outdegree() {
        if (!directed) {
            cout << "In-degree and out-degree only meaningful for directed graphs.\n";
            return;
        }
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << ": In-degree = " << get_indegree(i)
                 << ", Out-degree = " << get_outdegree(i) << endl;
        }
    }

    // Bonus-01) BFS using adjacency matrix
    void bfs_matrix(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS (Adjacency Matrix) = ";
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            cout << curr << " ";
            for (int i = 0; i < n; i++) {
                if (adj_matrix[curr][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Bonus-02) Iterative version of DFS
    void dfs_iterative(int start) {
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);
        cout << "DFS Iterative = ";
        while (!s.empty()) {
            int curr = s.top(); s.pop();
            if (!visited[curr]) {
                visited[curr] = true;
                cout << curr << " ";
                for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
                    if (!visited[*it])
                        s.push(*it);
                }
            }
        }
        cout << endl;
    }

    // Bonus-03) Find shortest path using BFS
    void shortest_path_bfs(int src) {
        vector<int> dist(n, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int u : adj[curr]) {
                if (dist[u] == -1) {
                    dist[u] = dist[curr] + 1;
                    q.push(u);
                }
            }
        }
        cout << "\nShortest path distances from node " << src << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << "-> Distance = " << dist[i] << endl;
        }
    }
};

int main() {
    int node, edge, direction;
    cin >> node >> edge >> direction;

    Graph g(node, direction);

    for (int i = 0; i < edge; i++) {
        int u, v; cin >> u >> v;
        g.add_edge(u, v);
    }

    int start; cin >> start;

    g.full_bfs();
    g.full_dfs();
    g.print_degrees();

    vector<int> adj_v = g.get_adjacent_vertices(2);
    cout << "\nAdjacent vertices of 2 = ";
    for (int u : adj_v) cout << u << " ";
    cout << endl;

    if (direction) {
        cout << "In-degree of vertex 3 = " << g.get_indegree(3) << endl;
        cout << "Out-degree of vertex 0 = " << g.get_outdegree(0) << endl;
        g.print_indegree_outdegree();
    }

    // Bonus methods
    cout << "\n---------> Bonus Task output <-----\n\n";
    g.bfs_matrix(start);           
    g.dfs_iterative(start);        
    g.shortest_path_bfs(start);    

    return 0;
}


/* 
----------> Sample Input <-------------
6 5 1
0 1
0 2
1 3
4 5
2 3
0

-------------> Output <-----------------
BFS Traversal: 0 1 2 3 4 5       
DFS Traversal: 0 1 3 2 4 5       

Graph is not connected.
Number of connected components: 2

Degrees:
Vertex 0 = 2
Vertex 1 = 1
Vertex 2 = 1
Vertex 3 = 0
Vertex 4 = 1
Vertex 5 = 0

Adjacent vertices of 2 = 3
In-degree of vertex 3 = 2
Out-degree of vertex 0 = 2
Vertex 0: In-degree = 0, Out-degree = 2
Vertex 1: In-degree = 1, Out-degree = 1
Vertex 2: In-degree = 1, Out-degree = 1
Vertex 3: In-degree = 2, Out-degree = 0
Vertex 4: In-degree = 0, Out-degree = 1
Vertex 5: In-degree = 1, Out-degree = 0

---------> Bonus Task output <-----

BFS (Adjacency Matrix) = 0 1 2 3
DFS Iterative = 0 1 3 2 

Shortest path distances from node 0
Vertex 0-> Distance = 0
Vertex 1-> Distance = 1
Vertex 2-> Distance = 1
Vertex 3-> Distance = 2
Vertex 4-> Distance = -1
Vertex 5-> Distance = -1
*/
