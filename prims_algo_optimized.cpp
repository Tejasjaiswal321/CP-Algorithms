#include <bits/stdc++.h>
#define ll long long
using namespace std;
// bellman ford algorithm
bool comp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b ){
    return a.first>b.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINEJUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 5, source = 1;
    vector<pair<int, int>> adj[n + 1]; // assuming 1 based indexing of graph
    // Constructinadj the adjraph
    adj[1].push_back({2, 4});
    adj[1].push_back({4, 4});
    adj[1].push_back({3,4});
    adj[2].push_back({1, 4});
    adj[2].push_back({5, 4});
    adj[2].push_back({3,3});
    adj[3].push_back({1,4});
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 4});
    adj[3].push_back({5, 4});
    adj[4].push_back({1, 4});
    adj[4].push_back({3, 4});
    adj[5].push_back({2, 4});
    adj[5].push_back({3, 4});
    
    vector<int> mst(n+1),parent(n+1,-1),key(n+1,INT_MAX);
    key[1]=0;
    int vis=0;
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,1});
    while(vis<n){
        vis++;
        int node=pq.top().second;
        while(mst[node]==1){
            pq.pop();
            // cout<<node<<" "<< pq.top().first<<"\n";
            node=pq.top().second;
        }
        // cout<<node<<" "<< pq.top().first<<"\n";
        mst[node]=1;
        pq.pop();
        for(auto &v:adj[node]){
            int nbr=v.first;
            int wt=v.second;
            if(mst[nbr]==0&&wt<key[nbr]){
                key[nbr]=wt;
                pq.push({wt,nbr});
                parent[nbr]=node;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}