// cycle detection - for undirected graph - using BFS 

#include <bits/stdc++.h>
using namespace std;

class graph{
    int v; 
    list<int>* l;  

public:
    graph(int v){
        this->v = v;
        l = new list<int> [v];   
    }

    void addEdge(int u, int v){  
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool cycle_detector(int u, int parent, vector<bool> &vis) {  // cycle detector.
        vis[u] = true;
        list<int> neighbors = l[u];
        
        for (int v : neighbors) {
            if (!vis[v]) {
                cycle_detector(v, u, vis);
            }
            else if(v != parent){   // v neighbour of u. if it is not equal to its parent then cycle condition satisfied.
                return true;
            }
        }
        return false;
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

    vector<bool> vec(7, false);
    cout<<gp.cycle_detector(6, -1, vec);
    return 0;
}