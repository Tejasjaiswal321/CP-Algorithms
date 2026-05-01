#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
    int lca(TreeNode* A, int b, int c) ;
};

unordered_map<int,vector<int>> ancestorMap;
vector<int> depthArr;
int mapsize = 1e8;
void initAncestorMap(TreeNode* node,int parent,int depth){
    if(node==NULL){
        // printf("initAncestorMap : parent = %d NULL \n",parent);
        return;
    }
    auto ancestors = vector<int>(log(mapsize)+1,-1);
    ancestors[0]=parent;
    auto nodeVal = node->val;
    // printf("init : nV = %d \n",nodeVal);
    // cout<<nodeVal<<endl;
    // printf("initAncestorMap : nodeVal = %d\n",nodeVal);

    depthArr[nodeVal]=depth;

    ancestorMap[nodeVal] = ancestors;
    initAncestorMap(node->left,nodeVal,depth+1);
    initAncestorMap(node->right,nodeVal,depth+1);
}
void computeAllParents(){
    for(auto index = 1;index < log(mapsize)+1;index++){
        for(auto &p:ancestorMap){
            auto nodeVal = p.first;
            auto ancestors = p.second;
            auto firstAncestor = ancestors[index-1];
            ancestors[index] = ancestorMap[firstAncestor][index-1];
        }
        cout<<index<<"\n";


    }
}

int getIthParent(int node,int steps){
    int nextStep = mapsize;

    for(int index = log(mapsize) ; index>=0 ; index--){
        if(nextStep<=steps){
            steps-=nextStep;
            node = ancestorMap[node][index];
        }
        printf("getIthParent : node = %d steps=%d",node,steps);
        nextStep>>=1;
    }
    return node;
}
int findLCA(int a,int b){
    if(ancestorMap.find(a)==ancestorMap.end() || ancestorMap.find(b)==ancestorMap.end()){
        return -1;
    }
    auto diff = depthArr[b]-depthArr[a];
    if(diff<0){
        swap(a,b);
        diff = -diff;
    }
    
    b = getIthParent(b,diff);
    int nextStep = mapsize;
    int index = log(mapsize);
    printf("a=%d b=%d nextStep=%d index=%d",a,b,nextStep,index);
    while(b!=a){
        auto newA = ancestorMap[a][index];
        auto newB = ancestorMap[b][index];
        if(newA!=newB){
            a = newA;
            b = newB;
        }
        nextStep>>=1;
        index--;
    }
    return ancestorMap[b][0];
}
int Solution::lca(TreeNode* A, int b, int c) {
    ancestorMap.clear();
    depthArr.clear();
    depthArr.resize(mapsize);
    ancestorMap[-1] = vector<int>(log(mapsize)+1,-1);//base case to simplify traversal
    //initialize and put 1st parent for all nodes using 1 traversal;
    initAncestorMap(A,-1,0);
    // printf("initAncestorMap");
    cout<<"init end\n";
    computeAllParents();
    cout<<"computeAllParents\n";
    return findLCA(b,c);
}

int main(){

}
/**
 73 15 20 34 35 5 14 16 26 -1 25 23 -1 30 3 36 -1 -1 7 24 11 32 -1 -1 21 -1 -1 -1 29 4 9 -1 33 13 -1 -1 -1 -1 22 31 -1 27 19 1 -1 12 18 6 -1 -1 -1 2 -1 -1 -1 -1 10 -1 -1 -1 -1 8 -1 28 -1 -1 -1 -1 -1 17 -1 -1 -1 -1
33
5

 */