#include <bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<pair<int,int>>* l;
public:
    Graph(int size, vector<vector<int>> vec){
        this->v = size;
        l = new vector<pair<int, int>> [size];
        for(vector<int> each_v : vec){
            l[each_v[0]].push_back(make_pair(each_v[1], each_v[2]));
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
