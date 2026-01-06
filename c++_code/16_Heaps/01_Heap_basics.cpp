#include <bits/stdc++.h>
using namespace std;

int main() {
    // heap is a one way to inplement priority queue.
    //here we are implementing a Priority Queue using a Heap (provided by STL).
    // implementing max heap in which top element is always the largest element.
    priority_queue<int> pq;

    pq.push(10);
    pq.push(1);
    pq.push(5);
    pq.push(3);

    while(!pq.empty()){
        cout<<"Top : "<<pq.top()<<endl;
        pq.pop();
    }

    // implementing min-PQ in which minimum element always at the top of the PQ/heap.
    priority_queue<int, vector<int>, greater<int>> pqm;
    cout<<"implementing min-PQ"<<endl;

    pqm.push(10);
    pqm.push(1);
    pqm.push(5);
    pqm.push(3);

    while(!pqm.empty()){
        cout<<"Top : "<<pqm.top()<<endl;
        pqm.pop();
    }

    // We can also store stirings in the PQ. 
    cout<<"PQ for string datatype"<<endl;
    priority_queue<string, vector<string>, greater<string>> pqs;    //accending order implementation.

    pqs.push("Apna collage");
    pqs.push("Chai aur code");
    pqs.push("Green tea");
    pqs.push("Hello world");

    while(!pqs.empty()){
        cout<<"Top : "<<pqs.top()<<endl;
        pqs.pop();
    }
    return 0;
}
