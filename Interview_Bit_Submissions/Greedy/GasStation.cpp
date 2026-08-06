/*
    Problem: Gas Station
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/gas-station/
    Time Complexity: O(n)
    Space Complexity: O(1)

    Problem Description

        Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].

        You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

        Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

        You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.


        Problem Constraints
        1 <= |A| <= 5 * 105
        |A| == |B|
        0 <= Ai <= 5 * 103
        0 <= Bi <= 5 * 103


        Input Format
        The first argument given is the integer array A. The second argument given is the integer array B.


        Output Format
        Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.


        Example Input
        A = [1, 2]
        B = [2, 1]


        Example Output
        1


        Example Explanation
        If you start from index 0, you can fill in A[0] = 1 amount of gas.
        Now your tank has 1 unit of gas. But you need B[0] = 2 gas to travel to station 1.

        If you start from index 1, you can fill in A[1] = 2 amount of gas.
        Now your tank has 2 units of gas. You need B[1] = 1 gas to get to station 0.
        So, you travel to station 0 and still have 1 unit of gas left over.
        You fill in A[0] = 1 unit of additional gas, making your current gas = 2. It costs you B[0] = 2 to get to station 1, which you do and complete the circuit.
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

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int sumGas = 0;
    int sumCost = 0;
    int start = 0;
    int tank = 0;
    for (int i = 0; i < A.size(); i++) {
        sumGas += A[i];
        sumCost += B[i];
        tank += A[i] - B[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    if (sumGas < sumCost) {
        return -1;
    } else {
        return start;
    }
}

int main(){
    manageInputOutput();

}