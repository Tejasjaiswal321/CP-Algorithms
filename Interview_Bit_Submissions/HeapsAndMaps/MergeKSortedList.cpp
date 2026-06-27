/*
    Problem: Merge K Sorted Lists

    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/merge-k-sorted-lists/

    Time Complexity:  O(n) -  n is sum of size of all lists
    Space Complexity: O(n)

    Author: Tejas Jaiswal
    Description:
        Merge k sorted linked lists and return it as one sorted list.

        Example :

        1 -> 10 -> 20
        4 -> 11 -> 13
        3 -> 8 -> 9
        will result in

        1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
    Example Explanation
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
// void print(vector<T> arr,string name = ""){
//     cout<<"DEBUG : "<<T<<name<<": ";
//     for(auto &i:arr){
//         cout<< i <<" ";
//     }
//     cout<<endl;
// }


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
    public:
    ListNode* mergeKLists(vector<ListNode*> &A);
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    map<int,vector<ListNode*>> mp;
    for(auto node:A){

        if(node!=NULL){
            // printf("hmm\n");
            if(mp.find(node->val)==mp.end()){
                mp[node->val] = {};
            }
            mp[node->val].push_back(node);
            // printf("mp insert %d\n ",node->val);
        }
    }
    ListNode* ans = new ListNode(-1),*ansEnd = ans;
    while(!mp.empty()){

        auto nextNode = new ListNode(mp.begin()->first);
        // printf("ans insert %d\n ",nextNode->val);
        ansEnd->next = nextNode;
        ansEnd = nextNode;
        // new node inserted;

        auto nextNodeInList = mp.begin()->second.back()->next;
        mp.begin()->second.pop_back();
        if(nextNodeInList!=NULL){
            mp[nextNodeInList->val].push_back(nextNodeInList);
        }
        

        if(mp.begin()->second.empty()){
            mp.erase(mp.begin());
        }
    }
    return ans->next;
}


int main(){
    manageInputOutput();
    auto *a = new ListNode(1),*b = new ListNode(2),*c =new ListNode(3),*d= new ListNode(4);
    vector<ListNode*> v = {a,b,c,d};
    auto ans = Solution().mergeKLists(v);
    while(ans!=NULL){
        cout<<ans->val<<endl;
        ans = ans->next;
    }
}




