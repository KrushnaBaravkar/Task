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
class Trie{
    Node* root;
public:     
    Trie(){
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
        return root;
    }

    bool search(string s){  // T.C - o(L)
        Node* temp = root;
        for(char c : s){
            if(temp->children.count(c) == 0){
                return false;
            }
            temp = temp->children[c];
        }
        return temp->endOfString;
    }
};

bool helper(Trie &trie, string key) {
    if (key.size() == 0) {
        return true;
    }

    for (int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i + 1);
        string second = key.substr(i + 1);

        if (trie.search(first) && helper(trie, second)) {
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string> dict, string key) {
    Trie trie;

    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return helper(trie, key);
}


int main() {
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout << wordBreak(dict, "ilikesam") << endl;


    return 0;
}