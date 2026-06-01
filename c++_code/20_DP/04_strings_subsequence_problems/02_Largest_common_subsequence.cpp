#include <bits/stdc++.h>
using namespace std;

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

/*
try to write the memoization and tabulation code of the same
*/

int main() {
    string s1 = "abcdgeeehgdhhcnmgk";
    string s2 = "abe";
    string ans= "";

    cout<<"largest subsequence is : "<< largest_subsequence_recurssion(s1, s2, 0, 0, ans)<<endl;

    return 0;
}