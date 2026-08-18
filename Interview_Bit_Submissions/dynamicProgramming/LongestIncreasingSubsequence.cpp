/*
    Problem: Longest Increasing Subsequence Length
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/longest-increasing-subsequence/submissions/?study_plan=study-plan-1-week&/
    Time Complexity: O(n Log(n))
    Space Complexity: O(n)
    Problem Description:
    Find the longest increasing subsequence of a given array of integers, A.

    In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible.

    In this case, return the length of the longest increasing subsequence.



    Problem Constraints
    1 <= length(A) <= 2500

    0 <= A[i] <= 2500



    Input Format
    The first and the only argument is an integer array A.



    Output Format
    Return an integer representing the length of the longest increasing subsequence.



    Example Input
    Input 1:

    A = [1, 2, 1, 5]
    Input 2:

    A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]


    Example Output
    Output 1:

    3
    Output 2:

    6


    Example Explanation
    Explanation 1:

    The longest increasing subsequence: [1, 2, 5]
    Explanation 2:

    The possible longest increasing subsequences: [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Common Helper functions
void manageInputOutput(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

template<class T>
void print_vector(vector<T> arr,string name = ""){
    cout<<"print_vector : "<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}
template<class T>
void print_vector(set<T>st){
    cout<<"print_set : "<<": ";
    for(auto &i:st){
        cout<< i <<" ";
    }
     cout<<endl;
}

typedef pair<int,int> pii;

//n*Log(n) solution
int Solution::lis_BEST(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    vector<int> dp;
    for(int i=0;i<n;i++){
        if(dp.empty() || A[i]>dp.back()){
            dp.push_back(A[i]);
        }else{
            dp[lower_bound(dp.begin(),dp.end(),A[i])-dp.begin()]=A[i];
        }
    }
    return dp.size();
}

//n**2 solution
int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n,1);
    int ans = 0;
    if(n>0){ ans = 1; }
    for(int i=1;i<n;i++){
        int currNum = A[i];
        int currAns = 1;
        for(int j =0;j<i;j++){
            if(A[j]<currNum){
                currAns = max(currAns,dp[j]+1);
            }
        }
        ans = max(ans,currAns);
        dp[i]=currAns;
    }
    return ans;
    
}

int main(){
    manageInputOutput();

}