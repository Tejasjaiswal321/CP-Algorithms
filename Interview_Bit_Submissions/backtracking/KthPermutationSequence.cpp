/*
    Problem: Kth Permutation Sequence

    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/kth-permutation-sequence/

    Time Complexity:  O(n*n)
    Space Complexity: O(n)

    Author: Tejas Jaiswal

    Problem Description:
        The set [1,2,3,…,n] contains a total of n! unique permutations.

        By listing and labeling all of the permutations in order,

        We get the following sequence (ie, for n = 3 ) :

        1. "123"
        2. "132"
        3. "213"
        4. "231"
        5. "312"
        6. "321"
        Given n and k, return the kth permutation sequence.

        For example, given n = 3, k = 4, ans = "231"

        Good questions to ask the interviewer :

        What if n is greater than 10. How should multiple digit numbers be represented in string?
            In this case, just concatenate the number to the answer.

            so if n = 11, k = 1, ans = "1234567891011"

        Whats the maximum value of n and k?
            In this case, k will be a positive integer thats less than INT_MAX.

            n is reasonable enough to make sure the answer does not bloat up a lot.
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
template<class T>
void print_vector(deque<T> arr,string name = ""){
    cout<<"print_vector : "<<name<<": ";
    for(auto &i:arr){
        cout<< i <<" ";
    }
    cout<<endl;
}

class Solution{
    public:
    string getPermutation(int A, int B);

};


vector<ll> facStore;
deque<ll> numArr;

string solve(int k){
    
    if(numArr.empty()){
        return "";
    }
    int rightCount = numArr.size()-1;
    int takeInd = 0;
    if(rightCount>0&& facStore.size()>=rightCount&&facStore[rightCount-1]<=k){
        int rCombCount =facStore[rightCount-1];
        takeInd = k/rCombCount;
        k = k%rCombCount;
    }
    // printf("k = %d takeInd = %d rightCount = %d: numArr",k,takeInd,rightCount);
    int currNum = numArr[takeInd];
    numArr.erase(numArr.begin()+takeInd);
    // print_vector(numArr);
    auto ans =  to_string(currNum) + solve(k);

    
    
    return ans;

}



string Solution::getPermutation(int A, int B) {
    facStore.clear();
    ll nextNum = 1;
    int i;
    for( i = 1;nextNum<=B;i++){
        nextNum*=i;
        facStore.push_back(nextNum);
    }
    // facStore.push_back(facStore.back()*i);
    for(int i = 1;i<=A;i++){
        numArr.push_back(i);
    }
    // print_vector(numArr);
    // print_vector(facStore);

    return solve(B-1);
}



int main(){
    manageInputOutput();
    cout<<Solution().getPermutation(3,4);

}





