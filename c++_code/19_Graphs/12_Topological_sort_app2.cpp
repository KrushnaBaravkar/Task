/*
Topologival sort - BFS / Kahn's algorithm approch.
- simplest approch
*/

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
        l[u].push_back(v);   // directed graphs
    }

    void calInDegree(vector<int> &indeg){  // calculate the indegree for the given graph and update the indegree of the perticular vertices.
        for(int i=0; i<v; i++){
            list<int> neighbour = l[i];
            for(int v : neighbour){
                indeg[v]++;
            }
        }
    }

    void topoSort2(){    // kahn's algorithm.
        vector<int> indeg(v, 0);
        calInDegree(indeg);
        queue<int> q;

        // 0 indeg vertices will push into queue.
        for(int i=0; i<v; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> neighbour = l[curr];
            for(int v : neighbour){
                indeg[v]--;
                if(indeg[v] == 0){  // no pending dependencies.
                    q.push(v);
                }
            }
        }
        cout<<endl; 
    }

};
int main() {
    graph gp(6);
    gp.addEdge(5,0);
    gp.addEdge(4,0);
    gp.addEdge(5,2);
    gp.addEdge(2,3);
    gp.addEdge(3,1);
    gp.addEdge(4,1);

    gp.topoSort2();

    return 0;
}