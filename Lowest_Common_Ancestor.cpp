#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>up;
vector<int> depth;
int lca(int u,int v,int logn){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff=depth[u]-depth[v];
    for(int k=logn-1;k>=0;k--){
        if((1<<k)<=diff){
            diff-=1<<k;
            u=up[u][k];
        }
    }
    if(u==v){
        return u;
    }
    for(int k=logn-1;k>=0;k--){
        // int jump=(1<<k);
        if(up[u][k]!=up[v][k]){
            u=up[u][k];
            v=up[v][k];
        }
    }
    return up[u][0];
}
int dfs(int node){
    if(node==0){
        return 0;
    }
    if(depth[node]==0){
        depth[node]=dfs(up[node][0])+1;
    }
    return depth[node];
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
    // int x=0;
    // while(1<<x<=n){
    //     x++;
    // }
    depth.resize(n);
    int logn = (int)log2(n) + 1;
    // int up[n][logn];
    vector<int> row(logn);
    for(int i=0;i<n;i++){
        up.push_back(row);
    }
    for (int i = 0; i < n; i++)
    {
        int child, temp;
        cin >> child;
        while (child--)
        {
            cin >> temp;
            // depth[temp]=depth[i]+1;
            up[temp][0] = i;
        }
    }
    for(int i=1;i<n;i++){
        if(!depth[i]){
            dfs(i);
        }
    }
    up[0][0] = 0;
    // tree formed as child[parent];
    for (int k = 1; k < logn; k++)
    {
        for (int i = 0; i < n; i++)
        {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v,logn)<<"\n";
    }

}