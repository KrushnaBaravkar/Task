/*
longest increasing subsequence 
*/

#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &arr1){
    // filtering the unique eelements using unordered set
    unordered_set<int> s(arr1.begin(), arr1.end());

    // ascending order array
    vector<int> arr2(s.begin(), s.end());
    sort(arr2.begin(), arr2.end());  // ascending sorted order

    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n1][n2];
}

int main() {
    vector<int> v = {1,3,5,4,7};
    cout<<"Largest Increasing Subarray : "<<lis(v);
    return 0;
}