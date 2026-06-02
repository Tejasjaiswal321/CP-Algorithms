/*
    Problem: Maximum Sum Combinations
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/maximum-sum-combinations/

    Time Complexity:  O(n*log(n))
    Space Complexity: O(n)

    Author: Tejas Jaiswal

    Problem Description:
        Given two equally sized 1-D arrays A, B containing N integers each.
        A sum combination is made by adding one element from array A and another element of array B.
        Return the maximum C valid sum combinations from all the possible sum combinations.

    Problem Constraints:
        1 <= N <= 105
        1 <= A[i] <= 105
        1 <= C <= N

    Input Format
        First argument is an one-dimensional integer array A of size N.
        Second argument is an one-dimensional integer array B of size N.
        Third argument is an integer C.

    Output Format
        Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.
        NOTE: The returned array must be sorted in non-increasing order.

    Example Input
    Input 1:
        A = [3, 2]
        B = [1, 4]
        C = 2

    Input 2:
        A = [1, 4, 2, 3]
        B = [2, 5, 1, 6]
        C = 4

    Example Output
    
        Output 1: [7, 6]
        Output 2: [10, 9, 9, 8]

    Example Explanation
    
        Explanation 1:
            7     (A : 3) + (B : 4)
            6     (A : 2) + (B : 4)

        Explanation 2:
            10   (A : 4) + (B : 6)
            9   (A : 4) + (B : 5)
            9   (A : 3) + (B : 6)
            8   (A : 3) + (B : 5)
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
void print(vector<T> arr,string name = ""){
    cout<<"DEBUG : "<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}

class Solution{
    public:
    vector<int> solve(vector<int> &A, vector<int> &B, int C);
};

int main(){
    manageInputOutput();
    vector<int> A= { 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83 },
        B = { 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83 };
    int C = 10;
    print(Solution().solve(A,B,C));
    
}
typedef  pair<int,pair<int,int>> pipii;

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int size = A.size();
    vector<int> ans ;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pipii> pqLeft,pqRight;
    for(int i =0;i<size;i++){
        pqLeft.push({A[i]+B[i],{i,i}});
    }
    for(int i =0;i<size-1;i++){
        pqRight.push({A[i]+B[i+1],{i,i+1}});
    }
    while(ans.size()<C){
        auto [leftVal, leftIJ] = pqLeft.top();
        auto [leftI,leftJ] = leftIJ;
        auto [rightVal, rightIJ] = pqRight.top();
        auto [rightI,rightJ] = rightIJ;

        if(leftVal>=rightVal){
            // printf("A: %d {%d,%d} %d {%d,%d}\n",leftVal,leftI,leftJ,rightVal,rightI,rightJ);
            ans.push_back(leftVal);
            pqLeft.pop();
            if(leftJ-1>=0){
                pqLeft.push({A[leftI]+B[leftJ-1],{leftI,leftJ-1}});
            }
        }else{
            // printf("B: %d {%d,%d} %d {%d,%d}\n",leftVal,leftI,leftJ,rightVal,rightI,rightJ);
            ans.push_back(rightVal);
            pqRight.pop();
            if(rightI-1>=0){
                pqRight.push({A[rightI-1]+B[rightJ],{rightI-1,rightJ}});
            }
        }
        // printf("%d %d %d \n",pqLeft.top().first,pqRight.top().first);
    }
    return ans;
}
