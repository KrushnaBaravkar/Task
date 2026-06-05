#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSet(int n) {
        this->n = n;
        par.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return find(par[x]);
    }

    int unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
        return 0;
    }
};

int main() {
    DisjointSet dj(6);

    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl;

    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);

    cout << dj.find(2) << endl;

    dj.unionByRank(0, 4);

    return 0;
}
