#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

vector<int> lpsarr(string pat){
    const int n=pat.length();
    vector<int> lps(n);
    lps[0]=0;
    int i=1,len=0;
    while(i<n){
        if(pat[i]==pat[len]){
            lps[i]=len+1;
            i++;
            len++;
        }
        
        
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
void KMPsearch(string pat,string txt){
    const int m=pat.length(),
    n=txt.length();
    vector<int> lps=lpsarr(pat);
    int i=0,j=0;
    
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==m){
            cout<<i-m<<" ";
            j=lps[j-1];//to print all occurances
        }
    }
    cout<<"\n";
}
int main()
{
    IOS;
#ifndef ONLINE_JUDGE                    
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout); 
#endif
    string pat,txt;
    cin>>pat>>txt;
    KMPsearch(pat,txt);
}