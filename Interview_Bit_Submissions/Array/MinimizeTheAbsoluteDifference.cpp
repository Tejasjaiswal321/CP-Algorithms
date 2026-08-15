/*
    Problem: Minimize the absolute difference
    Platform: InterviewBit
    Link: https://www.interviewbit.com/problems/minimize-the-absolute-difference/?study_plan=study-plan-1-week&/
    Time Complexity: O(sizeA+sizeB+sizeC)
    Space Complexity: O(1)
    Problem Description:
    Given three sorted arrays A, B  and Cof not necessarily same sizes.

    Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.

    i.e. minimize | max(a,b,c) - min(a,b,c) |.

    Example :

    Input:

    A : [ 1, 4, 5, 8, 10 ]
    B : [ 6, 9, 15 ]
    C : [ 2, 3, 6, 6 ]
    Output:

    1
    Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
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

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i2=0,i3=0;
    int aSize = A.size(),bSize = B.size(),cSize = C.size();
    int ans = 1e8;
    for(int i1 = 0;i1<aSize;i1++){
        while(i2<bSize-1&&B[i2]<A[i1]){
            i2++;
        }
        while(i3<cSize-1&&C[i3]<A[i1]){
            i3++;
        }
        int a = A[i1];
        vector<int> b = { -(int)1e9, B[i2]} ,c = { -(int)1e9, C[i3]};
        if(i2>0){
            b[0] = B[i2-1];
        }
        if(i3>0){
            c[0] = C[i3-1];
        }
        for(int i =0;i<2;i++){
            for(int j=0;j<2;j++){
                int bNum = b[i],cNum = c[j];
                int mn = min(a,min(bNum,cNum)),mx = max(a,max(bNum,cNum));
                // printf("%d %d %d\n",mn,mx,a);
                ans = min(ans,mx-mn);
            }
        }
    }
    return ans;
}


int main(){
    manageInputOutput();

}