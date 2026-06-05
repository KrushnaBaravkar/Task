#include <bits/stdc++.h>
using namespace std;

// Tabulation approch - iterative approch.
// T.C = o(n*w )
int unbounded_knapsack_tabulation(vector<int> val/*vect storing val of perticular object*/, vector<int> wt/*vect storing wt of perticular item*/, int w/*knapsack capacity*/){
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));  // cell values are as 0. to satisfy the base case 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){

            int weight = wt[i-1];
            int cost = val[i-1];

            if(weight <= j){
                // this is one approch.
                int max_val = 0;
                for(int k=1; k<=(j/weight); k++){
                    max_val = max(max_val, k*cost + dp[i-1][j-(k*weight)]);
                }
                dp[i][j] = max(dp[i-1][j], max_val);

                // 2nd approch is that allow that element again and again
                // dp[i][j] = max(dp[i-1][j], cost + dp[i][j-weight] /*allowing all i elements at a time */);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    //printing the storage for validation.
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][w];
}
int main() {
    vector<int> val = {1,2,5};
    vector<int> wt = {1,2,5};
    int knapsack_wt = 5;

    cout<<unbounded_knapsack_tabulation(val, wt, knapsack_wt);

    return 0;
}