/*
    Problem: Even Reverse
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/even-reverse/

    Problem Description

    Given a linked list A , reverse the order of all nodes at even positions.

    Problem Constraints
    1 <= Size of linked list <= 100000

    Input Format
    First and only argument is the head of the Linked-List A.

    Output Format
    Return the head of the new linked list.

    Example Input
    Input 1:

    A = 1 -> 2 -> 3 -> 4
    Input 2:

    A = 1 -> 2 -> 3

    Example Output
    Output 1:

    1 -> 4 -> 3 -> 2
    Output 2:

    1 -> 2 -> 3

    Example Explanation
    Explanation 1:

    Nodes are positions 2 and 4 have been swapped.
    Explanation 2:

    No swapping neccassary here.
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
    ListNode* Solution::solve(ListNode* A) ;
};

ListNode* Solution::solve(ListNode* A) {
    vector<ListNode*> evenNodes;
    auto node = A;
    bool isOdd = true;
    while(node!=NULL){
        if(!isOdd){
            evenNodes.push_back(node);
        }
        node = node->next;
        isOdd = !isOdd;
    }
    for(int i = 0,j=evenNodes.size()-1;i<j;i++,j--){
        auto num = evenNodes[i]->val;
        evenNodes[i]->val = evenNodes[j]->val;
        evenNodes[j]->val = num;
    }
    return A;
}



int main(){
    manageInputOutput();
    vector<int> v = {1};
    print(v);
}




