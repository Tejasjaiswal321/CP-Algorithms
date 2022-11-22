#include <iostream>
using namespace std;
#define ll long long
ll modpowIter(ll a, ll b, ll c) {
        ll ans=1;
        while(b != 0) {
                if(b%2 == 1)
                        ans=(ans*a)%c;

                a=(a*a)%c;
                b /= 2;
        }
        return ans;
}
ll modRecursion(ll a, ll b, ll c)
{
    if(b == 0)
    return 1;
    if(b == 1)
    return a%c;
    else if( b%2 == 0)      //if b is even
    {
        return modRecursion((a *a)%c,b/2,c);
    }
    else                      // if b is odd.
    {
        return (a*modRecursion((a*a%c),b/2,c))%c;
    }
}
int main() {
        ll a=5,b=59,c=19,ans,ans1;
        ans = modpowIter(a,b,c);
        cout << ans << endl;
}