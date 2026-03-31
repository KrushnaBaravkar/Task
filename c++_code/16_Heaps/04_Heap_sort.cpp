#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int i, int n){
    int l = 2*i + 1;   //left child index
    int r = 2*i + 2;   // right child index
    int maxidx = i;

    if(l<n && arr[maxidx] < arr[l]){
        maxidx = l;
    }
    if(r<n && arr[maxidx] < arr[r]){
        maxidx = r;
    }

    if(maxidx != i){
        swap(arr[maxidx], arr[i]);
        heapify(arr, maxidx, n);
    }
}

void heap_sort(vector<int> &arr, int n){ // n - array size.
    // step 1 : creating max heap
    for(int i = (n/2)-1; i>=0; i--){
        heapify(arr, i, n);              
    }

    // step 2 : swapping 1st element(mas_element) and last element and form assending order 
    // Important loop by the point of view of implementation.
    // putting max element at last and parforming heapify for remaining tree.(taking elements to there correct positions)
    for(int i = 0; i<arr.size(); i++){
        swap(arr[0], arr[n-i-1]); 
        heapify(arr, 0, n-i-1);
    }
    // OR
    /*for(int i = n-1; i>=0; i--){
        swap(arr[0], arr[i]); 
        heapify(arr, 0, i);
    } */
}
int main() {
    vector<int> arr = {1,4,2,5,3};
    int n = arr.size();

    heap_sort(arr, n);
    int i = 0;
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
    return 0;
}