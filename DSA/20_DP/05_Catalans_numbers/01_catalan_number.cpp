#include <bits/stdc++.h>
using namespace std;

int catlan(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    int ans = 0;  // variable to store Nth cal=talan.
    for(int i=0; i<n; i++){
        ans += (catlan(i) * catlan(n-i-1));
    }

    return ans;
}

// memoization approch.
int catlan_memoization(int n, vector<int> &dp){
    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];

    int ans = 0;  // variable to store Nth cal=talan.
    for(int i=0; i<n; i++){
        ans += (catlan_memoization(i, dp) * catlan_memoization(n-i-1, dp));
    }

    return dp[n] = ans;
}

// tabulation approch.
int catlan_tabulation(int n){
    vector<int> dp(n+1, 1);

    for(int i=2; i<=n; i++){
        int ans = 0;
        for(int j=0; j<i; j++){
            ans += dp[j] * dp[i-j-1];
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main() {
    cout<<catlan_tabulation(3);
    return 0;
}