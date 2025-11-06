#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Queue{
public:
    Node* top;    //
    Node* start;
    Queue(){
        top = nullptr;
        start = nullptr;
    }
    
    void push(int x){
        Node* temp = new Node(x);
        if(top == nullptr){
            top = start = temp;
        }
        else{top->next = temp;
        top = temp;
        }
    }
    int pop(){
        if(top == nullptr){
            return -1;
        }
        int value = start->data;
        Node* temp = start;
        start = start->next;
        delete temp;
        return value;
    }
    int top1(){
        if(top == nullptr){
            return -1;
        }
        return start->data;
    }
};
int main() {
    Queue st;
    st.push(5);
    st.push(3);
    st.push(2);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top1()<<endl;
    return 0;
}