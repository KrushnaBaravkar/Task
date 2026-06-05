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
void incert(Node* head, int position, int value){
    int n = 0;
    Node*in = new Node(value);
    Node*temp = head;
    while(n != (position-1)){
        temp = temp->next;
        n++;
    }
    in->back = temp;
    in->next = temp->next;
    temp->next = in;
}/*code is not tune for the edge cases such as 
- if thee position is 0
- if the value of the head is null
changes for those specific cases are needed */ 

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    incert(head, 2, 100);            // function call for incertion function
    print(head);
    return 0;
}
