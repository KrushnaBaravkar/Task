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

// building the tree using Preorde traversel-it uses the vector of node values in which null/end of the branch is being shown by -1 value.
Node* buildTree(vector<int> vec){   
    idx++;

    if(vec[idx] == -1){       // end of the branch.
        return NULL;
    }

    Node* currNode = new Node(vec[idx]);  // currNode is a pointer which is created to point the newly created node 
    currNode->left = buildTree(vec);
    currNode->right = buildTree(vec);

    return currNode;
}

// Preorder traversal.
void pre_order_Travel(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    pre_order_Travel(root->left);
    pre_order_Travel(root->right);
}

// InOrder traversal.
void in_order_Travel(Node* root){
    if(root == NULL){
        return;
    }
    in_order_Travel(root->right);
    cout<<root->data<<" ";
    in_order_Travel(root->left);
}

// PostOrder traversal.
void post_order_Travel(Node* root){
    if(root == NULL){
        return;
    }
    post_order_Travel(root->right);
    post_order_Travel(root->left);
    cout<<root->data<<" ";
} 

// LEVEL order traversal-Bredth first approch.
// without recurssion.
void leve_lorder_Treversal(Node* root){
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

// printing the tree level wise(in the form of tree).
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

// Height of the tree.
int height_of_TREE(Node* root){
    if(root == NULL){
        return 0;
    }
    Node* curr = root;
    int left_height = height_of_TREE(curr->left);
    int right_height = height_of_TREE(curr->right);
    return max(left_height, right_height) + 1;
}

// count of the Nodes present in the subtree.
int count_of_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int left_count = count_of_nodes(root->left);
    int right_count = count_of_nodes(root->right);
    return left_count + right_count + 1;
}

// sum of all the nodes of the tree
int sum_of_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int left_sum = sum_of_nodes(root->left);
    int right_sum = sum_of_nodes(root->right);
    return (left_sum + right_sum + root->data);
}

// DIAMETER of the binary tree 
// approch 1 - o(n^2) time complexivity   
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int curr_diameter = (height_of_TREE(root->left) + height_of_TREE(root->right) + 1);
    int left_tree_diam = diameter(root->left);
    int right_tree_diam = diameter(root->right);
    //return max(curr_diameter, max(left_tree_diam, right_tree_diam));  
    return max({curr_diameter, left_tree_diam, right_tree_diam});  
}

// Diameter approch 2
// approch has - complexivity of o(n).
pair<int, int> diameter1(Node* root){
    if(root == NULL){
        return make_pair(0, 0);
    }
    // (Diameter, height)
    pair<int, int> leftinfo = diameter1(root->left);
    pair<int, int> rightinfo = diameter1(root->right);

    int currDiam = leftinfo.second + rightinfo.second + 1;
    int finalDiam = max(currDiam, max(leftinfo.first, rightinfo.first));
    int currHei = max(leftinfo.second, rightinfo.second) + 1;
    return make_pair(finalDiam, currHei);
}  // try to find out is there any space complexivity is there or not.


// self written logic for identifying the subtree in the main tree
// bool find_tree(Node* root, Node* subroot){
//     if(root == NULL && subroot == NULL){
//         return true;
//     }
//     else if((root != NULL && subroot == NULL) || (root == NULL && subroot != NULL)){
//         return false;
//     }
//     if(root->data == subroot->data){
//         return (find_tree(root->left, subroot->left) && find_tree(root->right, subroot->right));
//         // here is the bug, only one function unable to find the structure and identity of the subtree in the main tree so we wanted to use another function to match the identicalness and the structure.
//     }
//     else{
//         int isLeftSubtree = isSubTree(root->left, subroot);
//         if(!isLeftSubtree){
//             return isSubTree(root->right, subroot);
//         }
//     }
// }  


// ideal logic for the above functionality 
// following function is just for checking the tree after the found identical root, can it leade to the identicalness of both the trees or not???.
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    return (isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}
// followin function is for finding the first identical nodes as try to match the nodes of the main tree to the first node of the given subtree.
bool isSubTree(Node* root, Node* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }
    else if((root != NULL && subroot == NULL) || (root == NULL && subroot != NULL)){
        return false;
    }
    
    if(root->data == subroot->data){
        //identical case for the subtrees
        if(isIdentical(root, subroot)){
            return true;
        }
    }

    int isLeftSubtree = isSubTree(root->left, subroot);
    if(!isLeftSubtree){
        return isSubTree(root->right, subroot);
    }
}

// topview of the binary tree 
void topView(Node*root){
    if(root == NULL) return;  // base case

    queue<pair<Node*, int>> Q; // pair(Node ptr, Horozontal_distance)
    map<int, int> m; // (horozonatl_diatance, currNode->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node*, int> currPair = Q.front();
        Q.pop(); // removing is imp else it goes like the inginite loop;
        Node* currNode = currPair.first;
        int currHD = currPair.second;

        if(m.count(currHD) == 0){  // count for HD = 0 then add that uniquely visable node from the above.
            m[currHD] = currNode->data;
        }

        if(currNode->left !=  NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD - 1);
            Q.push(left);
        }
        if(currNode->right !=  NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD + 1);
            Q.push(right);
        }
    }
    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
} 

// Kth level problem 
// following is the helper function that we should creat in the question, to solve it with one additional argument as currecn level of the node.
void KthHelper(Node* root, int k, int currLevel){
    if(root == NULL){
        return;
    }
    if(currLevel == k){
        cout<<root->data<<" ";
        return;
    }
    KthHelper(root->left, k, currLevel+1);
    KthHelper(root->right, k, currLevel+1);
}
// following is tha function provide in the question. we should use that only, so that we use the helper function be make task easy.
void KthLevel(Node* root, int k){
    KthHelper(root, k, 1);
    return;
}

// Lowest common ancestor.
// Approch 1 - with time complexivity of o(n) and space complexivity is also o(n)
// function to find the path.
bool findPath(Node* root, int k, vector<int> &V){
    if(root == NULL){
        return false;
    }
    // vector<int> V;
    V.push_back(root->data);
    if(root->data == k){
        return true;
    }
    if(((findPath(root->left, k, V))||(findPath(root->right, k, V)))){
        return true;
    }
    V.pop_back();
    return ((findPath(root->left, k, V))||(findPath(root->right, k, V)));
}
// function to valiadate the LCA for the found 2 paths.
int LCA(Node* root, int n1, int n2){
    vector<int> V1;
    vector<int> V2;
    findPath(root, n1, V1);
    findPath(root, n2, V2);
    int n = 0;
    int lca = -1;
    while(!(V1.empty() || V2.empty())){
        if(V1[n] != V2[n]){
            return lca;
        }
        lca = V1[n];
        n++;
    }
    return -1;
}

//Lowest common ancestor 
//Approch - 2 (time complexivity of o(n) + space complexivity of o(1))
Node* LCA2(Node* root, int n1, int n2){
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;  // treneary statement accounts all the three cases of the leftTREE and rightTree
}

int KthAncistor(Node* root, int n, int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;  // distance to itself is 0
    }
    int left = KthAncistor(root->left, n, k);
    int right = KthAncistor(root->right, n, k);

    if(left == -1 && right == -1){
        return -1;
    };
    int dist = 1 + (left == -1 ? right : left);
    if(dist == k){
        return root->data;  // correct ancestor
    }
    return dist; // pass distance upward
}

// Transform to Sum Tree;


int main() {  
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(arr);
    // cout<<"root data = "<<root->data;
    //creating the subtree to check the ufunction defined to check the subtree problem 
    Node* subroot = new Node(2);
    // subroot->left = new Node(4);
    // subroot->right = new Node(6);
    // cout<<"existance of the subtree : "<<isSubTree(root, subroot)<<endl;

    cout<<"Kth ancestor : "<<KthAncistor(root, 1  , 1);
    return 0;
}