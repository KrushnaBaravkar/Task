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

class stack1{
public:
    Node* top;
    stack1(){
        top = nullptr;
    }
    
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    int pop(){
        if(top == nullptr){
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int top1(){
        if(top == nullptr){
            return -1;
        }
        return top->data;
    }
};
int main() {
    stack1 st;
    st.push(5);
    st.push(3);
    st.push(2);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top1()<<endl;
    return 0;
}