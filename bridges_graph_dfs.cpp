//DFS for finding Bridges in Graph algorithm 
//Time Complexity - O(N+E)
//Space Complexity - O(N+E)
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> bridge;
void dfs(int node,int parent,int &t,vector<int> adj[],vector<int>&start_time,vector<int>&lowest_time){
    t++;
    start_time[node]=t;
    lowest_time[node]=t;
    for(auto &nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(start_time[nbr]==-1){
            dfs(nbr,node,t,adj,start_time,lowest_time);
            if(lowest_time[nbr]>start_time[node]){
                bridge.push_back({node,nbr});
            }
        }
        lowest_time[node]=min(lowest_time[node],lowest_time[nbr]);
    }
        
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
    cin >> n;
    int m;
    cin >> m;
    vector<int> adj[n + 1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> start_time(n+1,-1),lowest_time(n+1,INT_MAX);
    int t=0;
    for(int i=1;i<=n;i++){
        if(start_time[i]==-1){
            dfs(i,-1,t,adj,start_time,lowest_time);
        }
    }
    for(auto &b:bridge){
        cout<<b.first<<" --- "<<b.second<<"\n";
    }
}

//Input

// 10
// 10
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
