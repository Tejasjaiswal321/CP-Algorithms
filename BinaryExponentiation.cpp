#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10 ^ 9 + 7
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
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
        cout<<binpow(3,temp,5)<<endl;
    }
}
