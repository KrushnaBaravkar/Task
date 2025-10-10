#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// addition of incertion function in this code.
void delete1(Node*& head, int k) {
    if (head == nullptr) return;  // empty list

    Node* temp = head;
    // Case 1: delete head node
    if (temp->data == k) {
        head = head->next;
        if (head != nullptr)
            head->back = nullptr;
        delete temp;
        return;
    }

    // Case 2: delete a non-head node
    while (temp != nullptr && temp->data != k) {
        temp = temp->next;
    }

    if (temp == nullptr) return; // not found
    // Now temp points to the node to delete
    Node* prevNode = temp->back;
    Node* nextNode = temp->next;

    if (prevNode != nullptr)
        prevNode->next = nextNode;

    if (nextNode != nullptr)
        nextNode->back = prevNode;

    delete temp;
}
/*alanyse the cade sarefully because it is bit confusing*/ 

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    delete1(head, 5);            // function call for deleation - where 8 is the element to be delete.
    print(head);
    return 0;
}
