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
        // l[v].push_back(u);   // it is directed hance u direct towards the v hance u is not a neighbour of the v any more.
    }

    void print(){   // print the created graph.
        for(int u =0; u<v; u++){   // accessing the vertexes 
            list<int> neighbour = l[u];
            cout<<u<<" : ";
            for(int i : l[u]){   // accessing the neighbours of that perticular vertex.
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    graph gp(5);
    gp.addEdge(0,1);
    gp.addEdge(1,2);
    gp.addEdge(1,3);
    gp.addEdge(3,1);
    gp.addEdge(3,4);

    gp.print();
    return 0;
}