// printing the actual subsequence.
#include <bits/stdc++.h>
using namespace std;

// Recurssion code.
vector<int> LIS_Recursion(
        vector<int>& nums,
        int i,
        int prev,
        vector<int> v
    ) 
    {
        // Base case
        if (i == nums.size()) {
            return v;
        }

        // Skip current element
        vector<int> skip = LIS_Recursion(
            nums, i + 1, prev, v
        );

        // Take current element
        vector<int> take;

        if (prev == -1 || nums[i] > nums[prev]) {

            v.push_back(nums[i]);

            take = LIS_Recursion(
                nums, i + 1, i, v
            );
        }

        // Return the longer subsequence
        if (skip.size() > take.size()) {
            return skip;
        }
        else {
            return take;
        }
    }

// Memoization code.
vector<int> LIS_Recursion(vector<int>& nums, int i, int prev, vector<int> v, vector<vector<int>> &dp){
        // Base case
        if (i == nums.size()) {
            return v;
        }

        if(dp[i].size()>0){
            return dp[i];
        }

        // Skip current element
        vector<int> skip = LIS_Recursion(
            nums, i + 1, prev, v
        );

        // Take current element
        vector<int> take;

        if (prev == -1 || nums[i] > nums[prev]) {

            v.push_back(nums[i]);

            take = LIS_Recursion(
                nums, i + 1, i, v
            );
        }

        // Return the longer subsequence
        if (skip.size() > take.size()) {
            return dp[i] = skip;
        }
        else {
            return dp[i] = take;
        }
    }



int main(){
    
    return 0;
}