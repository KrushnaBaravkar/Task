// longest common sustring 
// try to write the code to print the longest sunstring.
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "abcde";
    string s2 = "abfde";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );
    // will store only the longest one for the current char only and global maximum will be take care by the ans variable.

    int ans = 0;

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= m; j++) {

            if(s1[i-1] == s2[j-1]) {

                dp[i][j] = dp[i-1][j-1] + 1;

                ans = max(ans, dp[i][j]);
            }
            else {

                dp[i][j] = 0;
            }
        }
    }

    cout << "Longest Common Substring Length = "
         << ans << endl;

    return 0;
}