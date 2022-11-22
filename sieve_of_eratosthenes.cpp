#include<bits/stdc++.h>
using namespace std;
void sieve_of_eratosthenes(int n){//O(nlog(log(n)))
    //for n>=1
    n++;
    vector<bool> N(n,1);
    N[0]=N[1]=0;
    for(int i=2;i*i<=n;i++){
        if(N[i]==1){//i -> prime
            for(int j=i*i;j<=n;j+=i){
                N[j]=0;
            }
        }
    }

    // printing primes
    for(int i=0;i<n;i++){
        if(N[i]==1){
            cout<<i<<" ";
        }
    }
    
}
int main(){
    int size;
    cin>>size;
    sieve_of_eratosthenes(size);

}