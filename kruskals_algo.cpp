//Kruskal's algorithm 
//Time Complexity - O(E*log(E))
//Space Complexity - O(E+N)
#include <bits/stdc++.h>
using namespace std;
vector<int> ranks, parent;
void setDis(int n)
{
    ranks.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
void Union(int u, int v)
{
    int pu = parent[u], pv = parent[v];
    if (pu != pv)
    {
        if (ranks[pu] < ranks[pv])
        {
            parent[pu] = pv;
        }
        else if (ranks[pu] > ranks[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            ranks[pv]++;
        }
    }
}
int findRoot(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = findRoot(parent[v]);
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
    setDis(n);
    int m;
    cin >> m;
    vector<pair<int, int>> adj_mst[n + 1];
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({wt, {a, b}});
    }
    sort(edges.begin(), edges.end());
    int cost=0;

    for (auto &e : edges)
    {
        int wt = e.first,
            a = e.second.first,
            b = e.second.second;
        int pa = findRoot(a), pb = findRoot(b);
        if (pa != pb)
        {
            Union(a, b);
            adj_mst[a].push_back({b, wt});
            adj_mst[b].push_back({a, wt});
            cost+=wt;
            cout<<a<<" -- "<<b<<" ( "<<wt<<" )\n";
        }
    }
    cout<<"MST cost = "<<cost;

}

//Input

// 10
// 10
// 1 2 1
// 3 4 3 
// 2 3 4
// 7 6 4
// 4 8 2
// 3 5 1
// 3 6 3
// 9 10 1
// 10 5 3
// 3 10 3

//Output
// 1 -- 2 ( 1 )
// 3 -- 5 ( 1 )
// 9 -- 10 ( 1 )
// 4 -- 8 ( 2 )
// 3 -- 4 ( 3 )
// 3 -- 6 ( 3 )
// 3 -- 10 ( 3 )
// 2 -- 3 ( 4 )
// 7 -- 6 ( 4 )
// MST cost = 22