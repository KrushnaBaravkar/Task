#include <bits/stdc++.h>
using namespace std;

int catlan(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    int ans = 0;  // variable to store Nth cal=talan.
    for(int i=0; i<n; i++){
        ans += (catlan(i) * catlan(n-i-1));
    }

    return ans;
}
int main() {
    cout<<catlan(3);
    return 0;
}