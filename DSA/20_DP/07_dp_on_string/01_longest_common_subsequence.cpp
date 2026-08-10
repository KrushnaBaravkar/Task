#include <bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2, int i, int j) {

    // Reached the end of either string
    if(i == s1.size() || j == s2.size()) {
        return 0;
    }

    // Characters match
    if(s1[i] == s2[j]) {
        return 1 + LCS(s1, s2, i + 1, j + 1);
    }

    // Characters don't match
    int ans1 = LCS(s1, s2, i + 1, j);
    int ans2 = LCS(s1, s2, i, j + 1);

    return max(ans1, ans2);
}

int main() {

    string s1 = "avedgsr";
    string s2 = "aedhjsien";

    cout << "LCS length = "
         << LCS(s1, s2, 0, 0)
         << endl;

    return 0;
}