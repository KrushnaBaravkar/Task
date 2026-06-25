#include <bits/stdc++.h>
using namespace std;
int MCM(vector<int> vec, int i, int j){ // return minimum cost to multiply j metrics
    if(i == j){
        return 0;
    }    

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        // for set from i to k
        int cost1 = MCM(vec, i, k);
        // for set form k+1 to j
        int cost2 = MCM(vec, k+1, j);
        
        int curr_partision_cost = cost1 + cost2 + (vec[i-1] * vec[k] * vec[j]);
        ans = min(ans, curr_partision_cost);
    }

    return ans;
}

int main() {
    vector<int> a = {1,2,3,4,3};
    int n = a.size();

    cout<<"Minimum poertion code for the given matrics is "<<MCM(a, 1, n-1);  // for n elements in the vector there are only n-1 matrics will form in present question or case.
    return 0;
}