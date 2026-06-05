/*
cost of connecting n roaps is equatl to sum of there length, then tell the code of connection of n ropes 
, if ropes and there lenght are discribe in vector as rope_lenght = {4,3,2,6}
*/ 

#include <bits/stdc++.h>
using namespace std;
class Rope{
public:
    int len;

    Rope(int len){
        this->len = len;
    }

    bool operator < (const Rope &obj) const{  // operator overloding so that PQ should know the meaning of that perticular operator and should creat desired pq(MAX/MIN).
        return this->len > obj.len;
    }
};

void Min_cost(vector<int> arr, int k){
    vector<Rope> Rope_len;
    for(int i=0; i<arr.size(); i++){
        Rope_len.push_back(arr[i]);
    }

    priority_queue<Rope> length(Rope_len.begin(), Rope_len.end());
    int cost = 0;
    for(int i=0; i<k; i++){
        cost += length.top().len;
        length.pop();
    }
    cout << "min_cost to join " << k << " rope/ropes is: " << cost;
}
int main() {
    vector<int> arr = {4,3,2,6};
    int k = 3; // no. of ropes to join
    Min_cost(arr, k);
    return 0;
}