//DFS for finding Articulation point in Graph
//Time Complexity - O(N+E)
//Space Complexity - O(N+E)
#include <bits/stdc++.h>
using namespace std;
vector<int> cut_vertex;
void dfs(int node,int parent,int &t,vector<int> adj[],vector<int>&start_time,vector<int>&lowest_time){
    t++;
    start_time[node]=t;
    lowest_time[node]=t;
    int child=0;
    for(auto &nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(start_time[nbr]==-1){
            dfs(nbr,node,t,adj,start_time,lowest_time);
            if(lowest_time[nbr]>=start_time[node]){
                cut_vertex[node]=1;
            }
            child++;
        }
        if(parent==-1&&child>1){
                cut_vertex[node]=1;
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
    cut_vertex.resize(n+1);
    for(int i=1;i<=n;i++){
        if(start_time[i]==-1){
            dfs(i,-1,t,adj,start_time,lowest_time);
        }
    }
    for(int i=1;i<=n;i++){
        if(cut_vertex[i]){
            cout<<i<<"\n";
        }
    }
    return 0;
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
