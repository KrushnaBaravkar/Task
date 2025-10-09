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
    
    // adding node using push back
    void push_back(int val){
        Node* newNode = new Node (val);  // creating dynamic object/ node
        if(head == NULL){
            head = tail = newNode;
            //cout<<head->data<<" , "<<head;  // printing data and the memory location
            return;
        }
        else{     // learn carefull this block.
            tail->next = newNode;
            tail = newNode;   
        }
    }
    
    //ramoving node fron front using pop front.
    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp; 
    }
    
    // removing node from back;
    void pop_back(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
        temp = temp->next;
        delete temp; 
    }

    void print_ll(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    List ll;
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    // till now, we have created a link list
    
    //printing the linklist.
    ll.print_ll();

    ll.pop_back();
    ll.print_ll();

    return 0;
}