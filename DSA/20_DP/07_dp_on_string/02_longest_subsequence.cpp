#include <bits/stdc++.h>
using namespace std;

string LCS(string &s1, string &s2, int i, int j) {

    // Reached the end of either string
    if(i == s1.size() || j == s2.size()) {
        return "";
    }

    // Characters match
    if(s1[i] == s2[j]) {
        return s1[i] + LCS(s1, s2, i + 1, j + 1);
    }

    // Characters don't match
    string ans1 = LCS(s1, s2, i + 1, j);
    string ans2 = LCS(s1, s2, i, j + 1);

    // Return the longer subsequence
    return (ans1.size() > ans2.size()) ? ans1 : ans2;
}

int main() {

    string s1 = "avedgsr";
    string s2 = "aedhjsien";

    cout << "LCS = "
         << LCS(s1, s2, 0, 0)
         << endl;

    return 0;
}