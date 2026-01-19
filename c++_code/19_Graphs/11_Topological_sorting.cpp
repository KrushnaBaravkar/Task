/*
Topologival sort using DFS approch 
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

    void DFS(int i, vector<bool> &vis, stack<int> &sort){
        vis[i] = true;
        list<int> neighbours = l[i];

        for(int v : neighbours){
            if(!vis[v]){
                DFS(v, vis, sort);
            }
        }
        sort.push(i);   // adding element in stack while back propogation. 
    }

    void topological_sort(){
        vector<bool> vis(v, false);
        stack<int> sort;

        for(int i=0; i<v; i++){   // checking for each element.
            if(!vis[i]){
                DFS(i, vis, sort);
            }
        }
        while(sort.size()>0){  // printing the topilogical sort.
            cout<<sort.top()<<" ";
            sort.pop();
        }
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

    gp.topological_sort();

    return 0;
}