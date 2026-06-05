// problem no - 820;


#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfString;

    Node(){
        endOfString = false;
    }
};
class trie{
    Node* root;
public: 
    trie(){
        root = new Node();    // root ptr of the tree defined ad nullptr. 
    }

    Node* insert(string key){  // Inserting new string in the tree.
        Node* temp = root;
        for(char c : key){
            if(temp->children.count(c)){
                temp = temp->children[c];
                continue;
            }
            else{
                temp->children[c] = new Node();
            }
            temp = temp->children[c];
        }
        temp->endOfString = true;
        cout<<"string inserted successfully."<<endl;   // Dibugger
        return root;
    }

    bool exist_st(string s){  // T.C - o(L)
        for(char c : s){
            if(root->children.count(c) == 0){
                return false;
            }
            root = root->children[c];
        }
        return root->endOfString;
    }

    int minimumLengthEncoding(vector<string>& words) {
        trie tr; // object of the calss trie.
        for(string s : words){    // insert function implementation.
            tr.insert(s);
        }

        string RString = "";
        for(string s : words){
            if(RString.size() == 0){
                for(char c : s){
                RString.push_back(c);
                }
            }
            

        }
    }
};

int main() {
    vector<string> v = {"one", "two", "three", "four", "five"};

    trie tr; // object of the calss trie.
    for(string s : v){    // insert function implementation.
        tr.insert(s);
    }

    cout<<endl;
    cout<<"existance of kay: "<<tr.exist_st("two");

    return 0;
}