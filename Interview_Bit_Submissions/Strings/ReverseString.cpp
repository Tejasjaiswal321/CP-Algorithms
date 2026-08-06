/*
    Problem: Reverse the String
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/reverse-the-string/?study_plan=study-plan-1-week&/
    Time Complexity: O(n)
    Space Complexity: O(n)

    Difficulty : Very Easy

    Problem Description
    You are given a string A of size N.

    Return the string A after reversing the string word by word.

    NOTE:

    A sequence of non-space characters constitutes a word.
    Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
    If there are multiple spaces between words, reduce them to a single space in the reversed string.
    

    Problem Constraints
    1 <= N <= 3 * 105

    Input Format
    The only argument given is string A.

    Output Format
    Return the string A after reversing the string word by word.

    Example Input
    Input 1:
        A = "the sky is blue"
    Input 2:
        A = "this is ib"


    Example Output
    Output 1:
        "blue is sky the"
    Output 2:
        "ib is this"

    Example Explanation
    Explanation 1:
        We reverse the string word by word so the string becomes "the sky is blue".
    Explanation 2:
        We reverse the string word by word so the string becomes "this is ib".
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


vector<string> splitString(string s){
    string curr = "";
    vector<string> ans;
    for(int i = 0;i<s.size();i++){
        if(s[i]==' '){
            if(curr!=""){
                ans.push_back(curr);
                curr = "";
            }
        }else{
            curr+=s[i];
        }
    }
    if(curr!=""){
        ans.push_back(curr);
    }
    return ans;
}

string Solution::solve(string A) {
    string ans = "";
    auto v = splitString(A);
    for(int i = 0;i<v.size();i++){
        ans = v[i] + " " + ans;
    }
    ans.pop_back();
    return ans;
}


int main(){
    manageInputOutput();

}