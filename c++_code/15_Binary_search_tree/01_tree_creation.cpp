#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// insearting new node to the BST while intacting the properties of the BST.
// try to dry run this code because it is litte confusing.
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {   // FOUND
        return true;
    }

    if (root->data > key) {    // left subtree
        return search(root->left, key);
    } else {
        return search(root->right, key);   //
    }
}

Node* IS(Node* root){
    if(root->left == NULL){
        return root;
    }
    else{
        return IS(root->left);
    }
}
// OR
// Node* getInorderSuccessor(Node* root) {
//     while (root->left != NULL) {
//         root = root->left;
//     }
//     return root;
// }
// Node delation function.
Node* delet_node(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val > root->data){
        root->right = delet_node(root->right, val);
    }
    else if (val < root->data){
        root->left = delet_node(root->left, val);
    }
    else{
        // root->data == val
        //case 1 : 0 child case
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //case 2 : 1 child case
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        //case 3 : 2 children case.
        if(root->left != NULL && root->right != NULL){
            Node* Inorder_successor = IS(root->right);
            root->data = Inorder_successor->data;
            // delete Inorder_successor;  it can be done like that because there shuld be the childs exist for the Inorder successor node
            delet_node(root->right, Inorder_successor->data);
        }
    }
    return root; 
    
}

int main() {
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, n);

    // cout << "Inorder traversal of BST: ";
    // inorder(root);
    // cout << endl;
    inorder(root);
    cout<<endl;
    delet_node(root, 4)->data;
    inorder(root);
    return 0;
}
