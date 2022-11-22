#include<bits/stdc++.h>
#define ll long long 
using namespace std;

bool check_dfs_bipartite(int node,int v,vector<int> adj[],vector<int>&color,int c){
    color[node]=c;
    for(auto nbr:adj[node]){
        if(color[nbr]==c){
            return false;
        }
        else if(color[nbr]==-1){
            if(!check_dfs_bipartite(nbr,v,adj,color,1-c)){
                return false;
            }
        }
    }
    return true;
}
bool dfs_colorize_bipartite(int v,vector<int> adj[],vector<int>&color){
    for(auto &i:color){
        i=-1;
    }
    for(int i=1;i<v;i++){
        if(color[i]==-1){
            if(!check_dfs_bipartite(i,v,adj,color,0)){
                return false;
            }
        }

    }    
    return true;
}
bool bfs_colorize_bipartite(int v,vector<int> adj[],vector<int>&color){//color=0,1
    // vector<int> color(v+1,-1);
    for(int i=1;i<=v;i++){
        if(color[i]==-1){
            queue<int> q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto nbr:adj[front]){
                    if(color[nbr]==-1){
                        color[nbr]=(color[front]+1)%2;
                        q.push(nbr);
                    }
                    else if(color[nbr]==color[front]){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int> adj[]={{},{4,2},{3},{5},{1},{2}};
    vector<int> color(6,-1);
    int poss=bfs_colorize_bipartite(5,adj,color);
    if(poss){
        cout<<color.size()<<"\n";
        for(auto &i:color){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"-1\n";
    }
    poss=dfs_colorize_bipartite(5,adj,color);
    if(poss){
        cout<<color.size()<<"\n";
        for(auto &i:color){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"-1\n";
    }
    
    return 0;
}

