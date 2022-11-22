#include<bits/stdc++.h>
using namespace std;

int GCD(int A, int B) {//O(logphi(max(A,B))) or min
//phi=golden ratio=1.618..
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
int d,x,y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int main(){
    cout<<GCD(25,15)<<endl;
    extendedEuclid(16, 10);
cout << "The GCD of 16 and 10 is "<< d << endl;
cout << "Coefficient x and y are: "<< x <<  "and  " << y << endl;

return 0;  
}