// return no of combinations of coins give to achive the given amount.

#include <bits/stdc++.h>
using namespace std;

// Returns the number of combinations of coins to achieve the given amount
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base Case: There is exactly 1 way to make amount 0 (by choosing no coins)
    // when thare is amount = 0 then there is exactly one way to make amount 0 is that to not choose any coin.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            int coin = coins[i - 1];

            if (coin <= currentAmount) {
                // Option 1: Exclude the current coin (take value from previous row)
                // Option 2: Include the current coin (take value from current row, reduced amount)
                dp[i][currentAmount] = dp[i - 1][currentAmount] + dp[i][currentAmount - coin];
            } else {
                // Cannot include the current coin
                dp[i][currentAmount] = dp[i - 1][currentAmount];
            }
        }
    }

    return dp[n][amount];
}



int main() {
    vector<int> v = {1,2,5};
    int target = 5;
    cout<< change(target, v);
    return 0;
}