// calculation of no of ways to climb the stears with variation on the no of stears to be climb in one attaimpt.

#include <bits/stdc++.h>
using namespace std;

// Tabulation approch. 
int no_of_str(int n, vector<int> &stair){
    for(int i=2; i<=n; i++){
        stair[i] = stair[i-1] + stair[i-2];
    }

    return stair[n];
}

// memoization approch 
int ways(int n, vector<int> &stair){
    if(stair[n] != -1){
        return stair[n];
    }

    if(n == 0){
        stair[0] = 1;  // way to reach stair 0 is 1.
        return 1;
    }
    else if(n == 1) {
        stair[1] = 1;
        return 1;
    }

    return ways(n-1, stair) + ways(n-2, stair);
}

// solution for steps to climb are 1,2,3
int ways_for_3_climbing_options(int n, vector<int> &stair){
    if(stair[n] != -1){
        return stair[n];
    }

    if(n == 0){
        stair[0] = 1;  // way to reach stair 0 is 1.
        return 1;
    }
    else if(n == 1) {
        stair[1] = 1;
        return 1;
    }
    else if(n == 2) {
        stair[2] = 2;
        return 2;
    }

    return (ways_for_3_climbing_options(n-1, stair) + ways_for_3_climbing_options(n-2, stair) + ways_for_3_climbing_options(n-3, stair));
}

int main() {
    int a;
    cout<<"enter the no.of stears : ";
    cin>>a;

    // why to run by tabulation.
    // vector<int> vec(a+1, 0);
    // vec[0] = 1;  // way to come to 0 the step is 1.
    // vec[1] = 1;
    // cout<<"no of waye to reach the stair(using tabulation approch) {a} is/are "<<no_of_str(a, vec);
    
    // way to run by memoization
    // vector<int> vec(a+1, -1);
    // cout<<"no of waye to reach the stair(using mamoization approch) {a} is/are "<<ways(a, vec);
    
    // executing for 3 options of execution(like you can take 1,2,3 steps at a time)
    vector<int> vec(a+1, -1);
    cout<<"no of waye to reach the stair(using mamoization approch) {a} with 1,2,3 sters at a time is/are "<<ways_for_3_climbing_options(a, vec);
    
    return 0;
}