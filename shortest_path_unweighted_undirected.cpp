#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> shortestPath(int source,int v,vector<int> adj[]){
    vector<int> len(v,INT_MAX);
    queue<int> q;
    len[source]=0;
    q.push(source);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto nbr:adj[front]){
            if(len[front]+1<len[nbr]){
                len[nbr]=len[front]+1;
                q.push(nbr);
            }
        }
    }
    return len;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINEJUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> adj[] = {{2}, {3, 4}, {0,5}, {1,6}, {1,5}, {2,4}, {3}};
    int v=7;
    vector<int>len=shortestPath(0,v,adj);
    for(auto i:len){
        cout<<i<<' ';
    }
    return 0;
}