#include <bits/stdc++.h>
using namespace std;

int main() {
    string st = "()()()(((())))";
    cout<<st<<endl;
    cout<<st[3]<<endl;
    st.replace(2, 1, "hnfnna");
    cout<<st;
    return 0;
}