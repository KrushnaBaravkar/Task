// DP approch - introducing new variable to avoide multiple computation losses.

#include <bits/stdc++.h>
using namespace std;

// solving fabionacci using MEMOIZATION(Recurssion + Additional_data_structure)
int fab(int n, vector<int> &DP){
    if(DP[n] != -1){
        return DP[n];
    }
    if(n == 0){
        DP[0] = 0;
        return 0;
    }
    else if(n == 1){
        DP[1] = 1;
        return 1;
    }
    int ans = (fab(n-1, DP) + fab(n-2, DP));
    DP[n] = ans;
    return ans;
}

// solving fabionacci using TABULATION
int fab_2(int n, vector<int> & feb){
    for(int i=2; i<=n; i++){
        feb[i] = feb[i-1] + feb[i-2];
    }

    return feb[n];
}
int main() {
    int a;
    cin>>a;
    // defining of array
    vector<int> DP(a+1, -1);
    // initialization with smallest slutions
    DP[0] = 0;
    DP[1] = 1;
    
    // executing of testing
    cout<<"fabonacchi of {a} : "<< fab_2(a, DP);
    return 0;
}

