#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5,6,3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int i = 0;
    int j = 0;
    vector<int> unionarr;
    while(i<n1 && j< n2){
        if(arr1[i] <= arr2[j]){
            if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
                unionarr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
                unionarr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(j<n2){
        if(unionarr.size() == 0 || unionarr.back() != arr2[j]){
            unionarr.push_back(arr1[j]);
        }
        j++;
    }
    while(i<n1){
        if(unionarr.size() == 0 || unionarr.back() != arr1[i]){
            unionarr.push_back(arr1[i]);
        }
        i++;
    }

    for(int a1 =0; a1<unionarr.size();  a1++){
        cout<<unionarr[a1];
    }
    return 0;
}  