#include <bits/stdc++.h>
using namespace std;

struct Node {  // use when no need of class functions and no need of encapsulation.
    int data;
    Node* next;
    
    // Constructor with only data (next defaults to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
}; // Semicolon added here

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

int main() {
    vector<int> arr = {23252, 5, 8,78,96,9999, 7};
    Node* head = convertArr2LL(arr);
    //cout<<head->data<<endl;     // printing head of the linlist
    // printing whole linklist.
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}