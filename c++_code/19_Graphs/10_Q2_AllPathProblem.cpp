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

    void pathHelper(int src, int dest, vector<bool> &vis, string path){
        if(src == dest){
            cout<<path<<dest<<endl;
            return;
        }

        vis[src] = true;
        path += to_string(src) + " ";
        list<int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                pathHelper(v, dest, vis, path);
            }
        }

        // remove all the current stored data like path and visites so that they will not affert the path detection for other path.
        path = path.substr(0, (path.size() - 1));
        vis[src] = false;
    }
    void printAllPath(int src, int dest){
        vector<bool> vis(v, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    graph gp(5);
    gp.addEdge(0,1);
    gp.addEdge(0,2);
    gp.addEdge(1,3);
    gp.addEdge(2,3);
    gp.addEdge(0,3);

    gp.printAllPath(0, 3);

    return 0;
}