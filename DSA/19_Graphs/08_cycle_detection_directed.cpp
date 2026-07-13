// directed graph = cycle detection = using DFS.


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

    bool helper(int u, vector<bool> &vis, vector<bool> &recurssion) { // T.C = o(V + E)
        vis[u] = true;
        recurssion[u] = true;

        list<int> neighbors = l[u];
        for (int v : neighbors) {
            if (!vis[v]) {
                if(helper(v, vis, recurssion))
                    return true;
            }
            else if(recurssion[v]){
                return true;
            }
        }
        recurssion[u] = false;   // backtrack - as recurssion for any cycle is ending, then we should make recurssion tracker false so that next cycle can use that.
        return false;
    }
    
    bool cycle_det(){
        vector<bool> vis(v, false);
        vector<bool> recurssion(v, false);

        for(int i=0; i<v; i++){
            if (!vis[i]) {
                if (helper(i, vis, recurssion))
                    return true;
            }
        }
        return false;
    }
    
};

int main() {
    graph gp(4);
    gp.addEdge(0,1);
    gp.addEdge(1,2);
    gp.addEdge(2,3);
    gp.addEdge(3,1);

    cout<<gp.cycle_det();

    return 0;
}