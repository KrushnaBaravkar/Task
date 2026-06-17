#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;   // paremeter data gets the value of that variable data
        left = right = NULL;
    }
};

// bottomview of the binary tree 
void bottomView(Node*root){
    if(root == NULL) return;  // base case

    queue<pair<Node*, int>> Q; // pair(Node ptr, Horozontal_distance)
    map<int, int> m; // (horozonatl_diatance, currNode->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node*, int> currPair = Q.front();
        Q.pop(); // removing is imp else it goes like the inginite loop;
        Node* currNode = currPair.first;
        int currHD = currPair.second;

        m[currHD] = currNode->data;  // always stores current node so that it leads to get thee last element of any Horozontal distanced block.

        if(currNode->left !=  NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD - 1);
            Q.push(left);
        }
        if(currNode->right !=  NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD + 1);
            Q.push(right);
        }
    }

    cout<<"Bottom View of the BT is : ";
    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main() {
    
    return 0;
}