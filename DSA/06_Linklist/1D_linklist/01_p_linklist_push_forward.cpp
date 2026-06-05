#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node (val);  // creating dynamic object/ node
        if(head == NULL){
            head = tail = newNode;
            //cout<<head->data<<" , "<<head;  // printing data and the memory location
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void print_ll(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main() {
    List ll;
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(7);
    // till now, we have created a link list
    
    //printing the linklist
    ll.print_ll();

    return 0;
}


/*
# Data-structure -> 1D linked-list
   - stl container -> forward_list -> works on datastructure 1D list.
   
# Data-structure -> dounled linked-list 
   - stl container -> list -> works on datastructure doubled linked-list.

# Doubled linked-list - A doubly linked list is a 1D linear data structure where each node has two pointers
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

# 2D Linked-List - A 2D linked list is a grid-like structure, similar to a 2D matrix, where each node is connected in two directions (row & column).
ex: 
[ ] → [ ] → [ ]
 ↓     ↓     ↓
[ ] → [ ] → [ ]
 ↓     ↓     ↓
[ ] → [ ] → [ ]

struct Node {
    int data;
    Node* right;   // next column
    Node* down;    // next row
};
*/