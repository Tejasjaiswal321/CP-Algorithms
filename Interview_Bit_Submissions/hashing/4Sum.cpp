/*
    Problem: 4 Sum
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/4-sum/

    Time Complexity:  O(n^4)
    Space Complexity: O(n^2)

    Author: Tejas Jaiswal (Editorial interview bit)

    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

    Note:

        Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
        The solution set must not contain duplicate quadruplets.
        Example : 

        Given array S = {1 0 -1 0 -2 2}, and target = 0

        A solution set is:

            (-2, -1, 1, 2)
            (-2,  0, 0, 2)
            (-1,  0, 0, 1)
        Also make sure that the solution set is lexicographically sorted.

        Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
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

// template<class T>
void print(vector<int> arr,string name = ""){
    // cout<<"DEBUG : "<<T<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &A, int B);

};
string makeAns(int a,vector<int> v){
    v.push_back(a);
    sort(v.begin(),v.end());
    string ans;
    for(auto i:v){
        ans+=to_string(i)+"_";
    }
    return ans;
}
vector<int> parseStr(string s){
    vector<int> ans;
    int prevI= 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='_'){
            ans.push_back(stoi(s.substr(prevI,i-prevI+1)));
            prevI = i+1;
        }
    }
    return ans;
}

vector<vector<int> > fourSum1(vector<int> &A, int target) {//doesn't work
    sort(A.begin(),A.end());
    unordered_map<int,vector<vector<int>>> ones,twos,threes;
    unordered_set<string> ans;
    for(int i =0;i<A.size();i++){
        int currNum = A[i];
        int remaining = target-currNum;
        if(threes.find(remaining)!=threes.end()){
            auto arr = threes[remaining];
            for(auto v:arr){
                ans.insert(makeAns(currNum,v));
            }
        }
        for(auto p:twos){
            int sum2 = p.first;
            for(auto v:p.second){
                auto newV(v);
                newV.push_back(currNum);
                int newSum3 = sum2+currNum;
                if( ( newSum3<=target && target>=0 )|| (target<0 && newSum3<0) ){
                    threes[newSum3].push_back(newV);
                }
            }
        }

        for(auto p:ones){
            int sum1 = p.first;
            for(auto v:p.second){
                auto newV(v);
                newV.push_back(currNum);
                int newSum2 = sum1+currNum;
                if( ( newSum2<=target && target>=0 )|| (target<0 && newSum2<0) ){
                    twos[newSum2].push_back(newV);
                }

            }
        }

        if( ( currNum<=target && target>=0 )|| (target<0 && currNum<0) ){

            if(ones.find(currNum)==ones.end() ){
                ones[currNum].push_back({currNum});
            }
        }

    }

    vector<vector<int>> ret;
    for(auto pp:ans){
        
        ret.push_back(parseStr(pp));
    }
    sort(ret.begin(),ret.end());
    return ret;
}


vector<vector<int> > Solution::fourSum(vector<int> &A, int target) {
    sort(A.begin(),A.end());
    unordered_map<int,vector<pair<int,int>>> mp;
    set<vector<int>> ans;
    for(int i=0;i<A.size();i++){
        for(int j = i+1;j<A.size();j++){
            int currSum = A[i]+A[j];
            if(mp.find(target-currSum)!=mp.end()){
                for(auto &pr:mp[target-currSum]){
                    vector<int> v = {pr.first,pr.second,A[i],A[j]};
                    ans.insert(v);
                }
            }
        }
        for(int j=0;j<i;j++){
            int sum =A[i]+A[j];
            mp[sum].push_back({A[j],A[i]});
        }

    }
    return vector<vector<int>>(ans.begin(),ans.end());
}

int main(){
    manageInputOutput();
    vector<int> v = {1,0,0, 0,2, -1, 0, -2, 2};
    // vector<int> v = {9, -8, -10, -7, 7, -8, 2, -7, 4, 7, 0, -3, -4, -5, -1, -4, 5, 8, 1, 9, -2, 5, 10, -5, -7, -1, -6, 4, 1, -5, 3, 8, -4, -10, -9, -3, 10, 0, 7, 9, -8, 10, -9, 7, 8, 0, 6, -6, -7, 6, -4, 2, 0, 10, 1, -2, 5, -2 };
    // vector<int> v = {-100, -100, -100, -100, -100 };
    // vector<int> v = {-1 ,-1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1};
    // vector<int> v = {};
    for(auto v:Solution().fourSum(v,0)){
        print(v);
    }
}




