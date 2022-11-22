#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dfs_topo(int node,int &v,vector<pair<int,int> > adj[],stack<int>&st,vector<int>&vis){
    vis[node]=1;
    for(auto &nbr:adj[node]){
        if(!vis[nbr.first]){
            dfs_topo(nbr.first,v,adj,st,vis);
        }
    }
    st.push(node);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINEJUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<pair<int,int> > adj[] = { {{1, 2}, {4, 1}}, {{2, 3}}, {},{{3, 6}}, {{2, 2}, {5, 4}}, {{3, 1}}};
    vector<int> vis(6, 0);
    int v = 6;
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs_topo(i,v,adj,st,vis);
        }
    }
    int src=0;
    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(dist[top]!=INT_MAX){
            for(auto &nbr:adj[top]){
                if(dist[nbr.first]>dist[top]+nbr.second){
                    dist[nbr.first]=dist[top]+nbr.second;
                }
            }
        }
    }
    for(auto &d:dist){
        cout<<d<<" ";
    }
    return 0;
}