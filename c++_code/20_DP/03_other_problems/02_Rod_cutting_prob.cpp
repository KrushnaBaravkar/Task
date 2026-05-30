#include <bits/stdc++.h>
using namespace std;

int rod_cutting(vector<int> lenght, vector<int> price, int rod_lenght){
    int n = lenght.size();
    vector<vector<int>> dp(n+1, vector<int>(rod_lenght+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=rod_lenght; j++){
            int avl_lenght = lenght[i-1];
            int present_price = price[i-1];

            if(avl_lenght <= j){
                dp[i][j] = max(dp[i-1][j], present_price + dp[i][j-avl_lenght]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    //printing the storage for validation.
    for(int i=0; i<=n; i++){
        for(int j=0; j<=rod_lenght; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][rod_lenght];
}

int main() {
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10,17,17,20};
    int rod_lenght = 8;

    cout<<rod_cutting(length, price, rod_lenght);
    return 0;
}