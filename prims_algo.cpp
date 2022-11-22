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
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({5, 5});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});
    adj[3].push_back({4, 3});
    adj[3].push_back({5, 1});
    adj[4].push_back({1, 1});
    adj[4].push_back({3, 3});
    adj[5].push_back({2, 5});
    adj[5].push_back({3, 1});
    
    vector<int> mst(n+1),parent(n+1,-1),key(n+1,INT_MAX);
    key[1]=0;
    int vis=0;
    // while(vis<n){
    //     vis++;
    //     int least=-1;
    //     for(int i=1;i<=n;i++){
    //         if(mst[i]==0&&(least==-1||key[least]>key[i])){
    //             least=i;
    //         }
    //     }
    //     mst[least]=1;
    //     for(auto &node:adj[least]){
    //         int nbr=node.first;
    //         int wt=node.second;
    //         if(mst[nbr]==0&&wt<key[nbr]){
    //             key[nbr]=wt;
    //             parent[nbr]=least;
    //         }
    //     }
    // }
    // vis=1;
    // queue<int> q;
    // q.push(1);
    int node=1,ans=-1;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int> >> > pq;
    do{
        vis++;
        for(auto &v:adj[node]){
            if(mst[v.first]==0){
                pq.push({v.second,{v.first,node}});
            }
        }
        mst[node]=1;
        parent[node]=ans;
        if(vis<n){
            auto top=pq.top();
            pq.pop();
            ans=top.second.second;
            node=top.second.first;
        }
    }while(vis<n);
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}