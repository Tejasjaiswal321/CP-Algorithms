#include <bits/stdc++.h>
#define ll long long
using namespace std;
void topo_dfs(int node, int &v, vector<int> adj[], vector<int> &vis, vector<int> &topo_sort)
{
    vis[node] = 1;
    for (auto &nbr : adj[node])
    {
        if (!vis[nbr])
        {
            topo_dfs(nbr, v, adj, vis, topo_sort);
        }
    }
    topo_sort.push_back(node);
}
void topo_bfs_kahn(int &v, vector<int> adj[], vector<int> &topo_sort)
{
    vector<int> indeg(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
        {
            indeg[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        topo_sort.push_back(front);
        for (auto j : adj[front])
        {
            indeg[j]--;
            if(indeg[j]==0){
                q.push(j);
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
    vector<int> adj[] = {{2}, {3, 4}, {5}, {6}, {}, {4}, {}};
    vector<int> vis(7, 0);
    int v = 7;
    vector<int> topo_sort;
    for (int i = 0; i < 7; i++)
    {
        if (!vis[i])
        {
            topo_dfs(i, v, adj, vis, topo_sort);
        }
    }
    reverse(topo_sort.begin(),topo_sort.end());
    for (auto i : topo_sort)
    {
        cout << i << " > ";
    }
    cout<<"\n";
    vector<int>topo_kahn;
    topo_bfs_kahn(v,adj,topo_kahn);
    for (auto i : topo_kahn)
    {
        cout << i << " > ";
    }

    return 0;
}