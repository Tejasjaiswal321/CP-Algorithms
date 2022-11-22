#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10 ^ 9 + 7
int phi(int n){//O(sqrt(n))
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ans-=ans/i;
        }
    }
    if(n!=1){
        ans-=ans/n;
    }
    return ans;
}
void phi_1_to_n(int n) {//O(n.log(log(n)))
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
void phi_1_to_n(int n) {//O(nlog(n)) --not best use above one based on formula
//This one -based on gauss established property : Sum{phi(d)}=n.--d is divisor of n
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<int> arr(t);
    while(t--){
        int temp;
        cin>>temp;
        cout<<phi(temp)<<endl;
    }
}
