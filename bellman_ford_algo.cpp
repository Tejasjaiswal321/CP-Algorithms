#include <bits/stdc++.h>
#define ll long long
using namespace std;
// bellman ford algorithm
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
    vector<int> dist(n + 1, INT_MAX / 2);
    dist[source] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (auto nbr : adj[i])
            {
                if (dist[i] + nbr.second < dist[nbr.first])
                {
                    dist[nbr.first] = dist[i] + nbr.second;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}