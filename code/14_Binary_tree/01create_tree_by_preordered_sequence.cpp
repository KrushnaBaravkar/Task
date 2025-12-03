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

static int idx = -1;

Node* buildTree(vector<int> vec){   
    idx++;

    if(vec[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(vec[idx]);  // currNode is a pointer which is created to point the newly created node 
    currNode->left = buildTree(vec);
    currNode->right = buildTree(vec);

    return currNode;
}

void preorderTravel(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTravel(root->left);
    preorderTravel(root->right);
}

void inorderTravel(Node* root){
    if(root == NULL){
        return;
    }
    inorderTravel(root->right);
    cout<<root->data<<" ";
    inorderTravel(root->left);
}

void postorderTravel(Node* root){
    if(root == NULL){
        return;
    }
    inorderTravel(root->right);
    inorderTravel(root->left);
    cout<<root->data<<" ";
} 

void levelorderTreversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node* curr = Q.front();
        Q.pop();
        
        cout<<curr->data<<" ";

        if(curr->left != NULL){
            Q.push(curr->left);
        }

        if(curr->left != NULL){
            Q.push(curr->left);
        }

    }
    cout<<" "<<endl; 
}

// printing the tree level wise.
void levelorderTreversal1(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        Node* curr = Q.front();
        Q.pop();
        
        if(curr == NULL){
            cout<<endl;
            if(!Q.empty()){
                Q.push(NULL);
            }
             continue;
        }

        cout<<curr->data<<" ";

        if(curr->left != NULL){
            Q.push(curr->left);
        }

        if(curr->right != NULL){
            Q.push(curr->right);
        }

    }
    cout<<" "<<endl; 
}

int height_of_TREE(Node* root){
    if(root == NULL){
        return 0;
    }
    Node* curr = root;
    int left_height = height_of_TREE(curr->left);
    int right_height = height_of_TREE(curr->right);
    return max(left_height, right_height) + 1;
}


int main() {
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(arr);
    // cout<<"root data = "<<root->data;

    int height = height_of_TREE(root);
    cout<<"height of the given tree : "<<height<<endl;
    return 0;
}