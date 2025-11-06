// brute force approch for the calculating
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0;
        int count = 0;

        while (left < nums.size()) {
            right = left;
            while (right < nums.size()) {
                if (nums[right] == 0) {
                    count++;
                    if (count <= k) {
                        maxLen = max(maxLen, (right - left + 1));
                        right++;
                    } else {
                        count = 0;
                        left++;
                        break;
                    }
                } else {
                    right++;
                    maxLen = max(maxLen, (right - left + 1));
                }
            }

            // Move left ahead to avoid infinite loop if right == nums.size()
            if (right == nums.size()) break;
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter number of elements in nums: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = sol.longestOnes(nums, k);
    cout << "Longest subarray with at most " << k << " zero flips: " << result << endl;

    return 0;
}
