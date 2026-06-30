#include <bits/stdc++.h>
using namespace std;
class Graph{
    int v;          // size or number of vertex.
    vector<pair<int,int>>* l;    // l is the pointer pointing to the vector of pairs 
public:
    Graph(int size, vector<vector<int>> vec){
        this->v = size;
        l = new vector<pair<int, int>> [size];      // now we had created size amount of null vectors and that l going to point the first one of them.
        // we can use l[3] because compiler converts it into "* (l+3)" and as a result pointer arthmetic works and we can use that also.
        for(vector<int> each_v : vec){
            l[each_v[0]].push_back(make_pair(each_v[1], each_v[2]));    // adding the edge with the weight of it in it. the pair at any  place consider the neighbour and the weight of the edge.
        }
    }
};
int main() {
    // edge list: {from, to, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 5, 1},
        {4, 3, 2}
    };

    int vertices = 6;

    Graph g(vertices, edges);

    cout << "Graph created successfully" << endl;

    return 0;
}
