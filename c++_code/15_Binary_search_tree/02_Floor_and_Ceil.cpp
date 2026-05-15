#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find Floor
int findFloor(Node* root, int X) {
    int floor = -1;

    while (root) {
        if (root->data == X)
            return root->data;

        if (root->data < X) {
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

// Find Ceil
int findCeil(Node* root, int X) {
    int ceil = -1;

    while (root) {
        if (root->data == X)
            return root->data;

        if (root->data > X) {
            ceil = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}

// Inorder Traversal (for checking BST)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    Node* root = NULL;

    // Insert values
    int arr[] = {10, 5, 15, 2, 7, 12, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder Traversal (Sorted BST): ";
    inorder(root);
    cout << endl;

    int X;
    cout << "Enter value to find Floor and Ceil: ";
    cin >> X;

    int floor = findFloor(root, X);
    int ceil = findCeil(root, X);

    cout << "Floor: " << floor << endl;
    cout << "Ceil: " << ceil << endl;

    return 0;
}