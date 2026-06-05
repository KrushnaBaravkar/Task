void topView(Node*root){
//     queue<pair<Node*, int>> Q; // pair(Node ptr, Horozontal_distance)
//     map<int, int> m; // (horozonatl_diatance, currNode->data)

//     Q.push(make_pair(root, 0));
//     while(!Q.empty()){
//         pair<Node*, int> currPair = Q.front();
//         Node* currNode = currPair.first;
//         int currHD = currPair.second;

//         if(m.count(currHD) == 0){  // count for HD = 0 then add that uniquely visable node from the above.
//             m[currHD] = currNode->data;
//         }

//         if(currNode->left !=  NULL){
//             pair<Node*, int> left = make_pair(currNode->left, currHD - 1);
//             Q.push(left);
//         }
//         if(currNode->right !=  NULL){
//             pair<Node*, int> right = make_pair(currNode->right, currHD + 1);
//             Q.push(right);
//         }
//     }
//     for(auto it : m){
//         cout<<it.second<<" ";
//     }
//     cout<<endl;
// } 