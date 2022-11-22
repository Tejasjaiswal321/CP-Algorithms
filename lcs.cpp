#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void trace(vector<vector<int> >&dp,int i,int j,vector<string> &ans,string &a,string &b){
    vector<string> aux_ans;
    //trace lcs
    while(dp[i][j]!=0){
        if(a[i-1]==b[j-1]){
            for(auto &str:ans){
                str.push_back(a[i-1]);
            }
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        
        else if(dp[i-1][j]<dp[i][j-1]){
            j--;
        }
        else if(a[i-2]==b[j-1]&&a[i-1]==b[j-2]){
            aux_ans=ans;
            trace(dp,i-1,j,ans,a,b);
            trace(dp,i,j-1,aux_ans,a,b);
            ans.insert(ans.end(),aux_ans.begin(),aux_ans.end());
            // return ans;
            // for(auto &a:ans){
            //     a.push_back(b[j]);
            // }
            // for(auto &a:aux_ans){
            //     a.push_back(a[i]);
            // }
            return;
        }
        else{
            i--;
            j--;
        }
    }
}
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
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
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

    cout<<dp[m][n];
    vector<string> ans;
    ans.push_back("");
    int i=m,j=n;
    trace(dp,i,j,ans,a,b);
    cout<<"\n";
    for(auto &s:ans){
        cout<<s<<" ";
    }
    return 0;
}