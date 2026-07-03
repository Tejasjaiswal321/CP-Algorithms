/*
    Problem: Replace With Factors!
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/replace-with-factors/

    Time Complexity:  O(n)
    Space Complexity: O(1)

    Author: Tejas Jaiswal

    Problem Description

        Rishabh has given you a linked list in the form of its head node A. He has also given you an integer B.

        You need to change the value of each node to its nearest multiple of B that is <= current value.



    Problem Constraints
        1 <= size of list <= 105

        1 <= value of each node <= 105

        1 <= B <= 105



        Input Format
        First argument is the head pointer of linked list A.

        Second argument is the integer B.



        Output Format
        Return the head of the changed linked list.



        Example Input
        Input 1:

        A = 1 -> 2 -> 3
        B = 2
        Input 2:

        A = 3 -> 4 -> 5
        B = 3


        Example Output
        Output 1:

        0 -> 2 -> 2
        Output 2:

        3 -> 3 -> 3


        Example Explanation
        Explanation 1:

        All numbers have been replaced by nearest multiples of 2.
        Explanation 2:

        All numbers have been replaced by nearest multiples of 3.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution{
    public:
        ListNode* Solution::solve(ListNode* A, int B);
};


ListNode* Solution::solve(ListNode* A, int B) {
    auto node= A;
    while(node!=NULL){
        node->val = (node->val/B*B);
        node=node->next;
    }
    return A;
}


int main(){
    manageInputOutput();
    vector<int> v = {1};
    print(v);
}




