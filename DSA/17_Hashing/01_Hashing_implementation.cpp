#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    // Destructor 
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;  // int* table- table of int,insted we want table of pointers of calss Node* there Node** table.

    int HashFunction(string key){
        int k = 0;
        for(int i=0; i<key.size(); i++){
            k += int(key[i])*int(key[i]);
        }
        return k % totSize;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }

        // copy old values
        for(int i=0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                incert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }
    
public:
    HashTable(int size){
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];   //table is a dynamically allocated ARRAY of Node*(Node pointers)

        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }
    }

    void incert(string key, int val){
        int idx = HashFunction(key);
        
        Node* temp = new Node(key, val);
        temp->next = table[idx];
        table[idx] = temp;

        currSize++;

        double lamda = currSize/totSize;
        if(lamda>1){
            rehash();
        }
    }

    void remove(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;

        while(temp != NULL){        // Find perticular key in the linklist at that perticular position of that table array.
            if(temp->key == key){
                if(prev == NULL){
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
    
                temp->next = NULL;  // safety for recursive destructor
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout<<"invalid index";
    }

    void search(string key){
        int idx = HashFunction(key);     // Find index in the array
        Node* temp = table[idx];
        while(temp != NULL){        // Find perticular key in the linklist at that perticular position of that table array.
            if(temp->key == key){
                cout<<"Value corresponding to key "<<key<<" is "<<temp->val;
                return;
            }
            temp = temp->next;
        }
        cout<<"Invalid Key.";
    }

    void print(){
        for(int i=0; i<totSize; i++){
            cout<<"idx"<<i<<"->";
            Node* temp = table[i];
            while(temp != NULL){
                cout<<"("<<temp->key<<", "<<temp->val<<") ->";
                temp = temp->next;
            }
            cout<< endl;
        }
    }
};

int main() {
    HashTable ht(5);

    ht.incert("India", 150);
    ht.incert("china", 170);
    ht.incert("USA", 50);
    ht.incert("UAE", 2);
    ht.incert("UK", 6);

    ht.print();
    // ht.search("USA");
    // ht.remove("USA");
    // ht.search("USA");

    return 0;
}