#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,6,3,4,7,2,8,9};
    int target = 17;

    unordered_map<int,int> um;  // using unorder_map to store values as key and indes as value in the map.
    for(int i=0; i<v.size(); i++){
        
        int val_rem = target-v[i];
        if(um.count(val_rem)){
            cout<<um[val_rem]<<", "<<i;
            return 0;
        }
        um[v[i]] = i;

    }
    return 0;
}