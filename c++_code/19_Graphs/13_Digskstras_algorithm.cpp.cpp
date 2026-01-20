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

void min_dist(int src, int size, vector<vector<Edge>> &graph) {
    vector<int> dist(size, INT_MAX);

    // min-heap: pair(distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // have a look in details.

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        for (Edge neighbour : graph[curr]) {
            int nextNode = neighbour.V;  // accessing edge datastructure
            int weight = neighbour.wt;  // accessing edge datastructure

            if (dist[nextNode] > dist[curr] + weight) {   // EDGE Relaxisation.
                dist[nextNode] = dist[curr] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    
    for(int i : dist){
        cout<<i<<" ";
    }
}

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    min_dist(3, V, graph);
    return 0;
}

