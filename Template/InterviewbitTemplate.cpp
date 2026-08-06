/*
    Problem:
    Platform: 
    Link: 
    Problem Description:
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


int main(){
    manageInputOutput();

}