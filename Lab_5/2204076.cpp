#include <bits/stdc++.h>
using namespace std;

class Graph { 
private:
    int v;
    bool flag;
    vector <list<int>> adj;

public:
    Graph(int v, bool flag) {
        this->v = v;
        this->flag = flag;
        adj.resize(v);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        if(!flag) adj[v].push_back(u);
    }

    void dfs(int v, vector <bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for(int child : adj[v]) {
            if(!visited[child]) dfs(child, visited);
        }
    }

    void full_dfs() {
        vector <bool> visited(v, false);
        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                dfs(i, visited);
                cout << endl;
            }
        }
    }

    void print_degree() {
        for(int i = 0; i < v; i++) {
            cout << "Vertex " << i << " has degree " << adj[i].size() << '\n';
        }
    }

    vector <int> adj_vertex(int V) {
        vector <int> childs;
        for(int child : adj[V]) childs.push_back(child);
        return childs;
    }

    int get_inDegree(int v) {
        int in = 0;
        for (int i = 0; i < v; i++) {
            for (int child : adj[i]) {
                if (child == v) in++;
            }
        }
        return in;
    }

    int get_outDegree(int v) { return adj[v].size(); }

    void print_in_out_degree() {
        if(!flag) {
            cout << "This method is meaningful only for directed graphs\n";
            return;
        }
        for(int i = 0; i < v; i++) {
            int in = get_inDegree(i);
            int out = get_outDegree(i);
            cout << "Vertex " << i << ": In-degree = " << in << ", Out-degree = " << out << endl;
        }
    }
};

int main()
{
    Graph gh(5, true);

    gh.add_edge(0, 1);
    gh.add_edge(0, 2);
    gh.add_edge(1, 3);
    gh.add_edge(3, 4);
    gh.add_edge(4, 0);

    cout << "All component = ";
    gh.full_dfs();

    cout << "\nNumber of degrees(for directed graph)---\n";
    gh.print_degree();

    cout << "\nIn-degree and out-degree(for directed graph)\n";
    gh.print_in_out_degree();

    cout << "\nAdjacent vertices of vertex 0 = ";
    vector <int> child = gh.adj_vertex(0);
    for(int val : child) cout << val << " ";
    cout << endl;

    return 0;
}