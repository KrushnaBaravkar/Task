// unordered and unweighted graphs.
// Building graph using "Adjacency List".


#include <bits/stdc++.h>
using namespace std;

class graph{
    int v; // No. of vertex
    list<int>* l;  // l is pointer points list<int> object. 

public:
    graph(int v){
        this->v = v;
        l = new list<int> [v];   // initialize v new lists and l points to 1st, l[1] points second and so on 
    }

    void addEdge(int u, int v){  // u -- v   --> there exist edge between u and v.
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS(int start_vertex){
        queue<int> q;  // for storing the vertes level wise
        vector<bool> validation(v, false);    // validating that the vertes is done or not, becaues different from BT here one vertex can have more that 3 neighoubers. in this case there is the possibility of the dublicates.

        q.push(start_vertex);    // initializing the process with starting node with our choice.
        validation[start_vertex] = true;
        while(q.size() > 0){    // iteration till the all the nodes will get completed.
            for(int i : l[q.front()]){
                if(validation[i] == false){
                    q.push(i);
                    validation[i] = true;
                }
            }
            cout<<q.front()<<", ";
            q.pop();
        }
    }

    void DFS(int u, vector<bool> &vis) { // T.C = o(V + E)
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for (int v : neighbors) {
            if (!vis[v]) {
                DFS(v, vis);
            }
        }
    }
    
    bool pathHelper(int src, int dest, vector<bool> &vis) {
        if (src == dest) {
            return true;
        }

        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                if (pathHelper(v, dest, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int src, int dest) {
        vector<bool> vis(v, false);
        return pathHelper(src, dest, vis);
    }

    
};

int main() {
    graph gp(7);
    gp.addEdge(0,1);
    gp.addEdge(0,2);
    gp.addEdge(1,3);
    gp.addEdge(2,4);
    gp.addEdge(3,5);
    gp.addEdge(4,5);
    gp.addEdge(5,6);

    // gp.BFS(4);

    vector<bool> vec(7, false);
    gp.DFS(0, vec);

    return 0;
}