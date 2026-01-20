// Have a look in depth.

#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int V;
    int wt;

    Edge(int v, int wt) {
        this->V = v;
        this->wt = wt;
    }
};

void bellmanFord(vector<vector<Edge>> graph, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {  // v-1 iterations.
        for (int u = src; u < V; u++) {  // for each edge after src because start from any other edge then it will caues INT_MAX overflow.
            for (Edge e : graph[u]) {   // for each edge passing to current vertex.
                if (dist[e.V] > dist[u] + e.wt) {
                    dist[e.V] = dist[u] + e.wt;
                }
            }
        }
    }

    for (int d : dist){
        cout<<d<<" ";
    }
}


int main() {
    // Bellman Ford Graph
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));

    graph[2].push_back(Edge(3, 2));

    graph[3].push_back(Edge(4, 4));

    graph[4].push_back(Edge(1, -1));


    bellmanFord(graph, V, 0);
    return 0;
}

