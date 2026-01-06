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
            root->right = delet_node(root->right, Inorder_successor->data);  // understand the line carefully. 
        }
    }
    return root; 
    
}

void print_in_range(Node* root, int start, int end){
    if(root == NULL){
        return;
    }
    if(start <= root->data && end >= root->data){//case 1
        cout<<root->data<<" ";
        print_in_range(root->left, start, end);      
        print_in_range(root->right, start, end);      
    }
    else if(start > root->data){//case 2
        print_in_range(root->right, start, end);
    }
    else{//case 3
        print_in_range(root->left, start, end);
    }
}


void printpath(vector<int> path){
    for(int i=0; i<path.size(); i++){
        cout<<path[i];
    }
    cout<<endl;
}
void PathHelper(Node* root, vector<int> &path){  //have a look of the function carefully, it is bit tricky.
    // if(root->left == NULL){
    //     int i = 0;
    //     vector<int> temp = path;
    //     while(!temp.empty()){
    //         cout<<path[i]<<" ";
    //         temp.erase(temp.begin());
    //         i++;
    //     }
    //     cout<<endl;
    //     return;
    // }
    // path.push_back(root->data);
    // Path(root->left, path);
    // Path(root->right, path);
    // path.pop_back();

    if(root == NULL){
        return;
    }
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        printpath(path);
        path.pop_back();   //IMP Link
        return;
    }

    PathHelper(root->left, path);
    PathHelper(root->right, path);

    path.pop_back();
}
void rootToLeafPath(Node* root){
    vector<int> path;
    PathHelper(root, path);
}

// validate BST. Asked in interviewes.
// IMP Question
bool validateBST(Node* root, Node* min, Node* max) {
    if (root == NULL) {
        return true;
    }

    if (min != NULL && root->data <= min->data) {
        return false;
    }

    if (max != NULL && root->data >= max->data) {
        return false;
    }

    return validateBST(root->left, min, root) &&
           validateBST(root->right, root, max);
} 

// Balanced subtree - tree with smallest height corresponding to the given sorted sequesce. 
Node* sequenceToBalanceBST(vector<int> arr){
    if (arr.size() == 0){
        return NULL;
    }
    int index = arr.size() / 2;
    Node* root = new Node(arr[index]);
    root->left = sequenceToBalanceBST(arr[]);
    root->right = sequenceToBalanceBST(arr[index+1:]);
    return root;
}

// normal to Balance BST. - converting normal BST to the Balance BST.
void travelHelper(vector<int> a, Node* &root){
    if(root == NULL){
        return;
    }
    travelHelper(a, root->left);
    travelHelper(a, root->right);
    a.push_back(root->data);
}
void conversion(Node* root){
    vector<int> arr;
    travelHelper(arr, root);
    Node* temp = sequenceToBalanceBST(arr);
    cout<<temp;
}

int main() {
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, n);

    // cout << "Inorder traversal of BST: ";
    // inorder(root);
    // cout << endl;
    // inorder(root);
    // cout<<endl;
    // delet_node(root, 5)->data;
    // inorder(root);
    //buildBST(arr, n);
    // rootToLeafPath(root);
    //cout<<validateBST(root, NULL, NULL);
    vector<int> array = {3,4,5,6,7,8,9};
    sequenceToBalanceBST(array);
    return 0;

}
