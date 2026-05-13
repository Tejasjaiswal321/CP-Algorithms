/*
    Problem: An Increment Problem
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/an-increment-problem/

    Time Complexity:  O(n log(n))
    Space Complexity: O(n)

    Author: Tejas Jaiswal

    Problem Description
    
        Given a stream of numbers A. On arrival of each number, you need to increase its first occurrence by 1 and include this in the stream.
        Return the final stream of numbers.
        Note: You will traverse the stream from left to right and update the first occurrence of the number by 1, if found.

    Problem Constraints
        1 <= |A| <= 100000
        1 <= A[i] <= 10000

    Input Format
        First and only argument is the array A.

    Output Format
        Return an array, the final stream of numbers.

    Example Input
        Input 1: A = [1, 1]
        Input 2: A = [1, 2]
        Input 3: A = [1, 1, 2, 2]
    Example Output
        Output 1:[2, 1]
        

        Output 2: [1, 2]
        
        Output 3: [3, 1, 3, 2]

    Example Explanation
    Explanation 1:
        On arrival of the second element, the other element is increased by 1.

    Explanation 2:
        No increases are to be done.
    
    Explanation 3:
        Stream after arrival of numbers (1-based indexing):
        First number  (1): [1]          , Simply push 1 to the stream
        Second number (1): [2, 1]       , Increment first occurence of 1, present at 1st Index and push 1 to the stream
        Third number  (2): [3, 1, 2]    , Increment first occurence of 2, present at 1st Index and push 2 to the stream
        Fourth number (2): [3, 1, 3, 2] , Increment first occurence of 2, present at 3rd Index and push 2 to the stream

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
    vector<int> solve(vector<int> &A);
};


int main(){
    manageInputOutput();
    
    vector<int> v = { 1, 2, 3, 2, 3, 1, 4, 2, 1, 3 };
    Solution().solve(v);
}

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;
    unordered_map<int,set<int>>mp;
    for(int i=0;i<A.size();i++){
        int num = A[i];
        ans.push_back(num);
        if(mp.find(num)!=mp.end()&&mp[num].size()!=0){
            int firstIndex = *mp[num].begin();
            ans[firstIndex]++;
            mp[num].erase(firstIndex);
            if(mp.find(num+1)==mp.end()){
                mp[num+1]={};
            }
            mp[num+1].insert(firstIndex);
            mp[num].insert(i);
        }else{
            set<int> st = {i};
            mp[num]=st;
        }
        print_vector(ans);
    }
    return ans;
}



