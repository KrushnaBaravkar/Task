// find the element that aappears more than n/3 times in the array


// o(n) - T.C
#include <bits/stdc++.h>
using namespace std;

void mapping(vector<int> arr){
    int size = arr.size();
    unordered_map<int, int> m;

    for(int i=0; i<size; i++){   // form map with key as element of arr and value as frequency of that array.
        if(m.count(arr[i])){
            m[arr[i]]++;
            continue;
        }
        m[arr[i]] = 1;
    }

    for(pair<int,int> p : m){     // checking the conditions of that perticular question and write the answer.
        if(p.second > size/3){
            cout<<p.first<<" ";
        }
    }
}
int main() {
    vector<int> v = {1,5,3,2,5,5,5,5,7,5,5,5,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,};
    mapping(v);
    return 0;
}