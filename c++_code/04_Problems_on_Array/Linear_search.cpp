#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,4,6,3,5,7,8,9};
    int n = 9;
    for(int a=0; a<arr.size(); a++){
        if(arr[a] == 9){
            return a;
        }
    }
    return -1;
}