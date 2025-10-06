// revision of map should be dont before this question attampting.
// this is optimal code for positive + negative elements in the vector.

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == k) {
            maxLen = max(maxLen, i + 1);   // MAXIMUM OPERATOR
        }

        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, -3, 1, 1, 1, -1, -4, 2, 3};
    long long k = 6;

    cout << "Longest subarray length with sum " << k << " is: "
         << longestSubarrayWithSumK(arr, k) << endl;

    return 0;
}
