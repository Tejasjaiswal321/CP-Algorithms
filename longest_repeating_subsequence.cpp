//longest repeating subsequence without taking any element twice
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = b.size();
    vector<vector<int> > dp(m + 1,vector<int>(n+1,-1));
    // int dp[m+1][n+1];
    // memset(dp, -1, sizeof(dp));
    int vis=-1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]&&i!=j)
            {
                // vis=max(i,j);
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    // for(auto &r:dp){
    //     for(auto&c:r){
    //         cout<<c<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}