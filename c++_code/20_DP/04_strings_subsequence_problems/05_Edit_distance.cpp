// leetcode problem 72 = edit distance.

#include <bits/stdc++.h>
using namespace std;

int ed(string &s1, string &s2){
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
    for(int i=0; i<=n1; i++){
        dp[i][0] = i;
    }
    for(int i=0; i<=n2; i++){
        dp[0][i] = i;
    }

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j-1], /*Insert operation*/
                                   min(dp[i-1][j], /*Delete operation*/
                                   dp[i-1][j-1]/*Replace operation*/));
            }
        }
    }
    
    return dp[n1][n2];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    cout<<"No. of operation to convert string s1 to string s2 is/are : "<<ed(s1,s2);

    return 0;
}