#include <bits/stdc++.h>
using namespace std;

class Graph{
    int size;
    vector<pair<int, int>>* l;

public:
    Graph(int v, vector<vector<int>> arr/*contain list of objects as from, to, weight of the edge*/){
        this->size = v;
        l = new vector<pair<int, int>> [v];

        for(vector<int> vec : arr){
            l[vec[0]].push_back(make_pair(vec[1], vec[2]));
        }
    }
};

int main() {
    vector<list<int>> List(4);
    List[0].push_back(123);
    List[0].push_back(254);
    List[0].push_front(658);

    for (int x : List[0]) {
        cout << x << " ";
    }
    return 0;
}