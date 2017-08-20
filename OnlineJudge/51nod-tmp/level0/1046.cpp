#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll fast_mod(ll a,ll b,ll mod)
{
    ll t=a;
    ll ans=1;
    while(b)
    {
        if(b%2)
        {
            ans*=t;
            ans%=mod;
        }
        t=t*t%mod;
        b/=2;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1046.in","r",stdin);
    //freopen("1046.out","w",stdout);
#endif
    ll a,b,c;
    cin >>a>>b>>c;
    cout << fast_mod(a,b,c)<<endl;
    return 0;
}
