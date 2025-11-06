#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    vector <int> arr;
    int top;
    int size = 10;
public:
    ArrayStack() : arr(size), top(-1) {
        
    }
    
    void push(int x) {
        top = top + 1;
        arr[top] = x;
    }
    
    int pop() {
        int temp = top;
        top = top - 1;
        return arr[temp];
    }
    
    int topf() {
        int a = arr[top];
        return a;
    }
    
    bool isEmpty() {
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    
    return 0;
}