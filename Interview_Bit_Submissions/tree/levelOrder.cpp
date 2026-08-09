/*
    Problem: Level Order
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/level-order/
    https://www.interviewbit.com/problems/level-order/submissions/?study_plan=study-plan-1-week&/

    Time Complexity:  O(n)
    Space Complexity: O(n)

    Author: Tejas Jaiswal
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Common Helper functions
void manageInputOutput(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

template<class T>
void print_vector(vector<T> arr,string name = ""){
    cout<<"print_vector : "<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}

class TreeNode{
    public:
    int val;
    TreeNode * left,*right;
    TreeNode(int newVal) {
        val = newVal;
    }
};

class Solution {
    public:
    vector<vector<int> > levelOrder(TreeNode* A) ;
};

vector<vector<int> > ans;

void solve(vector<TreeNode*> vt){
    vector<TreeNode*> vtNext;
    vector<int> v;
    for(auto node :vt){
        if(node!=NULL){
            v.push_back(node->val);
            vtNext.push_back(node->left);
            vtNext.push_back(node->right);
        }
    }
    if(vtNext.empty()){
        return;
    }
    ans.push_back(v);
    solve(vtNext);
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    ans.clear();
    solve({A});
    return ans;
}



vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ans = {{A->val}};
    vector<TreeNode*> nodeArr = {A},nextNodeArr;
    vector<int> levelAns;
    while(!nodeArr.empty()){
        levelAns.clear();
        nextNodeArr.clear();
        for(auto &node:nodeArr){
            TreeNode* left = node->left,*right = node->right;
            if(left!=NULL){
                nextNodeArr.push_back(left);
                levelAns.push_back(left->val);
            }
            if(right!=NULL){
                nextNodeArr.push_back(right);
                levelAns.push_back(right->val);
            }
        
        }
        if(!levelAns.empty()){
            ans.push_back(levelAns);
        }
        nodeArr = nextNodeArr;
    }
    return ans;
}

int main(){
    manageInputOutput();
    //Write driver code here
}

//Code for submission



