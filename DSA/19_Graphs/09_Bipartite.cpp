// 

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

    // implementation using "GRAPH COLOURING" approch.
    // implementation without using visited bool array. work of visited array done by the colour array itself.
    bool isBipartite(){  // return true if bipartite else false
        queue<int> q;
        // vector<bool> vis(v, false);    implementation without visited bool array
        vector<int> colour(v, -1);

        q.push(0);
        colour[0] = 0;
        // vis[0] = true;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            list<int> neighbours = l[curr];
            
            for(int v : neighbours){
                if(colour[v] == -1){  // unvisited
                    // vis[v] = true;
                    colour[v] = !colour[curr];
                    q.push(v);
                }
                else{
                    if(colour[v] == colour[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    
};

int main() {
    graph gp(5);
    gp.addEdge(0,1);
    gp.addEdge(0,2);
    gp.addEdge(1,3);
    gp.addEdge(2,3);
    gp.addEdge(0,3);


    cout<<gp.isBipartite();

    return 0;
}