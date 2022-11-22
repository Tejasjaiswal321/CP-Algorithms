#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10^9+7
ll nPm(ll n,ll m){
    ll ans=1;
    for(ll i=m-n+1;i<=m;i++){
        ans*=i;
        cout<<ans<<" "<<i<<'\n';
        ans%=mod;
    }
    return ans*(ans-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    cout<<nPm(n,m);
}

