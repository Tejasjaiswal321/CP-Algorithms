/*
    Problem: Max Rectangle in Binary Matrix
    Platform: Interview Bit
    Link: https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    Problem Description:
    Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

    Bonus if you can solve it in O(n^2) or less.

    Example :

    A : [  1 1 1
        0 1 1
        1 0 0 
        ]

    Output : 4 

    As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
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

int Solution::maximalRectangle(vector<vector<int> > &arr) {
    if(arr.size()==0){
        return 0;
    }
    int h = arr.size();
    int l = arr[0].size();
    vector<vector<int>> rOneCount(h,vector<int>(l,0));
    for(int i =0;i<h;i++){
        int rOne = 0;
        for(int j = l-1;j>=0;j--){
            if(arr[i][j]==1){
                rOne++;
                rOneCount[i][j]=rOne;
            }else{
                rOne = 0;
            }
        }
    }
    int ans = 0;
    
    stack<pii> st;
    for(int j = 0;j<l;j++){
        for(int i = 0;i<h;i++){
            auto currROne = rOneCount[i][j];
            while(!st.empty()&& st.top().second>=currROne){
                auto top = st.top();
                st.pop();
                int start = -1;
                if(!st.empty()){
                    start = st.top().first;
                }
                ans = max(ans,top.second*(i-start-1));
                
            }
            if(st.empty()|| st.top().second!=currROne){
                st.push({i,currROne});
            }
        }
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            int start = -1;
            if(!st.empty()){
                start = st.top().first;
            }
            ans = max(ans,top.second*(h-start-1));
        }
    }
    return ans;
    
}


int main(){
    manageInputOutput();

}







