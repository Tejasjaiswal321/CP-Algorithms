//Kosaraju Algorithm in Graph
//Time Complexity - O(N+E)
//Space Complexity - O(N+E)
#include <bits/stdc++.h>
using namespace std;
void kosaraju(vector<int> adj[],vector<vector<int> > &scc,vector<int>&vis,stack<int> topo_sorted){
    queue<int> q;
    int ind=0;
    int n=vis.size()-1;
    while(!topo_sorted.empty()){
        int i=topo_sorted.top();
        topo_sorted.pop();
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
            vector<int> v;
            while(!q.empty()){
                int front=q.front();
                q.pop();
                v.push_back(front);
                for(auto &nbr:adj[front]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=1;
                    }
                }
            }
            scc.push_back(v);
        }
    }
}
void topo_sort(int i,vector<int>adj[],vector<int> &vis,stack<int> &topo_sorted){
    vis[i]=1;
    for(auto &nbr:adj[i]){
        if(!vis[nbr]){
            topo_sort(nbr,adj,vis,topo_sorted);
        }
    }
    topo_sorted.push(i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);//directed edge
    }
    vector<int> vis(n+1);
    stack<int>topo_sorted;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            topo_sort(i,adj,vis,topo_sorted);
        }
    }
    vector<int> rev_adj[n+1];
    for(int i=1;i<=n;i++){
        for(auto &nbr:adj[i]){
            rev_adj[nbr].push_back(i);
        }
    }
    vector<vector<int> > scc;
    for(auto &i:vis){
        i=0;
    }
    kosaraju(rev_adj,scc,vis,topo_sorted);
    for(auto & v:scc){
        for(int node:v){
            cout<<node<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

//Input
// 10
// 12
// 1 2 
// 3 4  
// 2 3 
// 7 6 
// 4 8 
// 3 5 
// 3 6 
// 9 10
// 10 5 
// 3 10 
// 5 3
// 6 9