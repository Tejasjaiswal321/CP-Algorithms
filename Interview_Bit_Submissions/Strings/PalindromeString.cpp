/*
    Problem: Palindrome String
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/palindrome-string/

    Time Complexity:  O(n)
    Space Complexity: O(1)

    Author: Tejas Jaiswal

    Problem Description
 
    Given a string, determine if it is a palindrome. While checking for a palindrome, you have to ignore spaces, case, and all special characters; i.e. consider only alphanumeric characters.

    Check the sample test case for reference.
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem


    Problem Constraints
    1 <= |A| <= 106


    Input Format
    The first argument is a string A.


    Output Format
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem


    Example Input
    Input 1:
    "A man, a plan, a canal: Panama"
    Input 2:
    "race a car"


    Example Output
    Output 1:
    1
    Output 2:
    0


    Example Explanation
    Explanation 1:
    The input string after ignoring spaces, and all special characters is "AmanaplanacanalPanama" 
    which is a palindrome after ignoring the case.
    Explanation 2:
    The input string after ignoring spaces, and all special characters is "raceacar" which is not a palindrome


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
    cout<<"DEBUG : "<<T<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}

bool isValidChar(char ch){
    return (ch>='a'&&ch<='z')||(ch>='0'&&ch<='9');
}

int Solution::isPalindrome(string A) {
    int left = 0,right = A.size()-1;
    for(auto &ch:A){
        if(ch>='A'&&ch<='Z'){
            ch+=('a'-'A');
        }
    }
    while(left<right){
        if(!isValidChar(A[left])){
            left++;
        }else if(!isValidChar(A[right])){
            right--;
        }else{
            if(A[left]!=A[right]){
                return 0;
            }
            left++;
            right--;
        }
    }
    return 1;
}
