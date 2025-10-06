#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> a, int k, int n) {
    int lower = 0;
    int high = n - 1;
    int ans = -1;

    while (lower <= high) {
        int mid = (lower + high) / 2;
        if (a[mid] >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    return ans;
}
int upperBound(vector<int> a, int k, int n) {
    int lower = 0;
    int high = n - 1;
    int ans = -1;

    while (lower <= high) {
        int mid = (lower + high) / 2;
        if (a[mid] > k) {           // miner change in case of upper bound is that it is stricketly greater than the given one.
            ans = mid;
            high = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 3, 4, 5, 5, 5, 6, 8, 9};
    int n = a.size();
    int k = 5;
    
    int ans = upperBound(a, k, n);
    cout << "Index = " << ans << endl;

    return 0;
}
