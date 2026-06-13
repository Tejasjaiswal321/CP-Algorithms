/*
    Problem: Yet another string operation problem
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/yet-another-string-operation-problem/

    Time Complexity:  O(n*n)
    Space Complexity: O(n*n)

    Author: Tejas Jaiswal
        
    Problem Description

    You are given two strings, A and B of same length.
    In one operation you can set some A[x] equal to B[x], this cost 1 coin.

    You can also Reverse a substring A[i...j] atmost once. this cost C coins.

    Find minimum operation required to make both string equal.



    Problem Constraints
    1 <= |A| = |B| <= 1000
    A and B consist of lower case alphabets
    0 <= C <= |A|


    Input Format
    First argument of input contains a string A.
    Second argument of input contains a string B.
    Third argument of input contains an integer C.


    Output Format
    Return an integer denoting minimum coins to make strings equal.


    Example Input
    Input 1:
        A = "abceda", B = "bdecbo", C = 1
    Input 2:

        A = "finger", B = "ginger", C = 0


    Example Output
    Output 1:
        3
    Output 2:

        1


    Example Explanation
    Explanation 1:
        Initially we have, A = "abceda"
        set A[0] = B[0], A = "bbceda"
        set A[5] = B[5], A = "bbcedo"
        reverse (1,4),   A = "bdecbo"
    Explanation 2:

        set A[0] = B[0]
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

class Solution{
    public:
    int solve(string A, string B, int C) ;
};

std::string a, b;
vector<vector<vector<int>>>dp;

int solveRec(int i,int j,bool isRev){
    if(i>j){
        return 0;
    }
    if(dp[i][j][isRev]!=-1){
        return dp[i][j][isRev];
    }
    if(isRev){
        int ans = (a[j]!=b[i])+solveRec(i+1,j-1,isRev);
        if(i!=j){
            ans += (a[i]!=b[j]);
        }
        return dp[i][j][isRev] = ans;
    }
    return dp[i][j][isRev] = (a[i]!=b[i])+solveRec(i+1,j,isRev);
}

int Solution::solve(string A, string B, int C) {
    a = A,b=B;
    int size = A.size();
    dp.resize(size);

    for(int i = 0;i<size;i++){
        dp[i].resize(size);
        for(int j = 0;j<size;j++){
            // vector<int> a = {-1};
            dp[i][j].resize(2,-1);
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;


        }
    }

    int ans = 1000;
    for(int i =0;i<size;i++){
        for(int j = i;j<size;j++){
            ans = min(ans,solveRec(0,i-1,false)+solveRec(i,j,true)+solveRec(j+1,size-1,false)+C);
        }
    }
    ans = min(ans,solveRec(0,size-1,false));
    return ans;
}


// int getKey(int i,int j){
//     return i*10000+j;
// }
// int Solution::solve(string A, string B, int C) {//code for multiple reverse allowed
//     unordered_map<int,int>bestAns,revAns;
//     bestAns[getKey(0,0)]=A[0]!=B[0],
//     bestAns[getKey(0,-1)]=0;
//     for(int i =0;i<A.size();i++){
//         revAns[getKey(i,i)] = C+(A[i]!=B[i]);
//     }
//     for(int i = 1;i<A.size();i++){
//         int ans =1000;
//         for(int j=0;j<i;j++){//j+1 to i-1 is already stored for rev
//             revAns[getKey(j+1,i-1)] = max(revAns[getKey(j+1,i-1)],C);
//             revAns[getKey(j,i)]=revAns[getKey(j+1,i-1)]+(A[j]!=B[i])+ (A[i]!=B[j]);
//             ans = min(ans,bestAns[getKey(0,j-1)]+revAns[getKey(j,i)]);
//             // printf("%d + %d +%d +%c + %c %c %c\n",revAns[getKey(j+1,i-1)],(A[j]!=B[i]),(A[i]!=B[j]),A[i],A[j],B[i],B[j]);
//             // printf("j = %d,ans = %d revAns[getKey(%d,%d)] = %d  bestAns[getKey(0,%d)] = %d\n",j,ans,j,i,revAns[getKey(j,i)],j-1,bestAns[getKey(0,j-1)]);
//         }
//         bestAns[getKey(0,i)] = min(ans,bestAns[getKey(0,i-1)]+(A[i]!=B[i]));
//         // printf("A[%d] %d B[i] %d\n",i,A[i],B[i]);
//         // printf("bestAns[getKey(%d,%d)] = %d \n",0,i,bestAns[getKey(0,i)]);
//     }
//     return bestAns[getKey(0,A.size()-1)];
// }



int main(){
    manageInputOutput();
    vector<int> a = {2,3,3,1,1,1,1};
    cout<<Solution().solve("xyzxzzyyxyyxyzzxzxzzyzzxxzzxxy","xxyyzyxyyyzzzxxyzyzxzyzzzxyyzx",2);
}

/**
 * A : "xyzxzzyyxyyxyzzxzxzzyzzxxzzxxy"
 * B : "xxyyzyxyyyzzzxxyzyzxzyzzzxyyzx"
 * C : 2
 * expected 17;
 */