/*
    Problem: Balanced Parantheses!
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/balanced-parantheses/?study_plan=study-plan-1-week&/
    Time Complexity: O(n)
    Space Complexity: O(n)
    Problem Description

    Given a string A consisting only of '(' and ')'.

    You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



    Problem Constraints
    1 <= |A| <= 105



    Input Format
    First argument is an string A.



    Output Format
    Return 1 if parantheses in string are balanced else return 0.



    Example Input
    Input 1:

    A = "(()())"
    Input 2:

    A = "(()"


    Example Output
    Output 1:

    1
    Output 2:

    0


    Example Explanation
    Explanation 1:

    Given string is balanced so we return 1
    Explanation 2:

    Given string is not balanced so we return 0
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


int Solution::solve(string A) {
    int open = 0;
    for(auto &ch:A){
        if(ch=='('){
            open++;
        }else{
            open--;
            if(open<0){
                return 0;
            }
        }
    }
    return open == 0;
}

int main(){
    manageInputOutput();

}