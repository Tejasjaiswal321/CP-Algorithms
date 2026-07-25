/*
    Problem: Reverse Alternate K Nodes

    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

    Time Complexity:  O(n)
    Space Complexity: O(1)

    Author: Tejas Jaiswal

    Problem Description

    Given a linked list A of length N and an integer B.

    You need to reverse every alternate B nodes in the linked list A.



    Problem Constraints
    1 <= N <= 105
    1<= Value in Each Link List Node <= 103
    1 <= B <= N
    N is divisible by B


    Input Format
    First argument is the head pointer of the linkedlist A.

    Second argument is an integer B.



    Output Format
    Return the head pointer of the final linkedlist as described.



    Example Input
    Input 1:

    A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
    B = 3
    Input 2:

    A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
    B = 2


    Example Output
    Output 1:

    7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
    Output 2:

    4 -> 1 -> 6 -> 6 -> 10 -> 4


    Example Explanation
    Explanation 1:

    The linked list contains 9 nodes and we need to reverse alternate 3 nodes.
    First sublist of length 3  is 3 -> 4 -> 7 so on reversing it we get 7 -> 4 -> 3.
    Second sublist of length 3 is 5 -> 6 -> 6 we don't need to reverse it.
    Third sublist of length 3 is 15 -> 61 -> 16 so on reversing it we get 16 -> 61 -> 15.
    Explanation 2:

    The linked list contains 6 nodes and we need to reverse alternate 2 nodes.
    First sublist of length 2 is 1 -> 4 so on reversing it we get 4 -> 1.
    Second sublist of length 2 is 6 -> 6 we don't need to reverse it.
    Third sublist of length 2 is 4 -> 10 so on reversing it we get 10 -> 4.
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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseNext(ListNode* node,int B){
    auto start = node;
    ListNode* first = node->next,*current = node->next,*next,*prev = NULL;
    for(int i = 0;i<B;i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first->next = next;
    start->next = prev;
    return first;
}

ListNode* advanceByB(ListNode* node,int B){
    for(int i = 0;i<B;i++){
        node = node->next;
    }
    return node;
}

ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* start = new ListNode(-1),*ans = start;
    start->next = A;
    start = reverseNext(start,B);
    ans = ans->next;
    bool skip = false;
    while(start->next!=NULL){
        if(skip){
            start = reverseNext(start,B);
        }else{
            start = advanceByB(start,B);
        }
        skip = !skip;
    }
    
    return ans;
}




