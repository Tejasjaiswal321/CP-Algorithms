#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> dist,parent;
void dijkstra(map<int,int> adj[]){//correct one adj<nbr,wt_to_nbr>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto top=pq.top();
        int node=top.second,d=top.first;
        pq.pop();
        for(auto &pr:adj[node]){
            int nbr=pr.first;
            int wt=pr.second;
            if(wt+d<dist[nbr]){
                parent[nbr]=node;
                dist[nbr]=wt+d;
                pq.push({dist[nbr],nbr});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINEJUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // vector<int> adj[] = {{2}, {3, 4}, {0,5}, {1,6}, {1,5}, {2,4}, {3}};
    // int v=7;
    
	int n=5,m=6,source=1;

    vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
    vector<int> dist(m,INT_MAX);
    vector<int> prev(m,-1);//needs swapping
    dist[source]=0;
    pq.push({source,0});
    while(!pq.empty()){
        pair<int,int> node_dist=pq.top();
        pq.pop();
        if(dist[node_dist.first]==node_dist.second){
            for(auto nbr_wt:g[node_dist.first]){
                if(dist[nbr_wt.first]>node_dist.second+nbr_wt.second){
                    dist[nbr_wt.first]=node_dist.second+nbr_wt.second;
                    pq.push({nbr_wt.first,dist[nbr_wt.first]});
                    prev[nbr_wt.first]=node_dist.first;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"dist["<<i<<"]="<<dist[i]<<"\n";
        cout<<"path : ";
        int node=i;
        // if(node!=source){
        //     cout<<node<<" <- ";
        // }
        while(node!=source){
            cout<<node<<" <- ";
            node=prev[node];
        }
        cout<<source<<"\n\n";
    }
    
}