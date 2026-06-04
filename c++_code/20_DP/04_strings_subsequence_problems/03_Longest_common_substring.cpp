#include <bits/stdc++.h>
using namespace std;

// tabulation approch 
// largest common substring - get the meaning in details and carefully.
int lcs(string &s1, string &s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    int ans = -1; // variable to store largest common substring to return the ans;

    for(int i=1; i<=n1 ; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;  // because not valid substring due to not matching of last characters/part.
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    string s1 = "abcdefghiiiij";
    string s2 = "abdcfgggiiiij";

    cout<<" Largest common substring is : "<<lcs(s1,s2);
    return 0;
}