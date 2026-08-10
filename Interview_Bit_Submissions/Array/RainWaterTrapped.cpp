/*
    Problem: Rain Water Trapped
    Platform: Interview Bit
    Link: https://www.interviewbit.com/problems/rain-water-trapped/?study_plan=study-plan-1-week&/
    Time Complexity: O(n)
    Space Complexity: O(n)

    Problem Description:

    Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

    Problem Constraints
    1 <= |A| <= 100000



    Input Format
    The only argument given is integer array A.



    Output Format
    Return the total water it is able to trap after raining.



    Example Input
    Input 1:

    A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    Input 2:

    A = [1, 2]


    Example Output
    Output 1:

    6
    Output 2:

    0


    Example Explanation
    Explanation 1:

    
    In this case, 6 units of rain water (blue section) are being trapped.
    Explanation 2:

    No water is trapped.
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



int Solution::trap(const vector<int> &A) {
	vector<pii> inc,dec;

	int n = A.size();

	for(int i=0;i<n;i++){

		int num = A[i];

		while(!dec.empty()&&dec.back().second<num){
			dec.pop_back();
		}
		if(!inc.empty()&&inc.back().second>num){
			dec.push_back({i,A[i]});
		}
        if(inc.empty() || inc.back().second<=num){
            inc.push_back({i,num})	;
        }

		
	}
	vector<pii> total = inc;
	for(auto &i:dec){
		total.push_back(i);
	}
    for(auto &p:total){
        // printf("%d %d\n",p.first,p.second);
        // cout<<p.first<<" "<<p.sed
    }
	int prevHeight = 0,currBar = 0,ans =0;
	for(int i =0;i<n;i++){
		int waterHere = min(prevHeight,total[currBar].second) - A[i];
		if(waterHere>0){
			ans += waterHere;
		}
		if(total[currBar].first==i){
		    prevHeight = total[currBar].second;
			currBar++;
		}
	}
	return ans;
}



int main(){
    manageInputOutput();

}