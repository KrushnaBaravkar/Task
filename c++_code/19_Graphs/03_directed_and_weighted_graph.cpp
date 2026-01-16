// unordered and unweighted graphs.
// Building graph using "Adjacency List".

#include <bits/stdc++.h>
using namespace std;

class graph{
    int v; // No. of vertex
    list<pair<int,int>>* l;  // l is pointer points list<int> object. the list consist of pairs of neighbour and the weight of the edge.
    // pairs is of neighbour and the weight of the edge.

public:
    graph(int v){
        this->v = v;
        l = new list<pair<int,int>> [v];   // initialize v new lists and l points to 1st, l[1] points second and so on 
    }

    void addEdge(int u, int v, int w){  // u -- v   --> there exist edge between u and v.
        l[u].push_back(make_pair(v,w));   // pushing pair of naighbour and weight of the connection of vertex v and u.
        // l[v].push_back(u);    // it is directed hance u direct towards the v hance u is not a neighbour of the v any more.
    }

    void print(){   // print the created graph.
        for(int u =0; u<v; u++){   // accessing the vertexes 
            list<pair<int,int>> neighbour = l[u];
            cout<<u<<" : ";
            for(pair<int,int> Pair : l[u]){   // accessing the neighbours of that perticular vertex.
                cout<<"("<<Pair.first<<","<<Pair.second<<")"<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    graph gp(5);
    gp.addEdge(0,1,5);
    gp.addEdge(1,2,8);
    gp.addEdge(1,3,-5);
    gp.addEdge(3,1,-7);
    gp.addEdge(3,4,0);

    gp.print();
    return 0;
}