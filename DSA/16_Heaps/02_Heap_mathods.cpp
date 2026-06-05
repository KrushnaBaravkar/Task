#include <bits/stdc++.h>
using namespace std;

// self implemented and working. 
class heap{
    vector<int> v;   //CBT
public:
    void Push(int n){   // Max heap implementation.
        int child = v.size();
        int parent = (child - 1) / 2;
        if(v.empty()){
            v.push_back(n);
            return;
        }

        v.push_back(n);
        while(parent>=0 && v[child] > v[parent]){    // O(log(n))
            swap(v[child], v[parent]);
            child = parent;          // updated child.
            parent = (child - 1)/2;  // updated parent.
        }
    }

    void heapify(int i){   // i = parent index
        if(i>=v.size()){
            return;
        }
        int l = i*2 + 1;
        int r = i*2 + 2;

        int maxidx = i;

        if(l < v.size() && v[l]>v[maxidx]){
            maxidx = l;
        }
        if(r < v.size() && v[r]>v[maxidx]){
            maxidx = r;
        }

        swap(v[maxidx], v [i]);
        if(maxidx != i){
            heapify(maxidx);
        }
    }

    void pop(){
        //step 1
        swap(v[0], v[(v.size() -1)]);

        //step 2
        v.pop_back();

        //step 3 - o(log(n))
        heapify(0);
    }

    int top(){
        return v[0];    // Highest priority element 
    }

    bool empty(){
        return v.size() == 0; 
    } 

    void print_vector(){
        int i = 0;
        while(i < v.size()){
            cout<<v[i]<<" ";
            i++;
        }
    }
};

int main() {
    heap Heap;
    Heap.Push(10);
    Heap.Push(7);
    Heap.Push(2);
    Heap.Push(3);
    Heap.Push(9);
    Heap.Push(11);
    Heap.Push(14);
    Heap.Push(17);
    Heap.pop();
    Heap.print_vector();
    return 0;
}