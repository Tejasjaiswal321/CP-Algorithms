/*
    Problem: Remove Duplicates from Sorted Array
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/?study_plan=study-plan-1-week&/
    Time Complexity: O(n)
    Space Complexity: O(1)
    Problem Description
 
    Given a sorted array A consisting of duplicate elements.

    Your task is to remove all the duplicates and return the length of the sorted array of distinct elements consisting of all distinct elements present in A.

    Note: You need to update the elements of array A by removing all the duplicates

    Problem Constraints
    1 <= |A| <= 106
    1 <= Ai <= 2 * 109

    Input Format
    First and only argurment containing the integer array A.

    Output Format
    Return a single integer, as per the problem given.

    Example Input
    Input 1:

    A = [1, 1, 2]
    Input 2:

    A = [1, 2, 2, 3, 3]

    Example Output
    Output 1:
    2

    Output 2:
    3

    Example Explanation
    Explanation 1:

    Updated Array: [1, 2, X] after rearranging. Note that there could be any number in place of x since we dont need it.
    We return 2 here.
    Explanation 2:

    Updated Array: [1, 2, 3, X, X] after rearranging duplicates of 2 and 3.
    We return 3 from here.
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


int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int left = 0;
    for(int right = 1;right<n;right++){
        if(A[left]!=A[right]){
            A[left+1]=A[right];
            left++;
        }
    }
    return left+1;
}



int main(){
    manageInputOutput();

}