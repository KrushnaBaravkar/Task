#include <bits/stdc++.h>
using namespace std;

// recurssive approch
int MCM(vector<int> &vec, int i, int j){ // return minimum cost to multiply j metrics
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

// Mamoization approch 
// carefully understand the creation of the storage and its size and how does it get used in the code is aslo important.
int MCM_mamo(const vector<int>& vec,
             int i,
             int j,
             vector<vector<int>>& dp)
{
    if(i == j){
        return dp[i-1][j-1] = 0;
    }

    if(dp[i-1][j-1] != -1){
        return dp[i-1][j-1];
    }

    int ans = INT_MAX;

    for(int k = i; k < j; k++){

        int cost1 = MCM_mamo(vec, i, k, dp);

        int cost2 = MCM_mamo(vec, k + 1, j, dp);

        int curr_cost =
            cost1 +
            cost2 +
            vec[i - 1] * vec[k] * vec[j];

        ans = min(ans, curr_cost);
    }

    return dp[i-1][j-1] = ans;
}

int main() {
    vector<int> a = {1,2,3,4,3};
    int n = a.size();
    vector<vector<int>> dp(n-1, vector<int>(n-1, -1));

    cout<<"Minimum poertion code for the given matrics is "<<MCM_mamo(a, 1, n-1, dp);  // for n elements in the vector there are only n-1 matrics will form in present question or case.
    return 0;
}