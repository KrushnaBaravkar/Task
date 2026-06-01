#include <bits/stdc++.h>
using namespace std;

// function for returning the length of the largest subsequence of given 2 strings.
// resurssion approch.
int longest_subsequence_recurssion(string &s1, string &s2, int i/* index of s1*/, int j /*index for s2*/, int ans/*by default pass 0 intially*/){
    if(s1.size() == i || s2.size() == j){
        return ans;
    }

    if(s1[i] == s2[j]){
        ans++;
        return longest_subsequence_recurssion(s1, s2, i+1, j+1, ans);
    }
    else{
        int ans1 = longest_subsequence_recurssion(s1, s2, i+1, j, ans);
        int ans2 = longest_subsequence_recurssion(s1, s2, i, j+1, ans);
        ans = (ans1 > ans2) ? ans1 : ans2; 
    }

    return ans;
}

// function for returning the length of the largest subsequence of given 2 strings.
// Memoization(DP) approch.
int longest_subsequence_memoization(string &s1, string &s2, int i/* height of the storage */, int j /* weidth of the storage*/, vector<vector<int>> &dp/*DP storage*/){
    if(i == 0 || j == 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i-1] == s2[j-1]){
        dp[i][j] = 1 + longest_subsequence_memoization(s1, s2, i-1, j-1, dp);
    }
    else{
        int ans1 = longest_subsequence_memoization(s1, s2, i-1, j, dp);
        int ans2 = longest_subsequence_memoization(s1, s2, i, j-1, dp);
        dp[i][j] = (ans1 > ans2) ? ans1 : ans2; 
    }

    return dp[i][j];
}


// returning the largest subsequence from the given strings.
string largest_subsequence_recurssion(string &s1, string &s2, int i/* index of s1*/, int j /*index for s2*/, string ans){
    if(s1.size() == i || s2.size() == j){
        return ans;
    }

    if(s1[i] == s2[j]){
        ans.push_back(s1[i]);
        return largest_subsequence_recurssion(s1, s2, i+1, j+1, ans);
    }
    else{
        string ans1 = largest_subsequence_recurssion(s1, s2, i+1, j, ans);
        string ans2 = largest_subsequence_recurssion(s1, s2, i, j+1, ans);
        ans = (ans1.size() > ans2.size()) ? ans1 : ans2; 
    }

    return ans;
}

int main() {
    string s1 = "abcdgeeehgdhhcnmgk";
    string s2 = "abe";
    string ans= "";

    // cout<<"largest subsequence is : "<< longest_subsequence_recurssion(s1, s2, 0, 0, 0)<<endl;
    // cout<<"largest subsequence is : "<< largest_subsequence_recurssion(s1, s2, 0, 0, ans)<<endl;
    
    // memoization approch 
    // define the size of the storage.
    int i = s1.size();
    int j = s2.size();

    vector<vector<int>> dp(i+1 , vector<int> (j+1, -1));
    cout<<"longest subsequence with memoization approch is : "<< longest_subsequence_memoization(s1, s2, i, j, dp)<<endl;
    return 0;
}