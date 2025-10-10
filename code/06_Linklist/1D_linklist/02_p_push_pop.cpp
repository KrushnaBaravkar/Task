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
    }  // T.C = o(1)

    // adding node using push back
    void push_back(int val){
        Node* newNode = new Node(val);  // creating dynamic object/ node
        if(head == NULL){
            head = tail = newNode;
            //cout<<head->data<<" , "<<head;  // printing data and the memory location
            return;
        }
        else{     // learn carefull this block.
            tail->next = newNode;
            tail = newNode;   
        }
    }   // T.C = o(1)
    
    //ramoving node fron front using pop front.
    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp; 
    }   // T.C = o(1)
    
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
    }   // T.C = o(n)

    //Adding node at Pth position 
    void new_node(int a, int position){
        if(position < 0){
            cout<<"invalid position.";
            return;
        }
        
        if(position == 0){
            push_front(a);
        }                           // both the if cases are the special cases.
        else{
            Node* newNode = new Node (a);
            int n = 0;
            Node* temp = head;
            if(temp == NULL){
                cout<<"invalid position";
                return;
            }
            while(n != (position-1)){
                temp = temp->next;
                n++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        
    }   // T.C = o(n)

    void print_ll(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }   // T.C = o(n)
};

int main() {
    List ll;
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    // till now, we have created a link list
    
    //printing the linklist.
    ll.print_ll();

    ll.new_node(10, 1);
    ll.print_ll();

    return 0;
}