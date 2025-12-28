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


int main() {
    int arr[] = {5, 1, 3, 4, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, n);

    // cout << "Inorder traversal of BST: ";
    // inorder(root);
    // cout << endl;
    cout<<search(root, 4);
    return 0;
}
