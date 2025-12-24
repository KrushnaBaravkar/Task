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
    cout << y; // Output: 2
    return 0;
}