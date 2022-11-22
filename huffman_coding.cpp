#include <bits/stdc++.h>
#define pin pair<int,node*>
using namespace std;
struct node{
  int val;
  int symbol;
  // char data;
  // int freq;
  node* left=0,*right=0;
  node(int val,int s){
    this->val=val;
    symbol=s;
    left=0;
    right=0;
  }
};

map<int,string> code;
void assign_dfs(node*tree,string s){
  if(tree->left==0&&tree->right==0){
    code[tree->symbol]=s;
    // cout<<tree->symbol<<" "<<s<<"\n";
    return;
  }
  if(tree->left!=0){
    assign_dfs(tree->left,s+"0");
  }
  if(tree->right!=0){
    assign_dfs(tree->right,s+"1");
  }
}
// struct minheap{
//   int size;
//   int cap;
//   minheap
// }
priority_queue<pin,vector<pin>,greater<pin>> pq;
node *maketree(){
  while(pq.size()>1){
    auto a=pq.top().second;
    pq.pop();
    auto b=pq.top().second;
    pq.pop();
    node* nn=new node({a->val+b->val,-1});
    if(a->val<=b->val){
      nn->left=a;
      nn->right=b;
    }
    else{
      nn->left=b;
      nn->right=a;
    }
    pq.push({nn->val,nn});
  }
  return pq.top().second;
}
void solve(){
  if(pq.size()>=1){
    auto tree=maketree();
    assign_dfs(tree,"");
  }
  else if(pq.size()==1){
    code[pq.top().second->symbol]="0";
  }
  for(int i=0;i<10;i++){
    cout<<i<<" ";
    if(code[i].size()<1){
      cout<<"null\n";
    }
    else{
      cout<<code[i]<<"\n";
    }
  }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  string s;
  cin>>s;//input the string
  int count[10]={0};
  for(auto &c:s){
    count[c-'0']++;
  }
  for(int i=0;i<=9;i++){
    if(count[i]>0){
    //   cout<<i<<" "<<count[i]<<"\n";
      pq.push({count[i],new node(count[i],i)});
    }
  }
  solve();
  return 0;
}
//input is string of msg - 1751709618360459813571045
//output huffman coding for each digit if present else "null"