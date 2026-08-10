#include <bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2, int i, int j) {

    // Reached the end of either string
    if(i == s1.size() || j == s2.size()) {
        return 0;
    }

    // Characters match
    if(s1[i] == s2[j]) {
        return 1 + LCS(s1, s2, i + 1, j + 1);
    }

    // Characters don't match
    int ans1 = LCS(s1, s2, i + 1, j);
    int ans2 = LCS(s1, s2, i, j + 1);

    return max(ans1, ans2);
}

// DP solution(Predered)
void dpLCS(string s1, string s2, vector<vector<int>> &dp){
    int n = s1.size();
    int m = s2.size();

    for(int i = 0; i < max(n, m); i++){
        if(i<n){
            dp[i][0] = 0;
        }
        if(i<m){
            dp[0][i] = 0;
        }
    }

    for(int i =1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main() {

    string s1 = "avedgsr";
    string s2 = "aedhjsien";

    vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
    dpLCS(s1, s2, dp);
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}