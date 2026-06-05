#include <bits/stdc++.h>
using namespace std;

int ceil(vector<int> a, int k, int n) {
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

int floor(vector<int> a, int k, int n) {
    int lower = 0;
    int high = n - 1;
    int ans = -1;

    while (lower <= high) {
        int mid = (lower + high) / 2;
        if (a[mid] <= k) {
            ans = mid;
            lower = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int main() {
    vector<int> a = {1, 3, 4, 5, 5, 5, 6, 8, 9};
    int n = a.size();
    int k = 7;
    
    int ans1 = ceil(a, k, n);
    int ans2 = floor(a, k, n);
    cout << "ceil Index = " << ans1 << endl<<"floor index = "<<ans2;

    return 0;
}