/*
    Problem: Max Sum Contiguous Subarray
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/?study_plan=study-plan-1-week&/
    Time Complexity: O(n)
    Space Complexity: O(1)
    Problem Description

    Find the contiguous subarray within an array, A of length N which has the largest sum.

    Problem Constraints
    1 <= N <= 106
    -1000 <= A[i] <= 1000

    Input Format
    The first and the only argument contains an integer array, A.

    Output Format
    Return an integer representing the maximum possible sum of the contiguous subarray.


    Example Input
    Input 1:
    A = [1, 2, 3, 4, -10]
    Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

    Example Output
    Output 1:
    10
    Output 2:
    6

    Example Explanation
    Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.
    Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.
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

int Solution::maxSubArray(const vector<int> &A) {
    int lastMaxSum = 0;
    int ans = INT_MIN;
    for(auto&i:A){
        int nextNum = max(i,lastMaxSum+i);
        lastMaxSum = nextNum;
        ans  = max(ans,nextNum);
    }
    return ans;
}


int main(){
    manageInputOutput();

}