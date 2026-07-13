#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> nums){
    int totSum = 0;
    for(int a : nums){
    totSum += a;
    }

    int n = nums.size();
    int w = totSum/2;
    vector<vector<int>> dp(n+1 , vector<int>(w+1, 0));

    for(int i = 1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1Sum = dp[n][w];
    int grp2Sum = totSum - grp1Sum;
    return (grp1Sum - grp2Sum);
}

int main() {
    //Try to think of the solution as it is very similar question to the variation of 0-1 knapsack 
    return 0;
}