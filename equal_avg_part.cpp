#include <bits/stdc++.h>
using namespace std;


int min_selected_size = INT_MAX, n, sum, selected;
vector<int> to_be_ans, s1;
void check_update(vector<int> cand)
{ // also sort vector
    // part_s1=cand; ----- to be updated for best
    sort(cand.begin(), cand.end());
    if (cand.size() > min_selected_size)
    {
        return;
    }
    if (cand.size() < min_selected_size)
    {
        min_selected_size = cand.size();
        s1 = cand;
        return;
        // part_s1=v;
    }
    
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] > cand[i])
        {
            s1 = cand;
            // part_s1=v;
            return;
        }
        else if(s1[i]<cand[i]){
            return;
        }
    }
}
vector<int> lexically_smaller(vector<int> a,vector<int>b){
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            return b;
        }
        else if(a[i]<b[i]){
            return a;
        }
    }
    return a;
    
}
pair<int, vector<int>> knapsack(vector<int> &A, int i, int j, int k, vector<vector<vector<int>>> &dp, vector<vector<vector<vector<int>>>> &part_s1)
{
    // isPossbile , selected  items if isPossbile
    pair<int, vector<int>> inc, not_inc;
    // for(int j=0;j<=w;j++){//sum required from s1
    if (k > i)
    { // select more out of less
        dp[i][j][k] = 0;
        return {0,vector<int>(0)};
    }
    else if (j > 0 && k == 0)
    { // non zero sum for 0 to be selected
        dp[i][j][k] = 0;
        return {0,vector<int>(0)};  
    }
    else if (k == 0 && j == 0)
    { // sum=0&&to be selected =0
        dp[i][j][k] = 1;
        return {1,vector<int>(0)};
    }
    else if (dp[i][j][k] != -1)
    {
        return {dp[i][j][k], part_s1[i][j][k]};
    }
    else if (A[i - 1] <= j)
    {
        // select
        vector<int> v;
        selected++;
        to_be_ans.push_back(A[i - 1]);
        inc = knapsack(A, i - 1, j - A[i - 1], k - 1, dp, part_s1);
        if(inc.first){
            inc.second.push_back(A[i-1]);
        }
        sort(inc.second.begin(),inc.second.end());
        // if (inc.first)
        // {
        //     v = to_be_ans;
        //     v.insert(v.end(), inc.second.begin(), inc.second.end());
        //     check_update(v);
        // }

        // if(inc.first<min_selected_size){
        //     min_selected_size=inc.first;
        //     v=to_be_ans;
        //     v.insert(v.end(),inc.second.begin(),inc.second.end());
        //     s1=v;
        // }
        selected--;
        to_be_ans.pop_back();
        not_inc = knapsack(A, i - 1, j, k, dp, part_s1);
        sort(not_inc.second.begin(),not_inc.second.end());
        dp[i][j][k] = inc.first || not_inc.first;
        vector<int> a = inc.second, b = not_inc.second;
        if (dp[i][j][k])
        {
            if (inc.first == not_inc.first)
            {
                part_s1[i][j][k] = lexically_smaller(a, b);
            }
            else
            {
                if (inc.first == false)
                {
                    swap(a, b);
                }
                part_s1[i][j][k] = a;
            }
        }
        if (dp[i][j][k])
        {
            v = to_be_ans;
            v.insert(v.end(), part_s1[i][j][k].begin(), part_s1[i][j][k].end());
            check_update(v);
        }
        // if(not_inc.first<min_selected_size){
        //     min_selected_size=not_inc.first;
        //     v=to_be_ans;
        //     v.insert(v.end(),not_inc.second.begin(),not_inc.second.end());
        //     s1=v;
        // }
    }
    else
    {
        not_inc = knapsack(A, i - 1, j, k, dp, part_s1);
        dp[i][j][k] = not_inc.first;
        if (dp[i][j][k])
        {
            //update local answer
            part_s1[i][j][k] = not_inc.second;
            //update gloabal answer
            
            vector<int> v;
            v = to_be_ans;
            v.insert(v.end(), part_s1[i][j][k].begin(), part_s1[i][j][k].end());
            check_update(v);
            
        }
    }
    return {dp[i][j][k], part_s1[i][j][k]};
}
vector<vector<int>> avgset(vector<int> &A)
{
    sort(A.begin(), A.end());
    to_be_ans.clear();
    s1.clear();
    min_selected_size = INT_MAX;
    n = A.size();
    sum = 0;
    selected = 0;
    for (auto &i : A)
    {
        sum += i;
    }
    vector<vector<int>> ans(2, vector<int>(0));
    // bool dp[n+1][sum+1][n];//items in set ,sum required, no. of items to be selected
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(sum + 1, vector<int>(n, -1)));
    vector<vector<vector<vector<int>>>> part_s1(n + 1, vector<vector<vector<int>>>(sum + 1, vector<vector<int>>(n, vector<int>(0))));
    // memset(dp,0,sizeof(dp));
    for (int k = 1; k < n; k++)
    {
        if (sum * k % n != 0)
        {
            continue;
        }
        int w = sum * k / n;
        knapsack(A, n, w, k, dp, part_s1);
        if (dp[n][w][k] == 1)
        {
            // ans[0] = part_s1[n][w][k];
            ans[0] = s1;
            int it1 = 0, it2 = 0;
            while (it1 < ans[0].size() && it2 < A.size())
            {
                if (ans[0][it1] == A[it2])
                {
                    it1++;
                    it2++;
                }
                else
                {
                    ans[1].push_back(A[it2]);
                    it2++;
                }
            }
            while (it2 < A.size())
            {
                ans[1].push_back(A[it2]);
                it2++;
            }
            return ans;
        }
    }
    return ans; // check for no answer
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> A(n);
    
    for (auto &i : A)
    {
        cin >> i;
    }
    auto ans = avgset(A);
    cout << "ans\n";

    for (auto &r : ans)
    {
        for (auto &v : r)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}