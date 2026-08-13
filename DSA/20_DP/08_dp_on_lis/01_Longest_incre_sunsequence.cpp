#include <bits/stdc++.h>
using namespace std;


// ==================== RECURSION ====================

int LIS_Recursion(vector<int>& nums, int i, int prev) {

    // Base case
    if (i == nums.size()) {
        return 0;
    }

    // Skip current element
    int skip = LIS_Recursion(nums, i + 1, prev);

    // Take current element if it maintains increasing order
    int take = 0;

    if (prev == -1 || nums[i] > nums[prev]) {
        take = 1 + LIS_Recursion(nums, i + 1, i);
    }

    return max(take, skip);
}


// ==================== MEMOIZATION ====================

int LIS_Memoization(
    vector<int>& nums,
    int i,
    int prev,
    vector<vector<int>>& dp
) {

    // Base case
    if (i == nums.size()) {
        return 0;
    }

    // prev = -1 is mapped to index 0
    int prevIndex = prev + 1;

    if (dp[i][prevIndex] != -1) {
        return dp[i][prevIndex];
    }

    // Skip
    int skip = LIS_Memoization(
        nums, i + 1, prev, dp
    );

    // Take
    int take = 0;

    if (prev == -1 || nums[i] > nums[prev]) {
        take = 1 + LIS_Memoization(
            nums, i + 1, i, dp
        );
    }

    return dp[i][prevIndex] = max(take, skip);
}


// ==================== TABULATION ====================

int LIS_Tabulation(vector<int>& nums) {

    int n = nums.size();

    // dp[i][prev + 1]
    vector<vector<int>> dp(
        n + 1,
        vector<int>(n + 1, 0)
    );

    // Recursion depends on i + 1, so fill from right to left
    for (int i = n - 1; i >= 0; i--) {

        for (int prev = i - 1; prev >= -1; prev--) {

            // Skip current element
            int skip = dp[i + 1][prev + 1];

            // Take current element
            int take = 0;

            if (prev == -1 || nums[i] > nums[prev]) {
                take = 1 + dp[i + 1][i + 1];
            }

            dp[i][prev + 1] = max(take, skip);
        }
    }

    // Initially i = 0 and prev = -1
    return dp[0][0];
}


// ==================== MAIN ====================

int main() {

    vector<int> nums = {
        10, 9, 2, 5, 3, 7, 101, 18
    };

    cout << "Array: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << "\n\n";


    // Recursion
    int ans1 = LIS_Recursion(nums, 0, -1);

    cout << "LIS using Recursion: "
         << ans1 << endl;


    // Memoization
    int n = nums.size();

    vector<vector<int>> dp(
        n,
        vector<int>(n + 1, -1)
    );

    int ans2 = LIS_Memoization(
        nums, 0, -1, dp
    );

    cout << "LIS using Memoization: "
         << ans2 << endl;


    // Tabulation
    int ans3 = LIS_Tabulation(nums);

    cout << "LIS using Tabulation: "
         << ans3 << endl;


    return 0;
}