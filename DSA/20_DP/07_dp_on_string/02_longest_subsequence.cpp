#include <bits/stdc++.h>
using namespace std;

string LCS(string &s1, string &s2, int i, int j) {

    // Reached the end of either string
    if(i == s1.size() || j == s2.size()) {
        return "";
    }

    // Characters match
    if(s1[i] == s2[j]) {
        return s1[i] + LCS(s1, s2, i + 1, j + 1);
    }

    // Characters don't match
    string ans1 = LCS(s1, s2, i + 1, j);
    string ans2 = LCS(s1, s2, i, j + 1);

    // Return the longer subsequence
    return (ans1.size() > ans2.size()) ? ans1 : ans2;
}

// using DP
// DP / Tabulation solution
void dpLCS(string s1, string s2, vector<vector<string>> &dp) {

    int n = s1.size();
    int m = s2.size();

    // Base cases
    for(int i = 0; i <= n; i++) {
        dp[i][0] = "";
    }

    for(int j = 0; j <= m; j++) {
        dp[0][j] = "";
    }

    // Fill DP table
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= m; j++) {

            // Characters match
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + s1[i-1];
            }

            // Characters don't match
            else {
                if(dp[i-1][j].size() > dp[i][j-1].size()) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
}

int main() {

    string s1 = "avedgsr";
    string s2 = "aedhjsien";

    cout << "LCS = "
         << LCS(s1, s2, 0, 0)
         << endl;

    return 0;
}