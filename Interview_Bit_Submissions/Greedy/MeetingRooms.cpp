/*
    Problem: Meeting rooms
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/meeting-rooms/?study_plan=study-plan-1-week&/
    Time Complexity: O(n(log(n))
    Space Complexity: O(n)

    Problem Description
    
    

    Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

    

    Where:

    

    A[i][0] = start time of the ith meeting.
    A[i][1] = end time of the ith meeting.
    

    Find the minimum number of conference rooms required so that all meetings can be done.

    Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room

    



    Problem Constraints
    1 <= N <= 105

    

    0 <= A[i][0] < A[i][1] <= 2 * 109

    



    Input Format
    The only argument given is the matrix A.



    Output Format
    Return the minimum number of conference rooms required so that all meetings can be done.



    Example Input
    Input 1:

    A = [      [0, 30]
                [5, 10]
                [15, 20]
        ]

    Input 2:

    A =  [     [1, 18]
                [18, 23]
                [15, 29]
                [4, 15]
                [2, 11]
                [5, 13]
        ]


    Example Output
    Output 1:

    2
    Output 2:

    4


    Example Explanation
    Explanation 1:

    Meeting one can be done in conference room 1 form 0 - 30.
    Meeting two can be done in conference room 2 form 5 - 10.
    Meeting three can be done in conference room 2 form 15 - 20 as it is free in this interval.
    Explanation 2:

    Meeting one can be done in conference room 1 from 1 - 18.
    Meeting five can be done in conference room 2 from 2 - 11.
    Meeting four can be done in conference room 3 from 4 - 15.
    Meeting six can be done in conference room 4 from 5 - 13.
    Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
    Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.
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

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end());
    int ans = 0;
    multiset<int> endTimes ;
    for(auto &v:A){
        int start = v[0],end = v[1];
    
        while(!endTimes.empty()&&(*endTimes.begin())<=start){
            endTimes.erase(endTimes.begin());
        }
        endTimes.insert(end);
        ans =max(ans,(int)endTimes.size());
    }
    return ans;
}

int main(){
    manageInputOutput();

}