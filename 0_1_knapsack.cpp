// 0/1 knapsack problem
// Time Complexity = O(n*w)
// Space Complexity = O(n*w)
// for both recursive and iterative but recursive may cause stack overflow in some questions
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
static int dp[101][101];
int cnt = 0;
int rec_knapsack(vector<int> &val, vector<int> &wt, int w, int n)
{
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        // cnt++;
        cout << n << " " << w << "\n";
        return dp[n][w];
    }
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max(val[n - 1] + rec_knapsack(val, wt, w - wt[n - 1], n - 1), rec_knapsack(val, wt, w, n - 1));
    }
    return dp[n][w] = rec_knapsack(val, wt, w, n - 1);
}
int itr_knapsack(vector<int> &val, vector<int> &wt, int w, int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> val = {1, 4, 3, 2, 3, 4, 5, 6, 7, 23}, wt = {3, 14, 6, 7, 1, 13, 8, 9, 7, 2};
    int n = 10;
    int w = 50;
    memset(dp, -1, sizeof(dp));
    cout << itr_knapsack(val, wt, w, n);
    // memset(a,-1,sizeof(a));
    return 0;
}
