#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for binary tree
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
    public:
     TreeNode* buildTree(vector<int> &A,vector<int>&B);
};

//Code required for submission

unordered_map<int,int>mp;
vector<int>pre;
TreeNode* solve(int preI,int preJ,int inI,int inJ){
    if(preI>preJ||inI>inJ){
        return NULL;
    }
    auto nodeVal = pre[preI];
    auto node = new TreeNode(nodeVal);
    int index = mp[nodeVal];
    node->left = solve( preI+1, preI+(index-inI), inI,index-1);
    node->right = solve( preI+1+(index-inI),preJ,  index+1,inJ);
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    //1 2 3 4 5 6 7 -pre
    //2 3 4 1 6 5 7 = in
    /*
    1 2 3
    2 1 3
    */
   mp.clear();
   pre.clear();
//    in.clear();
   for(auto &i:A){
       pre.push_back(i);
   }
   for(int i = 0;i<B.size();i++){
    mp[B[i]]=i;
    // in.push_back(B[i]);
   }
    return solve(0,A.size()-1,0,B.size()-1);
}