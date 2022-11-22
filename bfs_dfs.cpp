#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> bfsofgraph(int n,vector<int> adj[]){
    vector<int>bfs,vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){//bfs called on the component
                int front=q.front();
                bfs.push_back(front);
                q.pop();
                for(auto &nbr:adj[front]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=1;
                    }
                }
            }
        }
    }
    return bfs;
}
void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&storeDfs){
    storeDfs.push_back(node);
    vis[node]=1;
    for(auto &i:adj[node]){
        if(!vis[i]){
            dfs(i,adj,vis,storeDfs);
        }
    }
}
vector<int> dfsofgraph(int n,vector<int> adj[]){
    vector<int>vis(n+1,0),storeDfs;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,storeDfs);
        }
    }
    return storeDfs;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> adj[]={{},{3,4},{5},{2},{3},{3}};
    auto bfs=bfsofgraph(5,adj);
    auto dfs=dfsofgraph(5,adj);
    for(auto &i:bfs){
        cout<<i<<"\n";
    }
    cout<<"\n";
    for(auto &i:dfs){
        cout<<i<<"\n";
    }
    return 0;
}
