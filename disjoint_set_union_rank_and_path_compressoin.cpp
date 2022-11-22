#include <bits/stdc++.h>
#define ll long long
using namespace std;
std::vector<int> parent,ranks;
void makeSet(int n){
    parent.resize(n);
    ranks.resize(n);//no need of rank matrix as benefit is not reflected in TC();
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int findPar(int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=findPar(parent[u]);
}
int Union(int u,int v){
    int pu=findPar(u);
    int pv=findPar(v);
    if(ranks[pu]>ranks[pv]){
        parent[pv]=pu;
    }
    else if(ranks[pu]<ranks[pv]){
        parent[pu]=pv;
    }
    else{
        parent[pu]=pv;
        ranks[pv]++;
    }
    return 1;
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
#ifndef ONLINEJUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n=10;
    makeSet(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    if(findPar(1)==findPar(4)){
        cout<<"Same Parent";
    }
    else {
        cout<<"Different Parent";
    }
    return 0;
}