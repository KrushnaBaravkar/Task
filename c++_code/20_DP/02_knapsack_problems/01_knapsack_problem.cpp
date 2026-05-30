#include <bits/stdc++.h>
using namespace std;

// fractional kanpsack (greedy approch).
// solve that problam ussing greedy in leetcode.
// solution using recurssion.
int knapsack_recurssion(vector<int> val, vector<int> wt, int w, int n){
    if(n==0 || w == 0){
        return 0;
    }

    int weight = wt[n-1];
    int cost = val[n-1];

    if(weight <= w){ //valid case 
        // inclusion senario
        int ans1 = knapsack_recurssion(val, wt, w-weight, n-1);
        
        // exclusion senario
        int ans2 = knapsack_recurssion(val, wt, w, n-1);

        return max(ans1, ans2);
    } else{
        //exclusion 
        return knapsack_recurssion(val, wt, w, n-1);
    }
}

// DP approch - Memoization approch(recurssive approch)
int knapsack_memoization(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>> &dp){
    if(dp[w][n] != -1){
        return dp[w][n];
    }
    if(n==0 || w == 0){
        return 0;
    }

    int weight = wt[n-1];
    int cost = val[n-1];

    if(weight <= w){ //valid case 
        // inclusion senario
        int ans1 = knapsack_memoization(val, wt, w-weight, n-1, dp);
        
        // exclusion senario
        int ans2 = knapsack_memoization(val, wt, w, n-1, dp);

        // insert the present computation in the DP array
        dp[w ][n] = max(ans1, ans2);

        // return max(ans1, ans2);
    } else{
        //exclusion 
        dp[n][w] = knapsack_memoization(val, wt, w, n-1, dp);
    }

    return dp[n][w];
}

// Tabulation approch - iterative approch.
// T.C = o(n*w )
int knapsack_tabulation(vector<int> val, vector<int> wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));  // cell values are as 0. to satisfy the base case 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){

            int weight = wt[i-1];
            int cost = val[i-1];

            if(weight <= j){
                dp[i][j] = max(dp[i-1][j], cost + dp[i-1][j-weight]);
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
    // int n = 5;
    // int w = 7;
    
    // // vector to be pass for DP purpose 
    // vector<vector<int>> Dp(n+1, vector<int>(w+1, -1));

    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int knapsack_wt = 10;
    cout<<knapsack_tabulation(val, wt, knapsack_wt, 5);
    return 0;
}