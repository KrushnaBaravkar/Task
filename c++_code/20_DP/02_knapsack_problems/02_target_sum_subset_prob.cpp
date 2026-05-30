#include <bits/stdc++.h>
using namespace std;
/* 
we have vector of options .
we had target to be obtain from sum of the options in the vector.
we have to tell is it possible.
ans :
we have 2 choices for each option that select or not to select.
storage - 2d array to store and we will store array of the selected elements till now.
and when the condition of the sum get satisfied will return that array.
*/


// tabulation approch.
bool target_sum(vector<int> v, int t){
    int n = v.size();

    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(j>=v[i-1]){
                dp[i][j] = max(v[i-1] + dp[i-1][j-v[i-1]] /*including the parsent number*/ , dp[i-1][j] /*not including  the present number*/); 
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    //printing the storage for validation.
    for(int i=0; i<=n; i++){
        for(int j=0; j<=t; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // validating the answer 
    return dp[n][t] == t;
}

// solve using memoization 


int main() {
    vector<int> v = {4, 2, 7, 1, 3};
    int target = 7;
    cout<< target_sum(v, target);
    return 0;
}