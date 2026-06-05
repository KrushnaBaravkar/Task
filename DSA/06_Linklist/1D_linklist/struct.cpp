#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    
    // Constructor with only data (next defaults to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
}; // Semicolon added here

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* y = new Node(arr[0], nullptr); // Create first node with value 2
    Node* z = new Node(arr[1]); // Create first node with value 2
    y->next = z;
    cout << y->next<<"  "<<z<<endl; // Output: 2
    cout<<y->data<<"  "<<y->next->data<<"  "<< z->data;
    return 0;
}