/*
    Problem: Swap List Nodes in pairs
    Platform: Interview Bit
    Link: https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/?study_plan=study-plan-1-week&/
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    Problem Description
    
    Given a linked list A, swap every two adjacent nodes and return its head.

    NOTE: Your algorithm should use only constant space. You may not modify the values in the list; only nodes themselves can be changed.

    Problem Constraints
    1 <= |A| <= 106 

    Input Format
    The first and the only argument of input contains a pointer to the head of the given linked list. 

    Output Format
    Return a pointer to the head of the modified linked list. 

    Example Input
    Input 1: 

    A = 1 -> 2 -> 3 -> 4
    Input 2: 

    A = 7 -> 2 -> 1

    Example Output
    Output 1: 

    2 -> 1 -> 4 -> 3
    Output 2: 

    2 -> 7 -> 1

    Example Explanation
    Explanation 1:

    In the first example (1, 2) and (3, 4) are the adjacent nodes. Swapping them will result in 2 -> 1 -> 4 -> 3
    Explanation 2:

    In the second example, 3rd element i.e. 1 does not have an adjacent node, so it won't be swapped. 
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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    auto start= new ListNode(-1);
    start->next = A;
    auto prev = start,curr = A,next = A->next;
    while(curr!=NULL && next !=NULL){
        auto nextCurr = next->next;
        prev->next = next;
        next->next = curr;
        curr->next = nextCurr;
        prev = curr;
        curr = curr->next;
        if(curr!=NULL){
            next = curr->next;
        }
        
    }
    return start->next;
}



int main(){
    manageInputOutput();

}